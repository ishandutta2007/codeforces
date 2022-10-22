#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], b[N];
int ra[N], rb[N];
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else 
        ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    if (a[0] != b[0] || a[n - 1] != b[n - 1]) {
        cout << "No\n";
        exit(0);
    }   
    for (int i = 0; i + 1 < n; ++i) {
        ra[i] = a[i + 1] - a[i];
    }
    for (int i = 0; i + 1 < n; ++i) {
        rb[i] = b[i + 1] - b[i];
    }   
    sort(ra, ra + n); sort(rb, rb + n);
    for (int i = 0; i < n - 1; ++i) {
        if (ra[i] != rb[i]) {
            cout << "No\n";
            exit(0);
        }   
    }   
    cout << "Yes\n";
}