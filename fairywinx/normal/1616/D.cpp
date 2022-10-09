#include <bits/stdc++.h>

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
    int x;
    cin >> x;
    for (int i = 0; i < n; ++i)
        a[i] -= x;
    const int inf = 1e9 + 228;
    vector<int> lst(n, -2);
    int it = -1;
    for (int i = 0; i < n; ++i) {
        lst[i] = it;
        if (a[i] < 0)
            it = i;
    }
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }
    vector<pair<int, int>> dp(n + 1, {-inf, -inf});
    dp[0] = {0, -inf};
    int res = -inf;
    for (int i = 0; i < n; ++i) {
        dp[i + 1].first = max(dp[i].first, dp[i].second);
        if (lst[i] == -1) {
            if (i > 0 && a[i - 1] + a[i] >= 0) {
                dp[i + 1].second = dp[i].second + 1;
            }
            dp[i + 1].second = max(dp[i + 1].second, dp[i].first + 1);
        } else {
            // cout << i << ' ' << lst[i] << ' ' << pref[i + 1] - pref[lst[i]] << '\n';
            if (a[i] + a[i - 1] < 0) {
                dp[i + 1].second = dp[i].first + 1;
            } else if (pref[i + 1] - pref[lst[i]] < 0 || a[lst[i]] + a[lst[i] + 1] < 0) {
                dp[i + 1].second = dp[lst[i] + 1].first + i - lst[i];
            } else {
                dp[i + 1].second = max(dp[lst[i] + 1].first + i - lst[i], dp[lst[i] + 1].second + i - lst[i]);
            }
        }
    }
    for (auto i : dp) {
        res = max({res, i.first, i.second});
    }
    cout << res << '\n';
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