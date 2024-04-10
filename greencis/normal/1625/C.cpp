#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, k;
    cin >> n >> l >> k;
    vector<int> v(n + 1);
    vector<int> a(n + 1);
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < n; ++i) cin >> a[i];
    v[n] = l;
    a[n] = 0;

    constexpr int INF = 1.05e9;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (dp[i][j] == INF) continue;
            for (int skip = 0; j + skip <= k && i + skip + 1 <= n; ++skip) {
                int to = i + skip + 1;
                int& rf = dp[to][j + skip];
                rf = min(rf, dp[i][j] + a[i] * (v[to] - v[i]));
            }
        }
    }
    int ans = *min_element(all(dp[n]));
    cout << ans << '\n';
}