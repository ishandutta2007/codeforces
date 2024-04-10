#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int dp[1005][1005];

int main() {
    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, k;
        cin >> n >> k;
        fill_n(dp[1], n + 1, 1);
        constexpr int mod = 1'000'000'007;
        for (int life = 2; life <= k; ++life) {
            dp[life][0] = 1;
            for (int planes = 1; planes <= n; ++planes) {
                int& rf = dp[life][planes];
                rf = dp[life][planes - 1] + dp[life - 1][n - planes];
                if (rf >= mod)
                    rf -= mod;
            }
        }
        int ans = dp[k][n];
        cout << ans << '\n';
    }
}