#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL inf = 1E15;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<LL> a(n + 1), sum(n + 1);
        int k = 0;
        while (k * (k + 1) / 2 <= n) k ++;
        vector dp(n + 2, vector(k, 0LL));
        for (int i = 1; i <= n; i += 1) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        for (int i = n; i >= 1; i -= 1) {
            for (int j = 1; j < k; j += 1) dp[i][j] = dp[i + 1][j];
            dp[i][1] = max(dp[i][1], a[i]);
            for (int j = 2; j < k; j += 1) if (i + j <= n)
                if (sum[i + j - 1] - sum[i - 1] < dp[i + j][j - 1])
                    dp[i][j] = max(dp[i][j], sum[i + j - 1] - sum[i - 1]);
            //for (int j = 1; j < k; j += 1) cout << dp[i][j] << " "; cout << "\n";
        }
        for (int j = k - 1; j >= 1; j -= 1)
            if (dp[1][j]) {
                cout << j << "\n";
                break;
            }
    }
    return 0;
}