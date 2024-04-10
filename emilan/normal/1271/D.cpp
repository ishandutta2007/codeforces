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

const int maxn = 5e3 + 2;
const int inf = (1 << 30) - 1;
int dp[maxn][maxn], a[maxn], b[maxn], c[maxn], maxPos[maxn];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    iota(maxPos, maxPos + n, 0);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        maxPos[v] = max(maxPos[v], u);
    }

    vt<vt<int>> defend(n);
    for (int i = 0; i < n; i++) {
        defend[maxPos[i]].push_back(c[i]);
    }
    for (int i = 0; i < n; i++) sort(rall(defend[i]));

    fill_n(dp[0], maxn * maxn, -inf);
    dp[0][k] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j < maxn; j++) {
            if (dp[i][j] == -inf) continue;

            int &x = dp[i + 1][j + b[i]];
            x = max(x, dp[i][j]);

            int acc = 0;
            for (int k = 0, idx = j + b[i] - 1;
                    k < sz(defend[i]) && idx >= 0;
                    k++, idx--) {
                acc += defend[i][k];
                int &y = dp[i + 1][idx];
                y = max(y, dp[i + 1][j + b[i]] + acc);
            }
        }
    }

    int ans = -inf;
    for (int i = 0; i < maxn; i++) {
        ans = max(ans, dp[n][i]);
    }

    if (ans == -inf) cout << -1;
    else cout << ans;
}