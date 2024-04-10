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
vi e[maxn];
int tin[maxn], tout[maxn];
int tord[maxn];
int up[maxn], vis[maxn];
int is_art[maxn];
int sgn[maxn];
int T = 0;
vi arts;

int n, m, s, t;

void dfs(int v, int p) {
    tin[v] = T++;
    tord[tin[v]] = v;
    up[v] = tin[v];
    vis[v] = 1;
    int ch = 0;

    for (int u: e[v]) {
        if (u == p) continue;
        if (vis[u] == 1) {
            uin(up[v], tin[u]);
            continue;
        }
        if (vis[u]) continue;
        ++ch;
        dfs(u, v);
        uin(up[v], up[u]);
        if (up[u] >= tin[v]) is_art[v] = 1;
    }
    if (p == -1) is_art[v] = ch > 1;
    if (is_art[v]) arts.pb(v);
//    cerr << v << ' ' << tin[v] << ' ' << up[v] << '\n';

    tout[v] = T;
    vis[v] = 2;
}

int ord[maxn];
int nxt[maxn], prv[maxn];
int el[maxn];
int O = 0;

void dfs_direct(int v, int p) {
    vis[v] = 1;
    for (int u: e[v]) {
        if (u == p) continue;
        if (vis[u]) continue;
        int w = tord[up[u]];
        assert(tin[w] < tin[u]);

        if (sgn[w] == 1) {
            int n = nxt[v];
            nxt[u] = n;
            prv[u] = v;
            nxt[v] = u;
            if (n != -1) prv[n] = u;
        } else {
            int p = prv[v];
            nxt[u] = v;
            prv[u] = p;
            prv[v] = u;
            if (p != -1) nxt[p] = u;
        }
        sgn[v] = -sgn[w];
        dfs_direct(u, v);
    }
    vis[v] = 2;
}

void solve() {
    cin >> n >> m >> s >> t;
//    cerr << n << ' ' << m << ' ' << s << ' ' << t << '\n';
    --s; --t;
    forn(i, n) e[i].clear();
    e[s].pb(t);
    vector<pii> oe;
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        oe.pb({u, v});
        if (set<int>({u, v}) == set<int>({s, t})) continue;
        e[u].pb(v);
        e[v].pb(u);
    }
    
    forn(v, n) vis[v] = is_art[v] = 0;
    arts.clear();

    T = 0;
    dfs(s, -1);
    if (!arts.empty()) {
        cout << "No\n";
        return;
    }

    sgn[s] = -1;
    forn(v, n) vis[v] = 0;
    forn(v, n) nxt[v] = prv[v] = -1;
    nxt[s] = t;
    prv[t] = s;
    vis[s] = 1;
    dfs_direct(t, s);

    int oi = 0;
    for (int v = s; v != -1; v = nxt[v]) ord[v] = oi++;
    assert(oi == n);

    cout << "Yes\n";
    for (auto [v, u]: oe) {
        if (ord[v] > ord[u]) swap(v, u);
        cout << v + 1 << ' ' << u + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    forn(ti, T) {
//        cerr << ti << '\n';
        solve();
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}