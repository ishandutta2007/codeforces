#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr int maxn = 2000;
    vector dp(maxn + 1, vector<LL>(maxn + 1));
    for (int i = 0; i <= maxn; i += 1) {
        dp[i][0] = i;
        for (int j = 1; j <= i; j += 1)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) * (mod + 1) / 2 % mod;
    }
    int t;
    for (cin >> t; t; t -= 1){
        int n, m, k;
        cin >> n >> m >> k;
        cout << (dp[n][n - m] * k % mod) << "\n";
    }
}