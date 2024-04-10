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

struct segtree {

    struct node {
        ll sum_on, sum;
    };

    node combine(node x, node y) {
        return {x.sum_on + y.sum_on, x.sum + y.sum};
    }

    constexpr static node identity = {0, 0};

    vector<int> a, b;
    vector<node> tree;
    vector<int> u;
    int n;

    segtree(vector<ll> v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);
        u.assign(2*n, 0);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = {0, v[i-n]};
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
        if (u[i] == 0) return;
        tree[i].sum_on = tree[i].sum - tree[i].sum_on;
        if (i < n) {
            u[2*i] ^= 1;
            u[2*i+1] ^= 1;
        }
        u[i] = 0;
    }

    void update(int l, int r, int x, int i = 1) {
        if (l <= a[i] && r >= b[i]) {
            u[i] ^= 1;
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

const int N = 2e5+5;
int n;
vector<array<int, 2>> adj[N];
ll p[N], ins[N], v[N], ans, chk, cnt;
vector<ll> c;
vector<int> matching;
hld_single hld;
segtree seg1({1}), seg2({1});

void dfs(int i) {
    for (auto [e, j] : adj[i])
        if (j != p[i]) {
            p[j] = i;
            c[j] = e+1;
            dfs(j);
        }
}

void insert(int x) {
    debug("insert", x, c[x]);
    ins[x] = 1;
    cnt++;

    for (auto& [l, r] : hld.path(x)) {
        seg1.update(l, r, 1);
        seg2.update(l, r, 1);
    }

    ans = seg1.query(0, n-1).sum_on;
    chk = seg2.query(0, n-1).sum_on;
    debug(chk, cnt);
    cout << (chk*2 == cnt ? ans : 0) << endl;
}

void dfs_out(int i) {
    for (auto [e, j] : adj[i]) {
        if (j == p[i] || !ins[j]) continue;
        dfs_out(j);
        if (!v[j]) {
            debug("edge", i, j);
            v[i] = v[j] = 1;
            matching.pb(e);
        }
    }
}

void query() {
    debug("query");
    debug(chk, cnt);
    if (chk*2 != cnt) {
        cout << 0 << endl;
        return;
    }
    fill(v, v+n, 0);
    matching.clear();
    dfs_out(0);
    cout << matching.size();
    sort(all(matching));
    assert(matching.size()*2 == cnt);
    for (int x : matching)
        cout << " " << x+1;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<vector<int>> uw_adj(n);
    c.resize(n);
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb({i, y}), adj[y].pb({i, x});
        uw_adj[x].pb(y), uw_adj[y].pb(x);
    }
    hld = hld_single(uw_adj, 0);
    fill(p, p+N, -1);
    ans = c[0] = 0;
    cnt = chk = 1;
    ins[0] = 1;
    dfs(0);
    vector<ll> cc(n);
    for (int i = 0; i < n; i++)
        cc[hld.vin[i]] = c[i];
    debug(c, cc);
    seg1 = segtree(cc);
    fill(all(c), 1);
    seg2 = segtree(c);
    seg1.update(hld.vin[0], hld.vin[0], 1);
    seg2.update(hld.vin[0], hld.vin[0], 1);
    while (1) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            insert(x-1);
        } else if (t == 2)
            query();
        else
            break;
    }
}