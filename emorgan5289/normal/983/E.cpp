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

struct segtree {

    using node = vector<int>;

    vector<int> a, b;
    vector<node> tree;
    int n;

    segtree(vector<vector<int>>& v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = v[i-n];
                    sort(all(tree[i]));
                }
            } else {
                a[i] = a[2*i];
                b[i] = b[2*i+1];
                merge(all(tree[2*i]), all(tree[2*i+1]), back_inserter(tree[i]));
            }
        }
    }

    bool get(int i, int x, int y) {
        return lower_bound(all(tree[i]), x) != upper_bound(all(tree[i]), y);
    }

    bool query(int l, int r, int x, int y, int i = 1) {
        if (l <= a[i] && r >= b[i])
            return get(i, x, y);
        if (l > b[i] || r < a[i])
            return 0;
        return query(l, r, x, y, 2*i) || query(l, r, x, y, 2*i+1);
    }
};

const int N = 2e5+5, K = 20;
int jump[N], ans[N];
array<int, 2> qry[N];
vector<vector<int>> adj, j_adj;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    adj.resize(n);
    j_adj.resize(n+1);
    for (int i = 1; i < n; i++) {
        int x; cin >> x;
        adj[x-1].pb(i);
    }
    iota(jump, jump+n, 0);
    ancestor anc(adj, 0);
    vector<vector<int>> buses(n+1);
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y; x--, y--;
        int z = anc.lca(x, y);
        if (anc.d[z] < anc.d[jump[x]]) jump[x] = z;
        if (anc.d[z] < anc.d[jump[y]]) jump[y] = z;
        if (anc.vin[x] > anc.vin[y]) swap(x, y);
        debug(anc.vin[x], anc.vin[y]);
        buses[anc.vin[x]].pb(anc.vin[y]);
    }
    segtree seg(buses);
    for (int i = n-1; i >= 0; i--)
        for (int j : adj[i])
            if (anc.d[jump[j]] < anc.d[jump[i]])
                jump[i] = jump[j];
    for (int i = 0; i < n; i++) {
        if (jump[i] == i)
            j_adj[n].pb(i);
        else
            j_adj[jump[i]].pb(i);
    }
    debug(vector(jump, jump+n));
    debug(j_adj);
    ancestor j_anc(j_adj, n);
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y; x--, y--;
        if (anc.vin[x] > anc.vin[y]) swap(x, y);
        if (j_anc.lca(x, y) == n)
            ans[i] = -1;
        else if (anc.is_ancestor(x, y)) {
            for (int k = j_anc.e; k >= 0; k--)
                if (j_anc.p[y][k] != n && !anc.is_ancestor(j_anc.p[y][k], x))
                    y = j_anc.p[y][k], ans[i] += 1<<k;
            ans[i]++;
        } else {
            for (int k = j_anc.e; k >= 0; k--)
                if (j_anc.p[y][k] != n && !anc.is_ancestor(j_anc.p[y][k], x))
                    y = j_anc.p[y][k], ans[i] += 1<<k;
            for (int k = j_anc.e; k >= 0; k--)
                if (j_anc.p[x][k] != n && !anc.is_ancestor(j_anc.p[x][k], y))
                    x = j_anc.p[x][k], ans[i] += 1<<k;
            ans[i] += 2;
            if (seg.query(anc.vin[x], anc.vout[x], anc.vin[y], anc.vout[y]))
                ans[i]--;
        }
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
}