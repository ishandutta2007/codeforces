#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<vector<ll>> dp(n+1, vector<ll>(n+1, -inf_ll));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        int ans = inf;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]);
                if (a[i-1] == j) cmax(dp[i][j], dp[i-1][j-1]+1);
                if (dp[i][j] >= k) cmin(ans, i-j);
                debug(i, j, dp[i][j]);
            }
        cout << (ans == inf ? -1 : ans) << "\n";
    }
}