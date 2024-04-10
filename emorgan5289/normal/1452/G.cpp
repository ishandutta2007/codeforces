#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

// combined data structure for various ancestor-related queries.

struct ancestor {

    vector<int> vin, vout, d;
    vector<vector<int>> adj, p;
    int n, t = 0, e;

    void dfs(int i, int v) {
        vin[i] = t++;
        p[i][0] = v, d[i] = d[v]+1;
        for (int j = 1; j <= e; j++)
            p[i][j] = p[p[i][j-1]][j-1];
        for (auto& j : adj[i])
            if (j != v) dfs(j, i);
        vout[i] = t-1;
    }

    ancestor() {}

    // accepts an adjecency list. can include or exlude parents, it works either way.
    // constructor runs in O(nlogn) time.
    ancestor(vector<vector<int>> _adj, int root) : adj(_adj), n(_adj.size()) {
        vin.resize(n), vout.resize(n), d.assign(n, 0);
        e = ceil(log2(n));
        p.assign(n, vector<int>(e+1));
        dfs(root, root);
    }

    // returns true if i is an ancestor of j in O(1) time.
    bool is_ancestor(int i, int j) const {
        return vin[i] <= vin[j] && vout[i] >= vout[j];
    }

    // returns the k'th ancestor of i O(logk) time.
    int ktha(int i, int k) const {
        for (int j = 0; (1<<j) <= k; j++)
            if (k&(1<<j)) i = p[i][j];
        return i;
    }

    // returns the LCA of i and j in O(logn) time.
    int lca(int i, int j) const {
        if (is_ancestor(i, j)) return i;
        if (is_ancestor(j, i)) return j;
        for (int k = e; k >= 0; k--)
            if (!is_ancestor(p[i][k], j))
                i = p[i][k];
        return p[i][0];
    }

    // returns the vertex one step along the path from i to j in O(logn) time.
    int step(int i, int j) const {
        return is_ancestor(i, j) ? ktha(j, d[j]-d[i]-1) : p[i][0];
    }

    // returns the number of edges between i and j in O(logn) time.
    int dist(int i, int j) {
        return d[i]+d[j]-2*d[lca(i, j)];
    }
};

// note, the file lca_old.cpp allows lca queries in O(1) time instead of O(logn) time,
// but has a much higher constant factor and can cause MLE for around 5*10^5 vertices.

struct centroid {

    int c, s;
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<int> sz;

    centroid(int n) : adj(n), vis(n, 0), sz(n) {}

    // add an edge between i and j
    void edge(int i, int j) {
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    void dfs1(int i, int p) {
        sz[i] = 1;
        for (int j : adj[i])
            if (j != p && !vis[j]) {
                dfs1(j, i);
                sz[i] += sz[j];
            }
    }

    void dfs2(int i, int p) {
        bool v = sz[i] >= s;
        for (int j : adj[i])
            if (j != p && !vis[j]) {
                dfs2(j, i);
                v &= sz[j] <= s;
            }
        if (v) c = i;
    }

    int find(int r) {
        dfs1(r, r);
        s = sz[r]/2;
        dfs2(r, r);
        return c;
    }

    // returns the vertices of the tree ordered in a
    // pre-order dfs traversal of the centroid tree in O(VlogV)
    vector<int> list() {
        vector<int> out, stk = {0};
        while (!stk.empty()) {
            int i = find(stk.back()); stk.pop_back();
            out.push_back(i);
            vis[i] = 1;
            for (int j : adj[i])
                if (!vis[j])
                    stk.push_back(j);
        }
        return out;
    }

    // returns {root, children-only adjacency list} of the centroid tree
    pair<int, vector<vector<int>>> tree() {
        int root = find(0);
        vector<vector<int>> out(adj.size());
        vector<int> stk = {root};
        while (!stk.empty()) {
            int i = stk.back(); stk.pop_back();
            vis[i] = 1;
            for (int j : adj[i])
                if (!vis[j]) {
                    int r = find(j);
                    out[i].push_back(r);
                    stk.push_back(r);
                }
        }
        return {root, out};
    }
};

const int N = 2e5+5;
vector<vector<int>> adj, cadj;
vector<int> stk, rch[N];
int v[N], d[N], cr, ans[N], mdist[N];
ancestor a;

void dfs4(int i, int p, int r, int dist) {
    cmax(mdist[r], dist);
    for (auto& j : adj[i])
        if (!v[j] && p != j) dfs4(j, i, r, dist+1);
}

void dfs5(int i) {
    dfs4(i, i, i, 0);
    v[i] = 1;
    for (auto& j : cadj[i]) dfs5(j);
}

void dfs1(int i) {
    stk.pb(i);
    // debug(i, stk);
    for (auto& x : stk) {
        int r = min(d[i]-a.dist(i, x)-1, mdist[x]+2);
        // debug(i, d[i], x, r);
        if (r < 0) continue;
        while (rch[x].size() <= r) rch[x].pb(0);
        cmax(rch[x][r], d[i]);
    }
    for (auto& j : cadj[i]) dfs1(j);
    stk.pop_back();
}

void dfs3(int i, int p, int r, int dist) {
    // debug(i, r, dist);
    if (dist < rch[r].size()) {
        // debug(i, rch[r][dist]);
        cmax(ans[i], rch[r][dist]);
    }
    for (auto& j : adj[i])
        if (!v[j] && p != j) dfs3(j, i, r, dist+1);
}

void dfs2(int i) {
    dfs3(i, i, i, 0);
    v[i] = 1;
    for (auto& j : cadj[i]) dfs2(j);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    adj.resize(n);
    centroid cent(n);
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
        cent.edge(x, y);
    }
    int k; cin >> k;
    queue<int> q;
    fill(d, d+n, inf);
    while (k--) {
        int x; cin >> x; x--;
        d[x] = 0, q.push(x);
    }
    while (!q.empty()) {
        int i = q.front(); q.pop();
        for (auto& j : adj[i])
            if (d[j] == inf) d[j] = d[i]+1, q.push(j);
    }
    a = ancestor(adj, 0);
    tie(cr, cadj) = cent.tree();
    fill(v, v+n, 0);
    dfs5(cr);
    fill(v, v+n, 0);
    dfs1(cr);
    for (int i = 0; i < n; i++)
        for (int j = rch[i].size()-2; j >= 0; j--)
            cmax(rch[i][j], rch[i][j+1]);
    dfs2(cr);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n-1];
}