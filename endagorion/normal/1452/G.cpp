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
vi e[maxn];

int dist[maxn];
int sz[maxn];
int ban[maxn];
int ans[maxn];

vi subt;

void dfs_sz(int v, int p) {
    if (ban[v]) {
        sz[v] = 0;
        return;
    }
    sz[v] = 1;
    subt.pb(v);
    for (int u: e[v]) {
        if (u == p) continue;
        dfs_sz(u, v);
        sz[v] += sz[u];
    }
}

void dfs_dans(int v, int p, int d, vi &dans) {
    if (ban[v]) return;
    if (dist[v] > d) uax(dans[min(dist[v] - d - 1, (int)dans.size() - 1)], dist[v]);
    for (int u: e[v]) if (u != p) dfs_dans(u, v, d + 1, dans);
}

void dfs_upd_dans(int v, int p, int d, vi &dans) {
    if (ban[v]) return; 
    uax(ans[v], dans[d]);
    for (int u: e[v]) if (u != p) dfs_upd_dans(u, v, d + 1, dans);
}


void dfs_centr(int v) {
    if (ban[v]) return;
    subt.clear();
    dfs_sz(v, -1);
    int C = -1;
    for (int u: subt) {
        bool is_centr = 2 * (sz[v] - sz[u]) <= sz[v];
        for (int w: e[u]) {
            if (sz[w] > sz[u]) continue;
            is_centr &= 2 * sz[w] <= sz[v];
        }
        if (is_centr) C = u;
    }
//    cerr << C << ": ";
//    for (int x: subt) cerr << x << ' ';
//    cerr << '\n';
    vi dans(subt.size() + 1);
    dfs_dans(C, -1, 0, dans);
    ford(i, dans.size() - 1) uax(dans[i], dans[i + 1]);
//    for (int x: dans) cerr << x << ' ';
//    cerr << '\n';
    dfs_upd_dans(C, -1, 0, dans);

    ban[C] = 1;
    for (int u: e[C]) dfs_centr(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }

    int k;
    cin >> k;
    vi q(k);
    for (int &x: q) cin >> x, --x;
    forn(i, n) dist[i] = 1e9;
    for (int x: q) dist[x] = 0;
    forn(cur, q.size()) {
        int v = q[cur];
        for (int u: e[v]) {
            if (dist[u] < 1e8) continue;
            dist[u] = dist[v] + 1;
            q.pb(u);
        }
    }


    dfs_centr(0);
    forn(i, n) cout << ans[i] << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}