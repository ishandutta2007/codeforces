#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 500 + 1;
int tr[maxn][2];
int dp[maxn][maxn][maxn];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    string a, b;
    cin >> n >> m >> a >> b;
    for (int i = 0; i < m; i += 1) {
        for (int j = 0; j < 2; j += 1) {
            auto c = b.substr(0, i) + (char)('0' + j);
            for (int k = min(m, (int)c.size()); k; k -= 1)
                if (c.substr((int)c.size() - k) == b.substr(0, k)) {
                    tr[i][j] = k;
                    break;
                }
        }
    }
    int L = 0;
    for (int i = 1; i < m; i += 1) if (b.substr(0, i) == b.substr(m - i)) L = i;
    for (int i = 0; i <= n; i += 1)
        for (int j = 0; j < m; j += 1)
            for (int k = 0; k <= n - m + 1; k += 1)
                dp[i][j][k] = n + 1;
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i += 1)
        for (int j = 0; j < m; j += 1)
            for (int k = 0; k <= n - m + 1; k += 1)
                for (int d = 0; d < 2; d += 1) {
                    int ni = i + 1, nj = 0, nk = k, c = d != a[i] - '0';
                    if (tr[j][d] != m)
                        nj = tr[j][d];
                    else {
                        nj = L;
                        nk += 1;
                    }
                    if (nk <= n - m + 1) dp[ni][nj][nk] = min(dp[ni][nj][nk], dp[i][j][k] + c);
                }
    for (int k = 0; k <= n - m + 1; k += 1) {
        int ans = n + 1;
        for (int j = 0; j < m; j += 1) ans = min(ans, dp[n][j][k]);
        if (ans == n + 1) cout << "-1 ";
        else cout << ans << " ";
    }
    return 0;
}