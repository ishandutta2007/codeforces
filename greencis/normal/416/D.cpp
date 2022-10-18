//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<pii> v;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > 0)
            v.emplace_back(a[i], i);
    }
    int m = v.size();
    if (m == 0) {
        cout << "1\n";
        return 0;
    }
    vector<vector<pii>> dp(m, vector<pii>(2, {1e9, -1e9}));
    dp[0][0] = {1, n};
    for (int i = 1; i < m; ++i) {
        int cur = 1e9;
        int maxRight = -1e9;
        if ((v[i].first - v[i - 1].first) % (v[i].second - v[i - 1].second) == 0) {
            int d = (v[i].first - v[i - 1].first) / (v[i].second - v[i - 1].second);
            int maxLeft = (d <= 0 ? -1 : v[i - 1].second - (v[i - 1].first - 1) / d);
            maxRight = (d >= 0 ? n : v[i].second + (v[i].first - 1) / -d);
            if (i == 1) {
                if (maxLeft <= 0)
                    cur = min(cur, 1);
            } else {
                cur = min(cur, dp[i - 2][0].first + 1);
                if (maxLeft <= dp[i - 2][1].second + 1)
                    cur = min(cur, dp[i - 2][1].first + 1);
                ll prv = v[i - 1].first + d * ll(v[i - 2].second - v[i - 1].second);
                if (prv == v[i - 2].first)
                    cur = min(cur, dp[i - 1][1].first);
            }
        }
        dp[i][1] = {cur, maxRight};

        cur = min(dp[i - 1][1].first + 1, dp[i - 1][0].first + (v[i - 1].first != v[i].first));
        dp[i][0] = {cur, n};

        //cerr << dp[i][0].first << ' ' << dp[i][1].first << '\n';
    }
    int ans = dp[m - 1][0].first;
    if (dp[m - 1][1].second >= n - 1) {
        ans = min(ans, dp[m - 1][1].first);
    }
    cout << ans << '\n';
}