#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <assert.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<vector<long long>> dp(n + 1, vector<long long> (n + 1, -1));
    dp[0][0] = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dp[i][j] < 0)
                continue;
            if (dp[i][j] + a[i] >= 0) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[i]);
            }
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }
    for (int i = 0; i <= n; ++i) {
        if (dp.back()[i] >= 0)
            ans = max(ans, i);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // SOLVE
    solve();
}