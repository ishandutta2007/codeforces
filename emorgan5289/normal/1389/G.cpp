#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
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

vector<ll> v, c, w, cv, cc, p, r, dp1;
vector<pair<int, int>> e;
vector<vector<pair<ll, int>>> adj;
int n;

void dfs1(int i, int k, bool s) {
    int d = 0;
    for (auto& [_, j] : adj[i]) {
        if (j == k) continue;
        dfs1(j, i, s || v[i]);
        d += v[j];
    }
    if (d+s > 1) v[i] = 1;
}

bool dfs5(int i, int k) {
    int d = 0;
    for (auto& [_, j] : adj[i]) {
        if (j == k) continue;
        d += dfs5(j, i);
    }
    if (d > 1) v[i] = 1;
    return d > 0 || v[i];
}

void dfs2(int i, int k) {
    if (v[i]) p[i] = i;
    else p[i] = p[k];
    for (auto& [wt, j] : adj[i]) {
        if (j == k) continue;
        dfs2(j, i);
        if (p[j] != j)
            c[i] += c[j], c[j] = 0;
    }
}

void dfs3(int i, int k) {
    dp1[i] = c[i];
    for (auto& [wt, j] : adj[i]) {
        if (j == k || !v[j]) continue;
        dfs3(j, i);
        dp1[i] += max(dp1[j]-wt, 0ll);
    }
}

void shift(int i, int j, ll wt) {
    dp1[i] -= max(dp1[j]-wt, 0ll);
    dp1[j] += max(dp1[i]-wt, 0ll);
}

void dfs4(int i, int k) {
    r[i] = dp1[i];
    for (auto& [wt, j] : adj[i]) {
        if (j == k || !v[j]) continue;
        shift(i, j, wt);
        dfs4(j, i);
        shift(j, i, wt);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m, k; cin >> n >> m >> k;
    v.resize(k), c.resize(n), w.resize(m);
    bridges b(n);
    for (int i = 0; i < k; i++)
        cin >> v[i], v[i]--;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < m; i++)
        cin >> w[i];
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y; x--, y--;
        e.pb({x, y});
        b.edge(x, y);
    }
    debug(e);
    auto comp = b.components();
    int cn = *max_element(all(comp))+1;
    debug(comp, cn);
    adj.resize(cn);
    for (int i = 0; i < m; i++) {
        auto [x, y] = e[i];
        x = comp[x], y = comp[y];
        if (x != y) {
            adj[x].pb({w[i], y});
            adj[y].pb({w[i], x});
        }
    }
    cv.assign(cn, 0), cc.assign(cn, 0);
    for (auto& i : v)
        cv[comp[i]] = 1;
    for (int i = 0; i < n; i++)
        cc[comp[i]] += c[i];
    c = move(cc), v = move(cv);
    n = cn;

    debug(n, c, v, adj);
    p.resize(n), r.resize(n);
    dp1.resize(n);
    dfs5(0, 0);
    dfs1(0, 0, 0);
    int root;
    for (int i = 0; i < n; i++)
        if (v[i]) root = i;
    debug(root);
    dfs2(root, root);
    debug(n, c, v, adj);
    dfs3(root, root);
    debug(dp1);
    dfs4(root, root);
    debug(r);

    for (int i = 0; i < comp.size(); i++) {
        debug(comp[i], p[comp[i]]);
        cout << r[p[comp[i]]] << " ";
    }
}

// 32 32 32 32 31 32 32 32 32 32