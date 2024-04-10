#include <bits/stdc++.h>
using namespace std;

int cnt[45][45];
int dp[45][45][45][45];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            cnt[i + 1][j + 1] = (s[j] - '0') + cnt[i + 1][j] + cnt[i][j + 1] - cnt[i][j];
        }
    }
    for (int h = 1; h <= n; ++h) {
        for (int w = 1; w <= m; ++w) {
            for (int a = 1, c; (c = a + h - 1) <= n; ++a) {
                for (int b = 1, d; (d = b + w - 1) <= m; ++b) {
                    int cur = cnt[c][d] - cnt[a - 1][d] - cnt[c][b - 1] + cnt[a - 1][b - 1];
                    dp[a][b][c][d] = dp[a][b + 1][c][d] + dp[a][b][c][d - 1] - dp[a][b + 1][c][d - 1] + !cur;
                }
            }
        }
    }
    for (int h = 1; h <= n; ++h) {
        for (int w = 1; w <= m; ++w) {
            for (int a = 1, c; (c = a + h - 1) <= n; ++a) {
                for (int b = 1, d; (d = b + w - 1) <= m; ++b) {
                    dp[a][b][c][d] += dp[a + 1][b][c][d] + dp[a][b][c - 1][d] - dp[a + 1][b][c - 1][d];
                }
            }
        }
    }
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << dp[a][b][c][d] << '\n';
    }
}