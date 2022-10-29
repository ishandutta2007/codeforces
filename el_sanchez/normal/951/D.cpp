#include <bits/stdc++.h>
#define forn(i,n) for (int i = 0; i < (n); ++i)
#define forab(i,a,b) for (int i = (a); i < (b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define X first
#define Y second
#define db(x) cout << #x << " = " << x << '\n'

#ifdef LOCAL
    #define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
    #define eprintf(args...) ;
#endif

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ipair;
typedef pair<ll, ll> lpair;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-9;

const int D = 19;
const int N = 500179;

struct DSU {
    int p[N];
    DSU() {
        memset(p, -1, sizeof(p));
    }
    int get(int x) {
        return p[x] == -1 ? x : p[x] = get(p[x]);
    }
    bool merge(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y)
            return false;
        p[x] = y;
        return 1;
    }
} dsu;

int n, k, m;
vector<ipair> e[N];

struct LEdge {
    int x, y, c;
};
vector<LEdge> les;

int dep[N];
int dp[N][D];
int dpv[N][D];
bool po[N];

void dfs1(int v, int p = -1, int cdep = 0, bool cpo = false) {
    po[v] = cpo;
    dep[v] = cdep;
    dp[v][0] = (p == -1 ? 0 : p);
    for (int i = 1; i < D; ++i)
        dp[v][i] = dp[dp[v][i-1]][i-1];
    for (ipair nv : e[v])
        if (nv.X != p)
            dfs1(nv.X, v, cdep + 1, nv.Y);
}

ll ans = 0;
bool ainf = 0;

int lca(int x, int y) {
    if (dep[x] < dep[y])
        swap(x, y);
    int s = dep[x] - dep[y];
    for (int i = 0; i < D; ++i)
        if (s & (1 << i))
            x = dp[x][i];
    if (x == y)
        return x;
    for (int i = D - 1; i >= 0; --i) {
        int nx = dp[x][i];
        int ny = dp[y][i];
        if (nx != ny) {
            x = nx;
            y = ny;
        }
    }
    return dp[x][0];
}

void putVal(int x, int s, int a) {
    for (int i = 0; i < D; ++i)
        if (s & (1 << i)) {
            dpv[x][i] = min(dpv[x][i], a);
            x = dp[x][i];
        }
}

void solve() {
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 0; i < k; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        dsu.merge(x, y);
        e[x].push_back({y, 1});
        e[y].push_back({x, 1});
    }
    for (int i = 0; i < m; ++i) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        --x;
        --y;
        if (dsu.merge(x, y)) {
            e[x].push_back({y, 0});
            e[y].push_back({x, 0});
        } else {
            les.push_back({x, y, c});
        }
    }

    dfs1(0);

    memset(dpv, 0x3f, sizeof(dpv));
    for (LEdge const& le : les) {
        int z = lca(le.x, le.y);
        putVal(le.x, dep[le.x] - dep[z], le.c);
        putVal(le.y, dep[le.y] - dep[z], le.c);
    }

    for (int i = D - 1; i > 0; --i)
        for (int v = 0; v < n; ++v) {
            int v1 = dp[v][i-1];
            dpv[v][i-1] = min(dpv[v][i-1], dpv[v][i]);
            dpv[v1][i-1] = min(dpv[v1][i-1], dpv[v][i]);
        }

    for (int i = 0; i < n; ++i)
        if (po[i]) {
            if (dpv[i][0] == INF)
                ainf = 1;
            else
                ans += dpv[i][0];
        }

    if (ainf)
        cout << "-1\n";
    else
        cout << ans << "\n";
}

int main() {
#ifdef LOCAL
    assert(freopen("D.in", "r", stdin));
#endif

    solve();

    return 0;
}