#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <array>
#include <map>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> dp(n, vector<int> (k, n));
    int st = -1;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') {
            st = i;
            break;
        }
    }
    dp[st][0] = 1;
    for (int i = st + 1; i < n; ++i) {
        if (s[i] == '*') {
            for (int j = 0; j < k; ++j)
                dp[i][0] = min(dp[i][0], dp[i - 1][j] + 1);
        }
        for (int j = 0; j < k - 1; ++j)
            dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j]);
    }
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '*') {
            cout << dp[i][0] << '\n';
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    SOLVE
}