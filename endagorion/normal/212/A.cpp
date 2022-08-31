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

struct TEdge {
    int x, col;
};

const int maxn = 401, maxt = 201;

vector<TEdge> edges;
vi e[maxn];
int deg[maxn][maxt];

int n, m, k, t;
int vis[maxn];

bool dfs(int v, int c1, int c2) {
    if (deg[v][c1] < deg[v][c2]) return true;
    if (vis[v]) return false;
    vis[v] = 1;
    for (int eid: e[v]) {
        auto &ee = edges[eid];
        if (ee.col != c1) continue;
        int u = v ^ ee.x;
        if (dfs(u, c2, c1)) {
            --deg[v][c1];
            --deg[u][c1];
            ee.col = c2;
            ++deg[v][c2];
            ++deg[u][c2];
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> m >> k >> t;
    forn(i, k) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        y += n;
        edges.pb({x ^ y, 0});
        e[x].pb(i);
        e[y].pb(i);
        ++deg[x][0];
        ++deg[y][0];
    }

    forn(v, n + m) {
        while (1) {
            int cmin = min_element(deg[v], deg[v] + t) - deg[v];
            int cmax = max_element(deg[v], deg[v] + t) - deg[v];
            if (deg[v][cmax] - deg[v][cmin] <= 1) break;
            forn(i, n + m) vis[i] = 0;
            if (!dfs(v, cmax, cmin)) {
                cerr << v << ' ' << cmax << ' ' << cmin << ' ' << deg[v][cmax] << ' ' << deg[v][cmin] << '\n';
                forn(i, k) cerr << edges[i].col << ' ';
                cerr << '\n';
                assert(false);
            }
        }
    }

    int ans = 0;
    forn(v, n + m) {
        int cmin = min_element(deg[v], deg[v] + t) - deg[v];
        int cmax = max_element(deg[v], deg[v] + t) - deg[v];
        int dmin = deg[v][cmin], dmax = deg[v][cmax];
        assert(dmax - dmin <= 1);
        ans += dmax - dmin;
    }
    cout << ans << '\n';
    forn(i, k) cout << edges[i].col + 1 << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}