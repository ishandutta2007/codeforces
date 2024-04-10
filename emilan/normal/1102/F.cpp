#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

const int maxn = 16, inf = 1 << 30;

int dp[1 << maxn][maxn][maxn],
    cost[maxn][maxn],
    trav[maxn][maxn];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;
    vt<vt<int>> a(n, vt<int>(m));
    for (auto &i : a) for (int &j : i) cin >> j;

    if (n == 1) {
        int ans = inf;
        for (int i = 1; i < m; i++) {
            ans = min(ans, abs(a[0][i - 1] - a[0][i]));
        }

        return cout << ans, 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            cost[i][j] = inf;
            for (int k = 0; k < m; k++) {
                cost[i][j] =
                    min(cost[i][j], abs(a[i][k] - a[j][k]));
            }

            trav[i][j] = inf;
            for (int k = 1; k < m; k++) {
                trav[i][j] =
                    min(trav[i][j], abs(a[i][k - 1] - a[j][k]));
            }
        }
    }

    for (int i = 1; i < 1 << n; i++) {
        for (int u = 0; u < n; u++) {
            if (~i >> u & 1) continue;

            for (int v = 0; v < n; v++) {
                if (i >> v & 1) continue;

                for (int k = 0; k < n; k++) {
                    if (~i >> k & 1 || (k == u &&
                            __builtin_popcount(i) != 1)) continue;

                    int res = cost[k][v];
                    if (k != u) res = min(res, dp[i][u][k]);
                    dp[i | 1 << v][u][v] =
                        max(dp[i | 1 << v][u][v], res);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(
                ans,
                min(
                    trav[j][i],
                    dp[(1 << n) - 1][i][j]
                )
            );
        }
    }
    cout << ans;
}