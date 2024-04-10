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

struct segtree {

    using node = array<ll, 4>;
    // {min, max, min true, max true}

    node combine(node x, node y) {
        return {min(x[0], y[0]), max(x[1], y[1]), min(x[2], y[2]), max(x[3], y[3])};
    }

    constexpr static node identity = {inf, -1, inf, -1};

    vector<int> a, b;
    vector<node> tree;
    vector<int> u; // 0 -> nothing, -1 -> false, 1 -> true
    int n;

    segtree(vector<ll>& v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);
        u.assign(2*n, 0);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = {v[i-n], v[i-n], inf, -1};
                } else {
                    tree[i] = identity;
                }
            } else {
                a[i] = a[2*i];
                b[i] = b[2*i+1];
                tree[i] = combine(tree[2*i], tree[2*i+1]);
            }
        }
    }

    void push(int i) {
        if (!u[i]) return;
        if (u[i] == -1) tree[i][2] = inf, tree[i][3] = -1;
        if (u[i] == 1) tree[i][2] = tree[i][0], tree[i][3] = tree[i][1];
        if (i < n) {
            u[2*i] = u[2*i+1] = u[i];
        }
        u[i] = 0;
    }

    void update(int l, int r, int x, int i = 1) {
        if (l <= a[i] && r >= b[i]) {
            u[i] = x;
        }
        push(i);
        if (l > b[i] || r < a[i] || (l <= a[i] && r >= b[i]))
            return;
        update(l, r, x, 2*i);
        update(l, r, x, 2*i+1);
        tree[i] = combine(tree[2*i], tree[2*i+1]);
    }

    node query(int l, int r, int i = 1) {
        push(i);
        if (l <= a[i] && r >= b[i])
            return tree[i];
        if (l > b[i] || r < a[i])
            return identity;
        return combine(query(l, r, 2*i), query(l, r, 2*i+1));
    }
};

template<typename it, typename bin_op>
struct sparse_table {

    using T = typename iterator_traits<it>::value_type;
    vector<vector<T>> t; bin_op f;

    void assign(it first, it last) {
        int n = distance(first, last);
        t.assign(32-__builtin_clz(n), vector<T>(n));
        t[0].assign(first, last);
        for (int i = 1; i < t.size(); i++)
            for (int j = 0; j < n-(1<<i)+1; j++)
                t[i][j] = f(t[i-1][j], t[i-1][j+(1<<(i-1))]);
    }

    sparse_table(bin_op op) : f(op) {}
    sparse_table(it first, it last, bin_op op) : f(op) {
        assign(first, last);
    }

    // returns f(a[l..r]) in O(1) time
    T operator()(int l, int r) {
        int h = floor(log2(r-l+1));
        return f(t[h][l], t[h][r-(1<<h)+1]);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, q; cin >> n >> q;
    vector<array<ll, 3>> e;
    for (int i = 0; i < n-1; i++) {
        ll x, y, w; cin >> x >> y >> w;
        e.pb({w, x-1, y-1});
    }
    debug(e);
    sort(all(e));
    dsu u(n);
    vector<ll> vl(n), vr(n);
    iota(all(vl), 0), iota(all(vr), 0);
    vector<vector<array<ll, 2>>> adj(n);
    for (auto& [w, x, y] : e) {
        x = u.rep(x), y = u.rep(y);
        u.unite(x, y);
        int z = u.rep(x);
        adj[vr[x]].pb({w, vl[y]});
        adj[vl[y]].pb({w, vr[x]});
        vl[z] = vl[x], vr[z] = vr[y];
    }
    // map<ll, ll> degf;
    // for (int i = 0; i < n; i++)
    //     degf[adj[i].size()]++;
    // debug(degf);
    ll c = 0;
    for (int i = 0; i < n; i++)
        if (adj[i].size() == 1) c = i;
    vector<ll> vis(n), vin(n), ord(n), val;
    debug(adj[0]);
    for (int i = 0; i < n; i++) {
        debug(c);
        vis[c] = 1;
        vin[c] = i;
        ord[i] = c;
        for (auto& [w, j] : adj[c])
            if (!vis[j]) c = j, val.pb(w);
    }
    debug(ord, val);
    sparse_table max_val(all(val), [&](ll x, ll y){ return max(x, y); });
    debug(vin);
    segtree s(vin);
    while (q--) {
        int t; cin >> t;
        debug(t);
        if (t == 1) {
            ll l, r; cin >> l >> r; l--, r--;
            s.update(l, r, 1);
        } else if (t == 2) {
            ll l, r; cin >> l >> r; l--, r--;
            s.update(l, r, -1);
        } else {
            ll x; cin >> x;
            debug(x);
            x = vin[x-1];
            debug(x);
            auto [_1, _2, l, r] = s.query(0, n-1);
            ll ans = -1;
            if (l < x)
                cmax(ans, max_val(l, x-1));
            if (r > x)
                cmax(ans, max_val(x, r-1));
            cout << ans << "\n";
        }
    }
}