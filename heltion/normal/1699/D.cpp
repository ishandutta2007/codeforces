#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int _ : ranges::iota_view(0, t)) {
        int n, ans = 0;
        cin >> n;
        vector<int> a(n + 1);
        for (int i : ranges::iota_view(1, n + 1))
            cin >> a[i];
        vector check(n + 1, vector<int>(n + 1));
        for (int i : ranges::iota_view(1, n + 1)) {
            vector<int> c(n + 1);
            int mx = 0;
            for (int j : ranges::iota_view(i, n + 1)) {
                mx = max(mx, c[a[j]] += 1);
                if (mx * 2 <= j - i + 1 and (j - i) % 2) check[i][j] = 1;
            }
        }
        vector<int> dp(n + 1, -n);
        dp[0] = 0;
        for (int i = 1; i <= n; i += 1) {
            if (i == 1 or check[1][i - 1]) dp[i] = 1;
            for (int j = 1; j < i; j += 1)
                if (a[j] == a[i] and (j + 1 == i or check[j + 1][i - 1]))
                    dp[i] = max(dp[i], dp[j] + 1);
            if (i == n or check[i + 1][n]) ans = max(ans, dp[i]);
        }
        cout << ans << "\n";
    }
}