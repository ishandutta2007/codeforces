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

const int N = 2e5+5;
vector<int> adj[N];
ll w[N], vis[N], dp[N], r[N], leaf;

void dfs(int i, int p) {
    vis[i] = 1, dp[i] = w[i];
    ll x = 0;
    for (auto& j : adj[i])
        if (j != p) {
            if (vis[j]) r[i] = 1;
            else {
                dfs(j, i);
                r[i] |= r[j];
                if (r[j]) dp[i] += dp[j];
                else x = max(x, dp[j]);
            }
        }
    if (!r[i]) {
        dp[i] += x;
        leaf = max(leaf, dp[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    while (m--) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    int s; cin >> s; s--;
    r[s] = 1;
    dfs(s, s);
    debug(leaf);
    debug(vector(r, r+n));
    debug(vector(w, w+n));
    debug(vector(dp, dp+n));
    cout << dp[s]+leaf << "\n";
}