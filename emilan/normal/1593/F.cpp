#include <bits/stdc++.h>

using namespace std;

const int N = 64;
// dp[pos][black_cnt][red_rem][black_rem] = prev
int dp[N][N][N][N];

void solve() {
    memset(dp, -1, sizeof dp);

    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;

    dp[0][0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        int x = s[i] - '0';
        for (int j = 0; j < n; j++) {
            for (int r_a = 0; r_a < a; r_a++) {
                for (int r_b = 0; r_b < b; r_b++) if (
                        dp[i][j][r_a][r_b] != -1) {
                    // red
                    {
                        int r = (10 * r_a + x) % a;
                        dp[i + 1][j][r][r_b] = j << 12 | r_a << 6 | r_b;
                    }

                    // black
                    {
                        int r = (10 * r_b + x) % b;
                        dp[i + 1][j + 1][r_a][r] = j << 12 | r_a << 6 | r_b;
                    }
                }
            }
        }
    }

    int best = n;
    string ans("-1");
    for (int j0 = 1; j0 < n; j0++) if (dp[n][j0][0][0] != -1) {
        if (abs(n - 2 * j0) >= best) continue;

        int j = j0, r_a = 0, r_b = 0;
        ans.clear();
        for (int i = n; i > 0; i--) {
            int pj = dp[i][j][r_a][r_b] >> 12;
            int pr_a = dp[i][j][r_a][r_b] >> 6 & 63;
            int pr_b = dp[i][j][r_a][r_b] & 63;
            if (pj != j) ans += "B";
            else ans += "R";

            j = pj;
            r_a = pr_a;
            r_b = pr_b;
        }
        reverse(ans.begin(), ans.end());

        best = abs(n - 2 * j0);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}