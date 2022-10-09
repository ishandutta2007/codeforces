#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    long long mod1 = 1, mod2 = 0;
    vector<long long> dp(n + 1);
    dp[1] = 1;
    vector<vector<int>> d(n + 1);
    for (int i = 2; i <= n; ++i) {
        for (int j = i; j <= n; j += i)
            d[j].push_back(i);
    }

    for (int i = 2; i <= n; ++i) {
        for (auto j : d[i]) {
            mod2 -= dp[i / j - 1];
            mod2 += dp[i / j];
            mod2 = (mod2 + m) % m;
        }
        dp[i] = (mod1 + mod2) % m;
        mod1 = (mod1 + dp[i]) % m;
    }
    cout << dp.back() << '\n';
}