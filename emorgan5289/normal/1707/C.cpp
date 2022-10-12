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

    // accepts an adjecency list. can include or exlude parents, it works either way.
    // constructor runs in O(nlogn) time.
    ancestor(vector<vector<int>> _adj = {}, int root = 0) : adj(_adj), n(_adj.size()) {
        if (adj.empty()) return;
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
        while (k) {
            int j = k&-k;
            i = p[i][__builtin_ctz(j)];
            k -= j;
        }
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

struct dsu {

    vector<int> p, sz;

    dsu(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int rep(int x) {
        while (x != p[x]) x = p[x] = p[p[x]];
        return x;
    }

    // returns true if a and b are in the same set, and then unites them.
    bool unite(int a, int b) {
        a = rep(a), b = rep(b);
        if (sz[a] < sz[b]) swap(a, b);
        if (a != b) p[b] = a, sz[a] += sz[b];
        return a == b;
    }

    // returns true if a and b are in the same set.
    bool query(int a, int b) {
        return rep(a) == rep(b);
    }

    // returns the size of the set containing x
    int size(int x) {
        return sz[rep(x)];
    }
};

vector<vector<int>> adj;
vector<map<int, vector<array<int, 3>>>> mp;
vector<int> bad, ans;
int bsum = 0;

void shift(int i, int j) {
    for (auto& [k, _, y] : mp[i][j]) {
        if (bad[k]) bsum--, bad[k] = 0;
        if (y != j) bad[k] = 1, bsum++;
    }
    for (auto& [k, _, y] : mp[j][i]) {
        if (bad[k]) bsum--, bad[k] = 0;
    }
}

void dfs(int i, int k) {
    debug(i, k);
    if (bsum == 0)
        ans[i] = 1;
    for (int j : adj[i]) {
        if (j == k) continue;
        shift(i, j);
        dfs(j, i);
        shift(j, i);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin >> n >> m;
    dsu u(n);
    adj.assign(n, {});
    bad.assign(m, 0);
    ans.assign(n, 0);
    mp.resize(n);
    vector<array<int, 3>> e;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y; x--, y--;
        if (!u.query(x, y)) {
            u.unite(x, y);
            adj[x].pb(y);
            adj[y].pb(x);
        } else {
            e.pb({i, x, y});
        }
    }
    ancestor anc(adj, 0);
    for (auto& [i, x, y] : e) {
        debug(i, x, y);
        if (anc.d[x] > anc.d[y]) swap(x, y);
        if (!anc.is_ancestor(x, y))
            bad[i] = 1, bsum++;
        mp[x][anc.step(x, y)].pb({i, x, y});
        mp[y][anc.step(y, x)].pb({i, y, x});
    }
    dfs(0, 0);
    for (int i = 0; i < n; i++)
        cout << ans[i];
    cout << "\n";
}