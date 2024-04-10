#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> dp(8192, INF);
        dp[a[0]] = 0;
        for (int i = 1; i < n; ++i) {
            vector<int> new_dp(8192, INF);
            for (int j = 0; j <= 8191; ++j) {
                new_dp[a[i]] = min(new_dp[a[i]], dp[j] + (j != 0));
                new_dp[a[i] ^ j] = min(new_dp[a[i] ^ j], dp[j] + (j != 0));
            }
            swap(dp, new_dp);
        }
        int ans = dp[0];
        for (int j = 1; j <= 8191; ++j) {
            ans = min(ans, dp[j] + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}