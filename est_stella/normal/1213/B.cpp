#include<bits/stdc++.h>
using namespace std;

int arr[200010];

int solve() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    int mn = 100000000;
    for(int i=n-1; i>=0; i--) {
        if(arr[i] > mn) ans++;
        else mn = arr[i];
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}