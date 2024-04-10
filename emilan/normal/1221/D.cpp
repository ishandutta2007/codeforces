#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll inf = 1e18;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

        vector<array<ll, 3>> dp(n + 1, {inf, inf, inf});
        dp[0] = {0, 0, 0};
        for (int i = 0; i < n; i++) {
            for (int u = 0; u < 3; u++) {
                for (int v = 0; v < 3; v++) {
                    if (i && a[i - 1] + u == a[i] + v) continue;

                    dp[i + 1][v] = min(dp[i][u] + b[i] * v, dp[i + 1][v]);
                }
            }
        }

        cout << *min_element(dp[n].begin(), dp[n].end()) << '\n';
    }
}