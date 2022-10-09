#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const int mod = 1e9 + 7;

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n;
    cin >> n;
    vector<int> c(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        sum += c[i];
    }
    vector<int> b(n - 1);
    vector<int> pref(n);
    vector<int> prefb(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
        pref[i + 1] = pref[i] + b[i];
        prefb[i + 1] = prefb[i] + pref[i + 1];
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        vector<vector<int>> dp(n + 1, vector<int> (sum + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int s = 0; s <= sum; ++s) {
                for (int j = 0; j <= c[i - 1] && s + j <= sum; ++j) {
                    if (x * i + prefb[i - 1] <= s + j) {
                        dp[i][s + j] += dp[i - 1][s];
                        if (dp[i][s + j] >= mod)
                            dp[i][s + j] -= mod;
                    }
                }
            }
        }
        int ans = 0;
        for (int i : dp.back()) {
            ans += i;
            if (ans >= mod)
                ans -= mod;
        }
        cout << ans << ' ';
    }
    cout << '\n';
}