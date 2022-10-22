#include <bits/stdc++.h>
using namespace std;
#define int long long
const int LG = 27;
int get(int n) {
    int ans = 1;
    for (int d = 2; d * d <= n; ++d) {
        if (n % d == 0) {
            ans = max(ans, d);
            ans = max(ans, n / d);
        }   
    }   
    return ans;
}   
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else 
        ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int mx = 0;
        for (int i = 0; i < LG; ++i) {
            if ((1 << i) <= x) mx += 1 << i;
        }   
        if (x == mx) {
            cout << get(x) << '\n';
        }
        else {
            cout << mx << '\n';
        }   
    }   
}