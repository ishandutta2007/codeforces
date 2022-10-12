#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct segtree {

    ll combine(ll x, ll y) {
        return min(x, y);
    }

    constexpr static ll identity = inf_ll;

    vector<int> a, b;
    vector<ll> tree;
    vector<ll> u;
    int n;

    segtree() {}

    segtree(vector<ll>& v) {

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
        if (u[i] == 0) return;
        tree[i] += u[i];
        if (i < n) {
            u[2*i+1] += u[i], u[2*i] += u[i];
        }
        u[i] = 0;
    }

    void update(int l, int r, ll x, int i = 1) {
        if (l <= a[i] && r >= b[i]) {
            u[i] += x;
        }
        push(i);
        if (l > b[i] || r < a[i] || l <= a[i] && r >= b[i])
            return;
        update(l, r, x, 2*i);
        update(l, r, x, 2*i+1);
        tree[i] = combine(tree[2*i], tree[2*i+1]);
    }

    ll query(int l, int r, int i = 1) {
        push(i);
        if (l <= a[i] && r >= b[i])
            return tree[i];
        if (l > b[i] || r < a[i])
            return identity;
        return combine(query(l, r, 2*i), query(l, r, 2*i+1));
    }
};

const int N = 500005;
vector<vector<pair<ll, int>>> adj;
vector<ll> a;
ll vout[N], t = 0, res[N];
vector<array<ll, 3>> qry[N];
segtree s;

void dfs(int i) {
    t++;
    for (auto& [w, j] : adj[i])
        a[j] = a[i]+w, dfs(j);
    vout[i] = t-1;
}

void dfs2(int i) {
    for (auto& [l, r, x] : qry[i]) {
        res[x] = s.query(l, r);
    }
    for (auto& [w, j] : adj[i]) {
        s.update(0, adj.size()-1, w);
        s.update(j, vout[j], -2*w);
        dfs2(j);
        s.update(0, adj.size()-1, -w);
        s.update(j, vout[j], 2*w);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    adj.resize(n);
    for (int i = 1; i < n; i++) {
        ll p, w; cin >> p >> w; p--;
        adj[p].pb({w, i});
    }
    a.assign(n, 0);
    dfs(0);
    for (int i = 0; i < n; i++)
        if (adj[i].size() > 0)
            a[i] = inf_ll;
    s = segtree(a);
    for (int i = 0; i < q; i++) {
        ll v, l, r; cin >> v >> l >> r;
        qry[v-1].pb({l-1, r-1, i});
    }
    dfs2(0);
    for (int i = 0; i < q; i++)
        cout << res[i] << "\n";
}