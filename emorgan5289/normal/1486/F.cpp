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

struct hld_single {

    vector<vector<int>> adj;
    vector<int> vin, vout, head, p, d, sz;
    vector<bool> hvy;
    int n, t = 0;

    void _assign(int i, int v) {
        if ((p[i] = v) != -1) d[i] = d[v]+1;
        for (int j : adj[i])
            if (j != v) _assign(j, i), sz[i] += sz[j];
        int b = -1;
        for (int j : adj[i])
            if (j != v && (b == -1 || sz[j] > sz[b])) b = j;
        if (b != -1) hvy[b] = 1;
    }

    void _dfs(int i) {
        vin[i] = t++;
        head[i] = hvy[i] ? head[p[i]] : i;
        for (int j : adj[i])
            if (j != p[i] && hvy[j]) _dfs(j);
        for (int j : adj[i])
            if (j != p[i] && !hvy[j]) _dfs(j);
        vout[i] = t-1;
    }

    hld_single(vector<vector<int>> _adj = {}, int root = 0) : adj(_adj), n(_adj.size()) {
        if (_adj.size() == 0) return;
        vin.resize(n), vout.resize(n), head.resize(n);
        p.assign(n, -1), d.assign(n, 0), sz.assign(n, 1), hvy.assign(n, 0);
        _assign(root, -1), _dfs(root);
    }

    // returns a single interval (inclusive of both ends) which
    // represents the subtree of vertex i.
    array<int, 2> subtree(int i) const {
        return {vin[i], vout[i]};
    }

    // returns a sorted list of disjoint intervals (inclusive of both ends).
    // the list has length O(logn) and the union of the intervals represents the
    // path from vertex i to the root (inclusive of both).
    vector<array<int, 2>> path(int i) const {
        vector<array<int, 2>> out;
        for (; i != -1; i = p[head[i]])
            out.push_back({vin[head[i]], vin[i]});
        reverse(out.begin(), out.end());
        return out;
    }

    // returns a sorted list of disjoint intervals (inclusive of both ends).
    // the list has length O(logn) and the union of the intervals represents the
    // path from vertex i to vertex j (inclusive of both).
    vector<array<int, 2>> path(int i, int j) const {
        vector<array<int, 2>> tmp, out;
        for (; head[i] != head[j]; j = p[head[j]]) {
            if (d[head[i]] > d[head[j]]) swap(i, j);
            tmp.push_back({vin[head[j]], vin[j]});
        }
        if (d[i] > d[j]) swap(i, j);
        tmp.push_back({vin[i], vin[j]});
        sort(tmp.begin(), tmp.end());
        for (auto [l, r] : tmp) {
            if (!out.empty() && out.back()[1] == l-1)
                l = out.back()[0], out.pop_back();
            out.push_back({l, r});
        }
        return out;
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

// ordered statistic tree using fenwick tree.
// all operations take O(log(N)),
// where N is the limit on size of elements.
// see https://codeforces.com/blog/entry/61364

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

const int N = 1e6+5;
fenwick_multiset<N> l;
map<array<int, 2>, int> mp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    hld_single hld(adj);
    ancestor anc(adj);
    int m; cin >> m;
    vector<array<int, 3>> e;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y; x--, y--;
        e.pb({-anc.d[anc.lca(x, y)], x, y});
    }
    sort(all(e));
    ll ans = 0;
    for (auto& [_, x, y] : e) {
        auto p = hld.path(x, y);
        for (auto& [a, b] : p)
            ans += l.index(b+1)-l.index(a);
        auto lca = anc.lca(x, y);
        l.insert(p[0][0]);
        int px = -1, py = -1;
        if (x != lca) px = anc.step(lca, x), l.remove(hld.vin[px]);
        if (y != lca) py = anc.step(lca, y), l.remove(hld.vin[py]);
        if (x != lca && y != lca) {
            if (px < py) swap(px, py);
            ans += mp[{px, py}]++;
        }
    }
    cout << ans << "\n";
}