#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1 << 20;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        sort(a.begin(), a.end());

        vector<vector<int>> dp(2 * n + 2, vector<int>(n + 1, INF));
        dp[1][0] = 0;
        for (int i = 1; i <= 2 * n; i++) {
            for (int j = 0; j <= n; j++) {
                if (j < n) {
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(i - a[j]));
                }

                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            }
        }

        cout << dp.back().back() << '\n';
    }
}