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

struct bridges {

    vector<int> low, tin;
    vector<bool> bridge;
    vector<vector<pair<int, int>>> adj;
    int e = 0, t = 0;

    bridges(int n) : adj(n), low(n, -1), tin(n, -1) {}

    // add an undirected edge between i and j
    void edge(int i, int j) {
        adj[i].push_back({j, e});
        adj[j].push_back({i, e++});
        bridge.push_back(0);
    }

    void dfs(int i, int p) {
        low[i] = tin[i] = ++t;
        for (auto& [j, k] : adj[i])
            if (k != p) {
                if (low[j] == -1) {
                    dfs(j, k);
                    low[i] = min(low[i], low[j]);
                    if (low[j] > low[i])
                        bridge[k] = 1;
                } else
                    low[i] = min(low[i], tin[j]);
            }
    }

    // returns a component vector for biconnected components in O(V+E).
    vector<int> components() {
        vector<int> comp(adj.size(), -1), stk;
        for (int i = 0; i < adj.size(); i++)
            if (low[i] == -1)
                dfs(i, -1);
        int c = 0;
        for (int i = 0; i < adj.size(); i++)
            if (comp[i] == -1) {
                stk.push_back(i);
                while (!stk.empty()) {
                    int j = stk.back(); stk.pop_back();
                    comp[j] = c;
                    for (auto& [k, l] : adj[j])
                        if (comp[k] == -1 && !bridge[l])
                            stk.push_back(k);
                }
                c++;
            }
        return comp;
    }
};

vector<int> odd_v, deg, v;
vector<array<int, 2>> dp;
vector<vector<array<int, 2>>> odd_adj;

void dfs(int i) {
    odd_v[i] = 1;
    int max_diff = 0;
    for (auto& [j, t] : odd_adj[i]) {
        if (odd_v[j]) continue;
        dfs(j);
        dp[i][1] += dp[j][0];
        dp[i][0] += dp[j][0];
        cmax(max_diff, dp[j][1]-dp[j][0]+1);
    }
    dp[i][0] += max_diff;
}

void dfs2(int i, int k, int x) {
    debug(i, k, x);
    if (x || dp[i][1] >= dp[i][0]) {
        for (auto& [j, t] : odd_adj[i])
            if (j != k) dfs2(j, i, 0);
        return;
    }
    int b = -1;
    for (auto& [j, t] : odd_adj[i]) {
        if (j == k) continue;
        if (b == -1 || dp[j][1]-dp[j][0] > dp[b][1]-dp[b][0])
            b = j;
    }
    for (auto& [j, t] : odd_adj[i]) {
        if (j == k) continue;
        if (j == b) {
            dfs2(j, i, 1);
            deg[i]--, deg[j]--, v[t] = 1;
        } else
            dfs2(j, i, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (1) {
        int n, m; cin >> n >> m;
        if (n == 0 && m == 0) exit(0);
        vector<array<int, 2>> e;
        while (m--) {
            int len; cin >> len;
            int p = -1;
            for (int i = 0; i < len; i++) {
                int x; cin >> x; x--;
                if (p != -1) e.pb({x, p});
                p = x;
            }
        }
        m = e.size();
        bridges br(n);
        for (auto& [x, y] : e)
            br.edge(x, y);
        auto c = br.components();
        vector<vector<array<int, 2>>> adj(n);
        odd_adj.assign(n, {});
        dp.assign(n, {0, 0});
        odd_v.assign(n, 0);
        deg.assign(n, 0);
        v.assign(n, 0);
        int t = 0;
        for (auto& [x, y] : e)
            if (c[x] != c[y]) {
                adj[x].pb({y, t});
                adj[y].pb({x, t});
                deg[x]++, deg[y]++;
                t++;
            }
        for (int x = 0; x < n; x++)
            for (auto& [y, j] : adj[x])
                if ((deg[x]&1) && (deg[y]&1)) {
                    debug(x, y, j);
                    odd_adj[x].pb({y, j});
                }
        debug(odd_adj);
        for (int i = 0; i < n; i++)
            if (!odd_v[i]) dfs(i), dfs2(i, i, 0);
        debug(v);
        vector<array<int, 2>> ans;
        for (int x = 0; x < n; x++) {
            if (deg[x]&1) {
                int i = x;
                while (1) {
                    while (!adj[i].empty() && v[adj[i].back()[1]])
                        adj[i].pop_back();
                    if (adj[i].empty()) break;
                    v[adj[i].back()[1]] = 1;
                    deg[i]--;
                    i = adj[i].back()[0];
                    deg[i]--;
                }
                ans.pb({i, x});
            }
        }
        cout << ans.size() << "\n";
        for (auto& [x, y] : ans) {
            cout << x+1 << " " << y+1 << "\n";
        }
    }
}