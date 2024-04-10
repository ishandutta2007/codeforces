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

const int maxn = 410000;

vi xe, ep;
vi e[maxn];
vector<pii> qs;
vi tAsk;
int p[maxn];
int par[maxn], xr[maxn];
vi te[2 * maxn];
int vis[2 * maxn], L[2 * maxn], R[2 * maxn];
int T = 0;
int tv = 0;

int root(int x) {
    return par[x] == x ? x : par[x] = root(par[x]);
}

vi seq;

void dfs(int v) {
    assert(!vis[v]);
    vis[v] = 1;
    L[v] = T;
    if (te[v].empty()) {
        seq.pb(p[v]);
        R[v] = ++T;
        return;
    }
    for (int u: te[v]) dfs(u);
    R[v] = T;
}

struct TNode {
    int L, R;
    int l, r;
    pii mx;
};

#define dn TNode &n = st[node]
TNode st[2 * maxn];
int tc = 0;

void relax(int node) {
    dn;
    n.mx = max(st[n.l].mx, st[n.r].mx);
}

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {-1, -1}};
    if (R - L == 1) {
        n.mx = mp(seq[L], L);
    } else {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        relax(node);
    }
    return node;
}

pii segMax(int node, int L, int R) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return mp(-1e9, -1);
    if (L <= n.L && n.R <= R) return n.mx;
    return max(segMax(n.l, L, R), segMax(n.r, L, R));
}

void zeroI(int node, int i) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        n.mx.fi = 0;
        return;
    }
    zeroI(n.l, i);
    zeroI(n.r, i);
    relax(node);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m, q;
    cin >> n >> m >> q;
    forn(i, n) cin >> p[i];
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        xe.pb(u ^ v);
        ep.pb(u);
        e[u].pb(i);
        e[v].pb(i);
    }

    qs = vector<pii>(q);
    forn(i, q) cin >> qs[i].fi >> qs[i].se, --qs[i].se;

    vi ordE, posE(m);
    vi taken(m);
    forn(i, q) if (qs[i].fi == 2) {
        int ei = qs[i].se;
        taken[ei] = 1;
    }
    forn(i, m) if (!taken[i]) {
        qs.pb({2, i});
        ++q;
    }
    tAsk.resize(q);

    forn(i, n) par[i] = xr[i] = i;
    tv = n;
    ford(qi, q) {
        if (qs[qi].fi == 1) tAsk[qi] = xr[root(qs[qi].se)];
        else {
           int ei = qs[qi].se;
           int v = ep[ei], u = v ^ xe[ei];
           if (root(v) == root(u)) continue;
           v = root(v);
           u = root(u);
           int w = tv++;
           te[w].pb(xr[v]);
           te[w].pb(xr[u]);
           par[u] = v;
           xr[v] = w;
        }
    }

    ford(i, tv) if (!vis[i]) dfs(i);

    int root = buildTree(0, n);

    forn(i, q) {
        if (qs[i].fi == 1) {
            int x = tAsk[i];
            auto w = segMax(root, L[x], R[x]);
            cout << w.fi << '\n';
            zeroI(root, w.se);
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}