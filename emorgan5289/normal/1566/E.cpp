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

vector<vector<int>> adj;
vector<int> dp;
ll ans;

void dfs(int i, int k) {
    for (int j : adj[i]) {
        if (j == k) continue;
        dfs(j, i);
        if (dp[j] == 0) dp[i] = 1;
    }
    debug(i, dp[i]);
    if (dp[i] == 1) {
        ans--;
        for (int j : adj[i])
            if (j != k && dp[j] == 0)
                ans++;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        adj.assign(n, {});
        dp.assign(n, 0);
        ans = 0;
        for (int i = 0; i < n-1; i++) {
            int x, y; cin >> x >> y; x--, y--;
            adj[x].pb(y), adj[y].pb(x);
        }
        dfs(0, 0);
        ans++;
        cout << ans << "\n";
    }
}