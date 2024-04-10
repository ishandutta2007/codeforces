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
string f[maxn];
int a[maxn];
vi byCol[maxn];
vi e[maxn], re[maxn];
int mark[maxn];

int n, m;

int index(pii p) {
    return p.fi * m + p.se;
}

void add_edge(pii p, pii q) {
    int a = index(p), b = index(q);
    e[a].pb(b);
    re[b].pb(a);
}

vi ord;
int vis[maxn], comp[maxn];
int intc[maxn];

void dfs(int v) {
    if (vis[v]) return;
    vis[v] = 1;
    for (int u: e[v]) dfs(u);
    ord.pb(v);
}

void dfs_re(int v, int C) {
    if (vis[v]) return;
    comp[v] = C;
    vis[v] = 1;
    for (int u: re[v]) dfs_re(u, C);
}

void dfs_re2(int v) {
    if (vis[v]) return;
    vis[v] = 1;
    intc[comp[v]] = 1;
    for (int u: re[v]) dfs_re2(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> m;
    forn(i, n) cin >> f[i];
    forn(i, m) cin >> a[i];
    forn(i, n) forn(j, m) if (f[i][j] == '#') byCol[j].pb(i);
    forn(i, n) forn(j, m) {
        if (f[i][j] == '.') continue;
        if (i > 0 && f[i - 1][j] == '#') add_edge(mp(i, j), mp(i - 1, j));
        fore(z, -1, 1) {
            int nj = j + z;
            if (nj < 0 || nj >= m) continue;
            auto it = z == 0 ? upper_bound(all(byCol[nj]), i) : lower_bound(all(byCol[nj]), i);
            if (it != byCol[nj].end()) add_edge(mp(i, j), mp(*it, nj));
        }
    }

    forn(j, m) ford(i, n) {
        if (f[i][j] == '.' || !a[j]) continue;
        --a[j];
        mark[index(mp(i, j))] = 1;
    }

    forn(i, n * m) if (!vis[i]) dfs(i);
    forn(i, n * m) vis[i] = 0;
    reverse(all(ord));
    int C = 0;
    for (int v: ord) {
        if (!vis[v]) dfs_re(v, C++);
    }
    forn(i, n * m) vis[i] = 0;
    forn(i, n * m) if (mark[i]) dfs_re2(i);

    forn(i, n * m) for (int j: e[i]) if (comp[i] != comp[j]) intc[comp[j]] = 0;
    int ans = 0;
    forn(i, C) if (intc[i]) ++ans;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}