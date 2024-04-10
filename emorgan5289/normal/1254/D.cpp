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

struct ancestor {

    vector<int> vin, vout, d, sz;
    vector<vector<int>> &adj, p;
    int n, t = 0, e;

    void dfs(int i, int v) {
        vin[i] = t++;
        p[i][0] = v, d[i] = d[v]+1;
        for (int j = 1; j <= e; j++)
            p[i][j] = p[p[i][j-1]][j-1];
        for (auto& j : adj[i])
            if (j != v)
                dfs(j, i), sz[i] += sz[j];
        vout[i] = t-1;
    }

    // accepts an adjecency list. can include or exlude parents, it works either way.
    // constructor runs in O(nlogn) time.
    ancestor(vector<vector<int>>& _adj, int root) : adj(_adj), n(_adj.size()) {
        vin.resize(n), vout.resize(n);
        d.assign(n, 0), sz.assign(n, 1);
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
};

const ll mod = 998244353;

struct segtree {

    vector<int> a, b;
    vector<ll> tree, u;
    int n;

    segtree(int _n) {

        n = 1<<int(ceil(log2(_n)));
        tree.assign(2*n, 0);
        a.resize(2*n); b.resize(2*n);
        u.assign(2*n, 0);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
            } else {
                a[i] = a[2*i];
                b[i] = b[2*i+1];
                tree[i] = (tree[2*i]+tree[2*i+1])%mod;
            }
        }
    }

    void push(int i) {
        if (u[i] == 0) return;
        tree[i] = (tree[i]+u[i])%mod;
        if (i < n) {
            u[2*i] = (u[2*i]+u[i])%mod;
            u[2*i+1] = (u[2*i+1]+u[i])%mod;
        }
        u[i] = 0;
    }

    void update(int l, int r, ll x, int i = 1) {
        if (l <= a[i] && r >= b[i])
            u[i] = (u[i]+x)%mod;
        push(i);
        if (l > b[i] || r < a[i] || l <= a[i] && r >= b[i])
            return;
        update(l, r, x, 2*i);
        update(l, r, x, 2*i+1);
        tree[i] = (tree[2*i]+tree[2*i+1])%mod;
    }

    ll query(int l, int r, int i = 1) {
        push(i);
        if (l <= a[i] && r >= b[i])
            return tree[i];
        if (l > b[i] || r < a[i])
            return 0;
        return (query(l, r, 2*i)+query(l, r, 2*i+1))%mod;
    }
};

template<typename T>
struct fenwick {

    int length;
    vector<T> tree;

    fenwick(int size) {
        length = size+1;
        tree.assign(length+1, 0);
    }

    fenwick(vector<T>& v) {
        length = v.size()+1;
        tree.assign(length+1, 0);
        for (int i = 0; i < v.size(); i++)
            update(i, v[i]);
    }

    // insert val at index i
    void update(int i, T val) {
        i++;
        while (i < length) {
            tree[i] = (tree[i]+val)%mod;
            i += i & -i;
        }
    }

    // inclusive of i
    T prefix(int i) {
        i++;
        T out = 0;
        while (i > 0) {
            out = (out+tree[i])%mod;;
            i -= i & -i;
        }
        return out;
    }
};

template<typename T>
T inv(T a, T m) {
    T r = 1;
    for (T k = m-2; k; k >>= 1) {
        if (k&1) r = (r*a)%m;
        a = (a*a)%m;
    }
    return r%m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q, b; cin >> n >> q; b = sqrt(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    ancestor a(adj, 0);
    vector<int> h;
    vector<ll> c(n);
    for (int i = 0; i < n; i++)
        if (adj[i].size() > b) h.pb(i);
    ll ninv = inv((ll)n, mod), g = 0;
    // segtree s(n);
    fenwick<ll> f(n+100);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            ll v, d; cin >> v >> d; v--;
            g = (g+d*a.sz[v]%mod*ninv%mod)%mod;
            ll u = d*(n-a.sz[v])%mod*ninv%mod;
            f.update(a.vin[v], u);
            f.update(a.vout[v]+1, mod-u);
            if (adj[v].size() > b)
                c[v] = (c[v]+d)%mod;
            else {
                for (auto& j : adj[v])
                    if (a.vin[j] > a.vin[v]) {
                        u = mod-d*a.sz[j]%mod*ninv%mod;
                        f.update(a.vin[j], u);
                        f.update(a.vout[j]+1, mod-u);
                    }
            }
        } else {
            ll v; cin >> v; v--;
            ll x = (f.prefix(a.vin[v])+g)%mod;
            for (auto& i : h)
                if (a.is_ancestor(i, v) && i != v) {
                    x = (x+mod-c[i]*a.sz[a.step(i, v)]%mod*ninv%mod)%mod;
                }
            cout << x << "\n";
        }
    }
}