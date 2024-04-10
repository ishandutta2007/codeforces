#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

long long solve(vector<int> a) {
    int n = a.size();
    reverse(all(a));
    vector<vector<int>> dp(n + 1, vector<int> (n + 1));
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> val(n + 1);
        int res = 0;
        for (int j = i; j >= 0; --j) {
            if (a[j] <= n) {
                ++val[a[j]];
                while (val[res])
                    ++res;
            }
            for (int k = 0; k < n; ++k) {
                dp[i + 1][k + 1] = max(dp[j][k] + res + 1, dp[i + 1][k + 1]);
            }
        }
        ans += *max_element(all(dp[i + 1]));
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        a.push_back(c);
        ans += solve(a);
    }
    cout << ans << '\n';
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE
}