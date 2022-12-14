#include <bits/stdc++.h>

using namespace std;

const int kN = 500;
const int kInf = 1e9;

// dp[#][last_alive][ammo] = time
int dp[2][kN][kN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l, k;
    cin >> n >> l >> k;
    vector<int> pos(n);
    for (int &x : pos) cin >> x;
    vector<int> lag(n);
    for (int &x : lag) cin >> x;

    fill_n(**dp, sizeof dp / sizeof ***dp, kInf);
    dp[0][0][k] = 0;
    for (int i = 1; i < n; i++) {
        fill_n(*dp[i & 1], sizeof *dp / sizeof ***dp, kInf);
        for (int u = 0; u < i; u++) {
            for (int s = 0; s <= k; s++) {
                dp[i & 1][i][s] = min(dp[i & 1][i][s],
                        dp[~i & 1][u][s] + lag[u] * (pos[i] - pos[u]));
                if (s > 0) {
                    dp[i & 1][u][s - 1] = min(dp[i & 1][u][s - 1],
                            dp[~i & 1][u][s]);
                }
            }
        }
    }

    int ans = kInf;
    for (int u = 0; u < n; u++) {
        for (int s = 0; s <= k; s++) {
            ans = min(ans, dp[~n & 1][u][s] + lag[u] * (l - pos[u]));
        }
    }
    cout << ans << '\n';
}