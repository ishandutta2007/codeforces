#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

signed main() {
    #ifdef DEBUG
        freopen( "main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<array<int, 2>> cnt(m, {0, 0});
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            if (c == '#') {
                ++cnt[j][1];
            } else {
                ++cnt[j][0];
            }
        }
    }
    const int inf = 1e9 + 228;
    vector<vector<array<int, 2>>> dp(m + 1, vector<array<int, 2>> (m + 1, {inf, inf}));
    dp[0][0][0] = 0, dp[0][0][1] = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= i && j <= y; ++j) {
            for (int t = 0; t < 2; ++t) {
                if (j + 1 <= y)
                    dp[i + 1][j + 1][t] = min(dp[i + 1][j + 1][t], dp[i][j][t] + n - cnt[i][t]);
                if (x <= j && j <= y)
                    dp[i + 1][1][1 - t] = min(dp[i + 1][1][1 - t], dp[i][j][t] + cnt[i][t]);
            }
        }
    }
    int ans = inf;
    for (int i = x; i <= min(y, m); ++i) {
        ans = min({ans, dp[m][i][0], dp[m][i][1]});
    }
    cout << ans << '\n';
}