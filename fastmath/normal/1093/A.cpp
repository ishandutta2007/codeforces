#include <bits/stdc++.h>

using namespace std;

const int MAXN = 207;

void solve() {
    int x;
    cin >> x;
    bitset <MAXN> dp;
    dp[0] = 1;
    for (int ans = 1; ; ++ans) {
        auto tmp = dp;
        for (int i = 2; i <= 7; ++i) {
            dp |= tmp << i;
        }   
        if (dp[x]) {
            cout << ans << '\n';
            return;
        }   
    }   
}   

signed main() {
    #ifdef HOME
        //freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        solve();
    }   

    return 0;
}