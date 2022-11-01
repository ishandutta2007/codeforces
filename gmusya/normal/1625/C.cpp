#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> x(n + 1), s(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    x[n] = l;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int last = 0; last < i; ++last) {
            int tmp = i - last - 1;
            for (int j = 0; j <= k; ++j) {
                int res = dp[last][j] + (x[i] - x[last]) * s[last];
                if (j + tmp <= k && dp[i][j + tmp] >= res) {
                    dp[i][j + tmp] = res;
                }
            }
        }
    }
    cout << *min_element(dp[n].begin(), dp[n].end());
    return 0;
}