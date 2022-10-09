#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

const int inf = 1e9 + 228;

int solve(int mask, int it, int m, vector<int> &a, vector<int> &dp, vector<pair<char, int>> &sob) {
    if (it == m) {
        return 0;
    }
    if (dp[mask] != inf) {
        return dp[mask];   
    }
    if (sob[it].second == 1) {
        dp[mask] = -inf;
        for (int i = 0; i < m; ++i) {
            if ((1 << i) & mask) {
                continue;
            } else {
                if (sob[it].first == 'b') {
                    dp[mask] = max(dp[mask], solve(mask + (1 << i), it + 1, m, a, dp, sob));
                } else {
                    dp[mask] = max(dp[mask], solve(mask + (1 << i), it + 1, m, a, dp, sob) + a[i]);
                }
            }
        }
    } else {
        dp[mask] = inf;
        for (int i = 0; i < m; ++i) {
            if ((1 << i) & mask) {
                continue;
            } else {
                if (sob[it].first == 'b') {
                    dp[mask] = min(dp[mask], solve(mask + (1 << i), it + 1, m, a, dp, sob));
                } else {
                    dp[mask] = min(dp[mask], solve(mask + (1 << i), it + 1, m, a, dp, sob) - a[i]);
                }
            }
        }
    }
    return dp[mask];
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(rall(a));
    cin >> m;
    a.resize(m);
    vector<int> dp((1 << m) - 1, inf);
    vector<pair<char, int>> sob(m);
    for (int i = 0; i < m; ++i) {
        char c;
        cin >> c;
        int team;
        cin >> team;
        sob[i] = {c, team};
    }
    cout << solve(0, 0, m, a, dp, sob) << '\n';
}