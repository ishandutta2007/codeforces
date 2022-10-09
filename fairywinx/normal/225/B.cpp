#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

signed main() {
    #ifdef DEBUG
        freopen( "main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n, k;
    cin >> n >> k;
    if (k > 40) {
        vector<int> ans = {0};
        for (int i = 30; i >= 0; --i) {
            if ((1 << i) & n) {
                ans.push_back((1 << i));
            }
        }
        cout << ans.size() << '\n';
        for (int i : ans) {
            cout << i << ' ';
        }
        cout << '\n';
        return 0;
    } else {
        vector<long long> dp = {1};
        for (int i = 1; dp.back() < n; ++i) {
            long long ans = 0;
            for (int j = i - 1; i - j <= k && j >= 0; --j) {
                ans += dp[j];
            }
            dp.push_back(ans);
        }
        vector<int> ans = {0};
        for (int i = (int) dp.size() - 1; i >= 0; --i) {
            if (dp[i] <= n) {
                n -= dp[i];
                ans.push_back(dp[i]);
            }
        }
        cout << ans.size() << '\n';
        for (int i : ans) {
            cout << i << ' ';
        }
        cout << '\n';
        return 0;
    }
}