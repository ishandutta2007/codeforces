#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;

int dp[5005][5005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = max(0, -i - j);
            } else {
                dp[i][j] = max(0, max(dp[i - 1][j] - 1, dp[i][j - 1] - 1));
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 2);
                }
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}