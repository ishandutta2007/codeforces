#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

vector<vector<int>> adj;
vector<int> w, dp;
int n, k, r;

void dfs1(int i, int p) {
    w[i] = dp[i] = 0;
    for (auto& j : adj[i]) {
        if (j == p) continue;
        dfs1(j, i);
        if (w[j] == adj[j].size()-1 && w[j]%k == 0)
            w[i]++;
        dp[i] += dp[j];
    }
    dp[i] += w[i]/k;
}

void shift(int i, int j) {
    if (w[j] == adj[j].size()-1 && w[j]%k == 0) {
        if (w[i]%k == 0) dp[i]--;
        w[i]--;
    }
    dp[i] -= dp[j];
    if (w[i] == adj[i].size()-1 && w[i]%k == 0) {
        w[j]++;
        if (w[j]%k == 0) dp[j]++;
    }
    dp[j] += dp[i];
}

void dfs2(int i, int p) {
    r = max(r, dp[i]);
    for (auto& j : adj[i]) {
        if (j == p) continue;
        shift(i, j);
        dfs2(j, i);
        shift(j, i);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> k;
        adj.assign(n, {});
        r = 0;
        for (int i = 0; i < n-1; i++) {
            int u, v; cin >> u >> v; u--, v--;
            adj[u].pb(v), adj[v].pb(u);
        }
        w.resize(n), dp.resize(n);
        dfs1(0, 0);
        dfs2(0, 0);
        cout << r << "\n";
    }
}