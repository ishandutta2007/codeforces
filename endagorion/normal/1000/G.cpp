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

const int maxn = 310000;
i64 a[maxn];
vector<pi64> e[maxn];

const i64 NONE = -1e18, INF = -1e17;

struct TState {
    int v;
    i64 cost;

    TState operator+(const TState &st) const {
        return {st.v, cost + st.cost};
    }
};

const int LOG = 20;
TState up[LOG + 1][maxn];
int h[maxn];
i64 downt[maxn], rt[maxn], upt[maxn], pe[maxn];

void dfs0(int v, int p) {
    up[0][v].v = p;
    up[0][v].cost += a[v];
    for (auto [u, c]: e[v]) {
        if (u == p) continue;
        h[u] = h[v] + 1;
        dfs0(u, v);
        rt[u] = max(0LL, downt[u] + a[u] - 2 * c);
//        cerr << "R " << u << ' ' << rt[u] << '\n';
        downt[v] += rt[u];
        pe[u] = c;
        up[0][u].cost -= rt[u] + pe[u];
    }
//    cerr << "D " << v << ' ' << downt[v] << '\n';
    up[0][v].cost += downt[v];
}

void dfs1(int v, int p) {
    for (auto [u, c]: e[v]) {
        if (u == p) continue;
        upt[u] = max(0LL, upt[v] + a[v] - 2 * c + downt[v] - rt[u]);
        dfs1(u, v);
    }
}

TState jmp(TState st, int h) {
    ford(k, LOG) {
        if (h < (1 << k)) continue;
        h -= 1 << k;
        st = st + up[k][st.v];
    }
    return st;
}

TState lca(int v, int u) {
    if (h[v] < h[u]) swap(v, u);
    TState sv = {v, 0}, su = {u, 0};
    sv = jmp(sv, h[v] - h[u]);
    if (sv.v == su.v) return sv + su;
    ford(k, LOG) {
        TState vv = sv + up[k][sv.v];
        TState uu = su + up[k][su.v];
        if (vv.v != uu.v) sv = vv, su = uu;
//        cerr << k << ' ' << sv.v << ' ' << sv.cost << ' ' << su.v << ' ' << su.cost << '\n';
    }
    return sv + su + up[0][sv.v] + up[0][su.v];
}

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
    forn(i, n) cin >> a[i];
    forn(i, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        e[u].pb({v, w});
        e[v].pb({u, w});
    }

    dfs0(0, 0);
//    forn(v, n) cerr << v << ' ' << up[0][v].v << ' ' << up[0][v].cost << '\n';
    dfs1(0, 0);
    forn(j, LOG) forn(v, n) up[j + 1][v] = up[j][v] + up[j][up[j][v].v];

    while (q--) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        TState st = lca(u, v);
//        cerr << st.v << ' ' << st.cost << '\n';
        i64 ans = st.cost + a[st.v] + downt[st.v] + upt[st.v];
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}