#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[105];
    int n;
    cin >> n;
    for(int i = 0; i< n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for(int i = 0; i < n; i++) {
        if(i) printf(" ");
        printf("%d", arr[i]);
    }
    return 0;
}