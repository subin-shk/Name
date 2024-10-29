/* Binary search repeatedly divides a sorted array to find a target efficiently.
 left and right track the search bounds, and mid is the midpoint. If arr[mid] equals the 
 target, the search ends. If arr[mid] is less, the search narrows to the right half, 
 otherwise to the left. The function returns the target’s index if found, else -1. */

#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int left = 0, right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // Avoid overflow

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Not found
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38};
    int target = 16;
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, size, target);

    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";
    return 0;
}
