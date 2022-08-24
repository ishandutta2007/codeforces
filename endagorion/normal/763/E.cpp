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

const int maxn = 110000;
vi e[maxn];
int comp[maxn];

int n, k, m;

int BL, BR;

void dfs(int v, int c) {
    if (comp[v] != -1) return;
    comp[v] = c;
    for (int u: e[v]) {
        if (u < BL || u >= BR) continue;
        dfs(u, c);
    }
}

int constrained_dfs(int L, int R) {
    assert(L >= 0 && R <= n);
    fore(i, L, R - 1) comp[i] = -1;
    int C = 0;
    BL = L; BR = R;
    fore(i, L, R - 1) {
        if (comp[i] == -1) dfs(i, C++);
    }
    return C;
}

vvi ge;

const int D = 5;

struct TRes {
    int prefc[D], sufc[D];
    int cb;
    int inside;

    bool is_none() const {
        return cb < 0;
    }
};

TRes none;

TRes init(int L) {
    TRes res;
    res.inside = 0;
    res.cb = constrained_dfs(L, L + D + 1);
    forn(i, D) res.prefc[i] = comp[L + i];
    forn(i, D) res.sufc[i] = comp[L + i + 1];
    return res;
}

void smol_dfs(int v, int c) {
    if (comp[v] != -1) return;
    comp[v] = c;
    for (int u: ge[v]) smol_dfs(u, c);
}

TRes operator+(const TRes &a, const TRes &b) {
    if (a.is_none()) return b;
    if (b.is_none()) return a;
    TRes res;
    res.inside = a.inside + b.inside;
    int V = a.cb + b.cb;
    ge = vvi(V, vi());
    forn(i, D) {
        int u = a.sufc[i], v = b.prefc[i] + a.cb;
        ge[u].pb(v);
        ge[v].pb(u);
    }
    forn(i, D) res.prefc[i] = res.sufc[i] = -1;
    forn(i, V) comp[i] = -1;
    int C = 0;
    forn(i, 5) {
        int v = a.prefc[i];
        if (comp[v] != -1) continue;
        smol_dfs(v, C++);
    }
    forn(i, 5) {
        int v = b.sufc[i] + a.cb;
        if (comp[v] != -1) continue;
        smol_dfs(v, C++);
    }
    res.cb = C;
    forn(i, 5) {
        res.prefc[i] = comp[a.prefc[i]];
        res.sufc[i] = comp[b.sufc[i] + a.cb];
    }
    forn(v, V) {
        if (comp[v] != -1) continue;
        ++res.inside;
        smol_dfs(v, C++);
    }
    return res;
}

struct TNode {
    int L, R;
    int l, r;
    TRes res;
};

TNode t[2 * maxn];
int tc = 0;

#define dn TNode &n = t[node]

void relax(int node) {
    dn;
    n.res = t[n.l].res + t[n.r].res;
}

int buildTree(int L, int R) {
    if (L >= R) return -1;
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {}};
    if (R - L == 1) n.res = init(L);
    else {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        relax(node);
    }
    auto &res = n.res;
/*    cerr << n.L << ' ' << n.R << ": " << res.cb << ' ' << res.inside << '\n';
    forn(i, 5) cerr << res.prefc[i] << ' ';
    cerr << '\n';
    forn(i, 5) cerr << res.sufc[i] << ' ';
    cerr << '\n';*/
    return node;
}

TRes query(int node, int L, int R) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return none;
    if (L <= n.L && n.R <= R) return n.res;
    auto res = query(n.l, L, R) + query(n.r, L, R);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    none.cb = -1;

    cin >> n >> k >> m;
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }

    int root = buildTree(0, n - D);

    int q;
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        --L;
        if (R - L <= D) cout << constrained_dfs(L, R) << '\n';
        else {
            auto res = query(root, L, R - D);
            cout << res.cb + res.inside << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}