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

struct segtree {

    struct node {
        int x0, x1;
    };

    node combine(node x, node y) {
        return {max(x.x0, y.x0), max(x.x1, y.x1)};
    }

    constexpr static node identity = {-inf, -inf};

    vector<int> a, b;
    vector<node> tree;
    vector<bool> u;
    int n;

    segtree(vector<node>& v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);
        u.assign(2*n, 0);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = v[i-n];
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
        swap(tree[i].x0, tree[i].x1);
        if (i < n) {
            u[2*i] = !u[2*i];
            u[2*i+1] = !u[2*i+1];
        }
        u[i] = 0;
    }

    void update(int l, int r, int i = 1) {
        if (l <= a[i] && r >= b[i]) {
            u[i] = !u[i];
        }
        push(i);
        if (l > b[i] || r < a[i] || l <= a[i] && r >= b[i])
            return;
        update(l, r, 2*i);
        update(l, r, 2*i+1);
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

int n;
vector<vector<array<int, 2>>> adj;

int bfs(int i) {
    vector<bool> v(n);
    queue<int> q({i}); v[i] = 1;
    int x;
    while (!q.empty()) {
        x = q.front(); q.pop();
        for (auto& [t, j] : adj[x])
            if (!v[j]) v[j] = 1, q.push(j);
    }
    return x;
}

vector<int> d, col;
vector<segtree::node> v;
int tt = 0;
vector<int> vin, vout;

void dfs(int i, int k) {
    vin[i] = tt++;
    if (col[i]) v.pb({-inf, d[i]});
    else v.pb({d[i], -inf});
    for (auto& [t, j] : adj[i])
        if (j != k) {
            d[j] = d[i]+1;
            col[j] = col[i]^t;
            dfs(j, i);
        }
    vout[i] = tt-1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    adj.resize(n);
    vector<array<int, 2>> e;
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        int t; cin >> t;
        adj[x].pb({t, y}), adj[y].pb({t, x});
        e.pb({x, y});
    }
    int r1 = bfs(0);
    int r2 = bfs(r1);

    debug(r1, r2);

    d.assign(n, 0);
    col.assign(n, 0);
    vin.assign(n, 0);
    vout.assign(n, 0);
    v.clear();

    dfs(r1, r1);
    vector<int> vin1(vin), vout1(vout);
    segtree s1(v);

    tt = 0;
    d.assign(n, 0);
    col.assign(n, 0);
    vin.assign(n, 0);
    vout.assign(n, 0);
    v.clear();

    dfs(r2, r2);
    vector<int> vin2(vin), vout2(vout);
    segtree s2(v);

    int m; cin >> m;
    while (m--) {
        int i; cin >> i; i--;
        auto [x, y] = e[i];
        debug(x, y);
        if (vin1[x] >= vin1[y])
            s1.update(vin1[x], vout1[x]);
        else
            s1.update(vin1[y], vout1[y]);
        if (vin2[x] >= vin2[y]) {
            debug(vin2[x], vout2[x]);
            s2.update(vin2[x], vout2[x]);
        }
        else {
            debug(vin2[y], vout2[y]);
            s2.update(vin2[y], vout2[y]);
        }
        debug(s1.query(0, n-1).x0);
        debug(s2.query(0, n-1).x0);
        cout << max(s1.query(0, n-1).x0, s2.query(0, n-1).x0) << "\n";
    }
}