#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
#define int long long
 
using namespace std;

const int mod = 998244353;

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
    vector<array<int, 3>> a(n);
    vector<int> pos(n + 1);
    vector<long long> dp(n + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
        pos[i + 1] = a[i][0];
    }
    for (int i = 1; i <= n; ++i) {
        int to = lower_bound(all(pos), a[i - 1][1]) - pos.begin();
        int dist = pos[to] - a[i - 1][1];
        if (to == i) {
            dp[i] = (dp[i - 1] + pos[i] - pos[i - 1] + dist) % mod;
        } else {
            dp[i] = (dp[i - 1] + 2ll * (pos[i] - pos[i - 1]) + dist + (dp[i - 1] - dp[to - 1] - (pos[to] - pos[to - 1]))) % mod;
            dp[i] = (dp[i] + mod) % mod; 
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += pos[i] - pos[i - 1];
        ans %= mod;
        if (a[i - 1][2] == 1) {
            int to = lower_bound(all(pos), a[i - 1][1]) - pos.begin();
            int dist = pos[to] - a[i - 1][1];
            if (to == i) {
                ans += dist;
            } else {
                ans += dist + pos[i] - pos[i - 1] + dp[i - 1] - dp[to - 1] - (pos[to] - pos[to - 1]);
                ans %= mod;
                ans = (ans + mod) % mod;
            }
        }
    }
    cout << (ans + 1) % mod << '\n';
}