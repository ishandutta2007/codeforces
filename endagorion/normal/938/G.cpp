#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 210000, B = 30;
int par[maxn], rk[maxn], pare[maxn];
int bsz[maxn], base[maxn][B];

pii root(int x) {
    if (x == par[x]) return {x, 0};
    auto res = root(par[x]);
    res.se ^= pare[x];
    return res;
}

vector<pair<int*, int> > chs;

void change(int &x, int y) {
    chs.pb({&x, x});
    x = y;
}

void revert(int sz) {
    while ((int)chs.size() > sz) {
        auto [ptr, x] = chs.back();
        *ptr = x;
        chs.pop_back();
    }
}

int modb(int v, int x) {
    forn(i, bsz[v]) uin(x, x ^ base[v][i]);
    return x;
}

void addtob(int v, int x) {
    if (!modb(v, x)) return;
    forn(i, bsz[v]) {
        int &u = base[v][i];
        uin(x, x ^ u);
        if (x > u) {
            int ou = u;
            change(u, x);
            x = ou;
        }
    }
    assert(x);
    change(base[v][bsz[v]], x);
    change(bsz[v], bsz[v] + 1);
}

void add_edge(int u, int v, int x) {
    auto pu = root(u), pv = root(v);
    x ^= pu.se ^ pv.se;
    u = pu.fi, v = pv.fi;
    if (u == v) addtob(u, x);
    else {
        if (rk[u] < rk[v]) swap(u, v);
        change(par[v], u);
        change(pare[v], x);
        if (rk[u] == rk[v]) change(rk[u], rk[v] + 1);
        forn(i, bsz[v]) addtob(u, base[v][i]);
    }
}

int query(int u, int v) {
    auto pu = root(u), pv = root(v);
    assert(pu.fi == pv.fi);
    return modb(pu.fi, pu.se ^ pv.se);
}

struct Edge {
    int u, v, x;
};

struct TNode {
    int L, R;
    int l, r;
    vector<Edge> es;
    optional<pii> query;
};

TNode t[2 * maxn];
int tc = 0;

#define dn TNode &n = t[node]

int build_tree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {}, nullopt};
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = build_tree(L, M);
        n.r = build_tree(M, R);
    }
    return node;
}

void seg_edge(int node, int L, int R, Edge e) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return;
    if (L <= n.L && n.R <= R) {
        n.es.pb(e);
        return;
    }
    seg_edge(n.l, L, R, e);
    seg_edge(n.r, L, R, e);
}

void seg_query(int node, int i, pii q) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        assert(!n.query.has_value());
        n.query = q;
        return;
    }
    seg_query(n.l, i, q);
    seg_query(n.r, i, q);
}

void dfs_root(int node) {
    if (node == -1) return;
    dn;
    int save = chs.size();
    for (auto e: n.es) {
//        cerr << "+ " << n.L << ' ' << n.R << ' ' << e.u << ' ' << e.v << ' ' << e.x << '\n';
        add_edge(e.u, e.v, e.x);
    }
    if (n.query.has_value()) {
        auto [u, v] = *n.query;
//        cerr << "? " << n.L << ' ' << u << ' ' << v << '\n';
        cout << query(u, v) << '\n';
    }
    dfs_root(n.l);
    dfs_root(n.r);
    revert(save);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    cin >> n >> m;
    forn(i, n) {
        par[i] = i;
    }
    map<pii, int> added, weight;
    forn(i, m) {
        int u, v, x;
        cin >> u >> v >> x;
        --u; --v;
        weight[{u, v}] = x;
        added[{u, v}] = 0;
    }

    int q;
    cin >> q;
    int root = build_tree(0, q);
    forn(i, q) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v, x;
            cin >> u >> v >> x;
            --u; --v;
            weight[{u, v}] = x;
            added[{u, v}] = i + 1;
        } else if (type == 2) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            seg_edge(root, added[{u, v}], i, {u, v, weight[{u, v}]});
            added.erase({u, v});
            weight.erase({u, v});
        } else {
            int u, v;
            cin >> u >> v;
            --u; --v;
            seg_query(root, i, {u, v});
        }
    }
    for (auto [e, t]: added) {
        auto [u, v] = e;
        seg_edge(root, t, q, {u, v, weight[e]});
    }

    dfs_root(root);

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}