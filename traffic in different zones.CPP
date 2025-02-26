#include <iostream>

using namespace std;

// Function to find the busiest zone
int findBusiestZone(int** trafficCounts, int zones, int intervals) {
    int busiestZone = 0;
    int maxCount = 0;
    
    for (int i = 0; i < zones; i++) {
        int totalCount = 0;
        for (int j = 0; j < intervals; j++) {
            totalCount += *(*(trafficCounts + i) + j);
        }
        if (totalCount > maxCount) {
            maxCount = totalCount;
            busiestZone = i;
        }
    }
    return busiestZone;
}

int main() {
    int zones, intervals;
    cout << "Enter number of zones: ";
    cin >> zones;
    cout << "Enter number of time intervals: ";
    cin >> intervals;

    // Dynamically allocate memory for the 2D array
    int** trafficCounts = new int*[zones];
    for (int i = 0; i < zones; i++) {
        trafficCounts[i] = new int[intervals];
    }

    // Input the vehicle counts
    for (int i = 0; i < zones; i++) {
        cout << "Enter vehicle counts for zone " << i + 1 << ":" << endl;
        for (int j = 0; j < intervals; j++) {
            cout << "Interval " << j + 1 << ": ";
            cin >> *(*(trafficCounts + i) + j);
        }
    }

    // Find and output the busiest zone
    int busiestZone = findBusiestZone(trafficCounts, zones, intervals);
    cout << "The busiest zone is zone " << busiestZone + 1 << "." << endl;

    // Deallocate memory
    for (int i = 0; i < zones; i++) {
        delete[] trafficCounts[i];
    }
    delete[] trafficCounts;

    return 0;
}
