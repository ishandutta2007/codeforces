#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    LL n, x;
    cin >> n >> x;
    vector dp(n + 1, vector<LL>(x + 1)), power(x + 1, vector<LL>(n + 1)), c(n + 1, vector<LL>(n + 1));
    for (int i = 0; i <= x; i += 1)
        for (int j = 0; j <= n; j += 1)
            power[i][j] = j ? power[i][j - 1] * i % mod : 1;
    for (int i = 0; i <= n; i += 1)
        for (int j = 0; j <= i; j += 1)
            c[i][j] = j ? (c[i - 1][j - 1] + c[i - 1][j]) % mod : 1;
    for (int i = 1; i <= x; i += 1) dp[1][i] = i;
    for (int i = 2; i <= n; i += 1)
        for (int j = 1; j <= x; j += 1) if (i <= j) {
            for (int k = 0; k < i; k += 1) {
                dp[i][j] = (dp[i][j] + power[i - 1][k] * dp[i - k][j - i + 1] % mod * c[i][k]) % mod;
            }
            //cout << i << " " << j << " " << dp[i][j] << "\n";
        }
    cout << (power[x][n] + mod - dp.back().back()) % mod;
    return 0;
}