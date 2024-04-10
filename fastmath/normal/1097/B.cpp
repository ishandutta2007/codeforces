#include <bits/stdc++.h>
using namespace std;
signed main() {
    #ifdef HOME
        //freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int M = 360;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) sum += a[i];
            else sum -= a[i];
        }   
        if ((sum % M + M) % M == 0) {
            cout << "Yes\n";
            exit(0);
        }   
    }   
    cout << "No\n";
}