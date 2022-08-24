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

const int maxn = 610000, LOG = 20;
int up[LOG + 1][maxn];
int par[maxn], R[maxn];
int h[maxn];
int we[maxn];

int root(int v) {
    return v == par[v] ? v : par[v] = root(par[v]);
}

int jmp(int v, int k) {
    forn(j, LOG) {
        if (!((k >> j) & 1)) continue;
        v = up[j][v];
    }
    return v;
}

int lca(int v, int u) {
    if (v == -1) return u;
    if (u == -1) return v;
    if (h[u] < h[v]) swap(u, v);
    u = jmp(u, h[u] - h[v]);
    if (u == v) return u;
    ford(j, LOG) {
        int uu = up[j][u], vv = up[j][v];
        if (uu != vv) u = uu, v = vv;
    }
    return up[0][u];
}

struct TNode {
    int L, R;
    int l, r;
    int lc, lc0;
    int val;
};

TNode t[maxn];
int tc = 0;

#define dn TNode &n = t[node]

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, -1, -1, 0};
    if (R - L == 1) {
        n.lc0 = L;
    } else {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        n.lc0 = lca(t[n.l].lc0, t[n.r].lc0);
    }
    return node;
}

void relax(int node) {
    dn;
    n.lc = lca(t[n.l].lc, t[n.r].lc);
}

void addval(int node, int val) {
    dn;
    if (val == 1) {
        n.lc = n.lc0;
        n.val = 1;
    }
    if (val == -1) {
        n.lc = -1;
        n.val = -1;
    }
}

void push(int node) {
    dn;
    addval(n.l, n.val);
    addval(n.r, n.val);
    n.val = 0;
}

void segval(int node, int L, int R, int v) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return;
    if (L <= n.L && n.R <= R) {
        addval(node, v);
        return;
    }
    push(node);
    segval(n.l, L, R, v);
    segval(n.r, L, R, v);
    relax(node);
}

vi te[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, q;
    cin >> n >> q;
    vector<pair<int, pii> > e(n - 1);
    for (auto &[w, p]: e) {
        auto &[u, v] = p;
        cin >> u >> v >> w;
        --u; --v;
    }

    sort(all(e));
    forn(i, 2 * n - 1) par[i] = i;
    forn(i, n) R[i] = i, we[i] = -1;

    int V = n;

    for (auto [w, p]: e) {
        auto [u, v] = p;
        u = root(u);
        v = root(v);
        int Z = V++;
//        cerr << R[u] << ' ' << R[v] << ' ' << Z << '\n';
        up[0][R[u]] = up[0][R[v]] = up[0][Z] = Z;
        te[Z] = {R[u], R[v]};
//        h[Z] = h[R[u]] - 1;
        par[v] = u;
        R[u] = Z;
        we[Z] = w;
    }

    ford(v, V) for (int u: te[v]) h[u] = h[v] + 1;

//    forn(v, V) cerr << up[0][v] << ' ';
//    cerr << '\n';

    forn(j, LOG) forn(v, V) up[j + 1][v] = up[j][up[j][v]];

    int node = buildTree(0, n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 3) {
            int v;
            cin >> v;
            --v;
            int y = lca(v, t[node].lc);
//            cerr << t[node].lc << ", Y = " << y << '\n';
            cout << we[y] << '\n';
        } else {
            int L, R;
            cin >> L >> R;
            --L;
            segval(node, L, R, type == 1 ? 1 : -1);
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}