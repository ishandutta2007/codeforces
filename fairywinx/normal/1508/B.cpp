#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <array>
#include <map>
#include <queue>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const long long INF = 2e18 + 228;

vector<int> ans;

bool solve(int i, int n, long long k, vector<long long> &dp) {
    // cout << '!' << i << ' ' << n << ' ' << k << '\n';
    for (int j = 1; j <= n - i + 1; ++j) {
        // cout << k << ' ' << dp[n - i - j + 1] << '\n';
        if (dp[n - i - j + 1] < k) {
            k -= dp[n - i - j + 1];
        } else {
            // cout << '^' << j << ' ' << i << '\n';
            for (int p = i + j - 2; p >= i - 1; --p)
                ans[p] = i + (i + j - 2 - p);
            if (i + j - 1 == n)
                return true;
            return solve(i + j , n, k, dp);
        }
    }
    return false;
}

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> dp(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        dp[i] = 2 * dp[i - 1];
        dp[i] = min(dp[i], INF);
    }
    ans.resize(n);
    if (solve(1, n, k, dp)) {
        for (int i : ans)
            cout << i << ' ';
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    SOLVE
    // solve();
}