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

const int maxn = 210000;
vector<pii> e[maxn], re[maxn];
int vis[maxn];
int comp[maxn];
i64 p[maxn], G[maxn];

i64 GCD(i64 a, i64 b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

vi ord;

void dfs0(int v) {
    if (vis[v]) return;
    vis[v] = 1;
    for (auto [u, l]: e[v]) dfs0(u);
    ord.pb(v);
}

void dfs_re(int v, int c) {
    if (comp[v] != -1) return;
//    cerr << v << ' ' << c << '\n';
    comp[v] = c;
    for (auto [u, l]: re[v]) {
        dfs_re(u, c);
    }
}

void dfs_G(int v, int c, i64 w) {
    if (comp[v] != c) return;
    if (vis[v]) {
        G[c] = GCD(G[c], abs(w - p[v]));
        return;
    }
    p[v] = w;
    vis[v] = 1;
    for (auto [u, l]: e[v]) dfs_G(u, c, w + l);
    for (auto [u, l]: re[v]) dfs_G(u, c, w - l);
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
    forn(i, m) {
        int u, v, l;
        cin >> u >> v >> l;
        --u; --v;
        e[u].pb({v, l});
        re[v].pb({u, l});
    }

    forn(i, n) dfs0(i);
    
    reverse(all(ord));
    forn(i, n) comp[i] = -1, vis[i] = 0;
    int C = 0;
    for (int v: ord) {
        if (comp[v] != -1) continue;
        dfs_re(v, C);
        dfs_G(v, C, 0);
        ++C;
    }

//    forn(i, n) cerr << G[comp[i]] << '\n';

    int q;
    cin >> q;
    while (q--) {
        int v, s, t;
        cin >> v >> s >> t;
        --v;
        cout << (s % GCD(G[comp[v]], t) == 0 ? "YES" : "NO") << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}