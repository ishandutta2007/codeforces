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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<int N, typename T = int>
struct fenwick_multiset {

    T s = 0, tree[N+1];
    T size() const { return s; }
    fenwick_multiset() { fill(tree, tree+N+1, 0); }
    
    // insert x into the set with multiplicity k
    void insert(int x, const T k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] += k;
        s += k;
    }

    // remove x from the set with multiplicity k
    void remove(int x, const T k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] -= k;
        s -= k;
    }

    // returns the number of elements in
    // the set which are strictly lower than x
    T index(int x) const {
        T i = 0;
        for (; x > 0; x -= x & -x)
            i += tree[x];
        return i;
    }

    // returns the number of elements in the set
    // which are exactly equal to x, O(1) amortized
    T count(int x) const {
        int y = x+1; T i = tree[x+1];
        for (y -= y & -y; x != y; x -= x & -x)
            i -= tree[x];
        return i;
    }

    // returns the x'th element of the set,
    // 0-based indexing
    int get(T x) const {
        int i = 0;
        for (int m = 1<<(31-__builtin_clz(N)); m > 0; m >>= 1)
            if (i+m <= N && tree[i+m] <= x)
                x -= tree[i += m];
        return i;
    }
};

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

const int N = 300005, S = sqrt(2*N);
int vin[N], vout[N], a[N], c[2*N], ans[N], fr[N], fb[N], t = 0;
vector<int> adj[N];
vector<array<int, 6>> qry;

void dfs(int i, int k) {
    vin[i] = t++;
    for (auto& j : adj[i])
        if (j != k) dfs(j, i);
    vout[i] = t++;
    c[vin[i]] = c[vout[i]] = a[i];
}

void ins(int x) {
    fb[x/S] -= fr[x], fr[x] ^= 1, fb[x/S] += fr[x];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    dfs(0, 0);
    ancestor anc(vector(adj, adj+n), 0);
    for (int i = 0; i < q; i++) {
        int u, v, l, r; cin >> u >> v >> l >> r; u--, v--;
        if (vin[u] > vin[v]) swap(u, v);
        // debug(vin[u], vout[u], vin[v], vout[v]);
        if (vout[u] >= vout[v])
            qry.pb({i, vin[u]+1, vin[v], l, r, a[u]});
        else
            qry.pb({i, vout[u], vin[v], l, r, a[anc.lca(u, v)]});
        // debug(i, qry.back()[1], qry.back()[2], a[u]);
        // debug(i, vector(c+qry.back()[1], c+qry.back()[2]+1));
    }
    // debug(qry);
    sort(all(qry), [&](auto x, auto y){
        return x[1]/S == y[1]/S ? x[2] < y[2] : x[1] < y[1];
    });
    int x = 0, y = -1;
    for (auto& [i, l, r, p, cr, ca] : qry) {
        while (y < r) ins(c[++y]);
        while (y > r) ins(c[y--]);
        while (x < l) ins(c[x++]);
        while (x > l) ins(c[--x]);
        ins(ca);
        while (!fr[p] && p%S != 0) p++;
        while (!fb[p/S] && p < N) p += S;
        while (!fr[p] && p < N) p++;
        ans[i] = p <= cr ? p : -1;
        ins(ca);
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
}