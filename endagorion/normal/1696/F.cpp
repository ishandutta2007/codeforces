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

const int maxn = 101;
int eq[maxn][maxn][maxn];
int dist[maxn][maxn];
int par[maxn];

int root(int v) {
    return par[v] == v ? v : par[v] = root(par[v]);
}

int n;
int vis[maxn];

vi e[maxn];

bool add_edge(int v, int u) {
//    cerr << "Add " << v << ' ' << u << '\n';
    if (root(v) == root(u)) return false;
    e[v].pb(u);
    e[u].pb(v);
    par[root(v)] = root(u);
    return true;
}

bool dfs(int v, int p) {
    if (vis[v]) return false;
    vis[v] = 1;
    forn(u, n) {
        if (u == v || u == p) continue;
        if (!eq[p][u][v]) continue;
        if (!add_edge(v, u) || !dfs(u, v)) return false;
    }
    return true;
}

void dfs_dist(int v, int p, int s, int d) {
    dist[v][s] = d;
    for (int u: e[v]) {
        if (u == p) continue;
        dfs_dist(u, v, s, d + 1);
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
    while (T--) {
        cin >> n;
        forn(i, n - 1) fore(j, i + 1, n - 1) {
            string s;
            cin >> s;
            forn(k, n) eq[i][j][k] = eq[j][i][k] = s[k] - '0';
        }
        bool done = false;
        
        for1(v, n - 1) {
//            cerr << "Try " << v << '\n';
            forn(i, n) par[i] = i;
            forn(i, n) vis[i] = 0;
            forn(i, n) e[i].clear();
            add_edge(0, v);
            if (!dfs(0, v) || !dfs(v, 0)) continue;
            forn(v, n) forn(u, n) dist[v][u] = 1e9;
            forn(v, n) dfs_dist(v, -1, v, 0);
            bool ok = true;
            forn(i, n) forn(j, n) ok &= dist[i][j] < 1e8;
//            if (!ok) cerr << "Not connected\n";
            forn(i, n) forn(j, n) forn(k, n) if (ok && i != j && (dist[i][k] == dist[j][k]) != (eq[i][j][k] == 1)) ok = false;
            if (!ok) continue;
            cout << "Yes\n";
            forn(i, n) for (int j: e[i]) if (i < j) cout << i + 1 << ' ' << j + 1 << '\n';
            done = true;
            break;
        }
        if (!done) cout << "No\n";
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}