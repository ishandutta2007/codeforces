//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using pii = pair<int, int>;

constexpr int mod = 1'000'000'007;
inline void add(int& x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
}
inline int mul(int x, int y) {
    return x * (ll)y % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> deg(n + 1);
    deg[0] = 1;
    for (int i = 1; i <= n; ++i)
        deg[i] = mul(deg[i - 1], 26);

    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    vector<vector<int>> dpLeft(n + 1, vector<int>(k + 1));
    dp[n][0] = dpLeft[n - 1][0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= k; ++j) {
            int newStrings = n - i;
            if (j - newStrings >= 0) {
                int ii = i, jj = j;
                int addon = mul(dp[i + 1][j - newStrings], 'z' - s[i]);
                while (ii >= 0 && jj <= k) {
                    add(dp[ii][jj], addon);
                    --ii;
                    jj += newStrings;
                }
            }
            add(dpLeft[i][j], mul(s[i] - 'a', dp[i + 1][j]));
            add(dp[i][j], dpLeft[i][j]);
            if (i > 0)
                add(dpLeft[i - 1][j], dpLeft[i][j]);
            //cerr << "(" << i << ", " << j << "): " << dp[i][j] << '\n';
        }
    }
    cout << dp[0][k] << '\n';
}