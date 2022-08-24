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

int n, m;
int cost[2];
const int maxn = 71;
vi e[2][maxn];
int c0[maxn];
int vis[maxn];
int dist[maxn][1 << 17];

void dfs0(int v, vi &comp) {
    if (vis[v]) return;
    vis[v] = 1;
    comp.pb(v);
    for (int u: e[0][v]) dfs0(u, comp);
}

bool visit(int &mask, int v) {
    if (c0[v] == -1) return true;
    if ((mask >> c0[v]) & 1) return false;
    mask |= 1 << c0[v];
    return true;
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
    forn(i, 2) cin >> cost[i];
    forn(i, m) {
        int u, v, c;
        cin >> u >> v >> c;
        --u; --v;
        e[c == cost[0] ? 0 : 1][u].pb(v);
        e[c == cost[0] ? 0 : 1][v].pb(u);
    }
    forn(i, n) c0[i] = -1;
    int C = 0;
    forn(i, n) {
        if (vis[i]) continue;
        vi comp;
        dfs0(i, comp);
        for (int u: comp) {
            vi ne;
            for (int v: e[1][u]) if (!count(all(comp), v)) ne.pb(v);
            e[1][u] = ne;
        }
//        cerr << i << ' ' << comp.size() << '\n';
        if (comp.size() >= 4) {
            for (int v: comp) c0[v] = C;
            ++C;
        }
    }

    assert(C <= 17);
    int mask = 0;
    visit(mask, 0);
    forn(i, n) forn(mm, 1 << C) dist[i][mm] = 1e9;
    dist[0][mask] = 0;
    priority_queue<pair<int, pii> > q;
    q.push({0, {0, mask}});
    while (!q.empty()) {
        auto w = q.top();
        q.pop();
        int v = w.se.fi, mask = w.se.se;
        if (w.fi != -dist[v][mask]) continue;
        for (int u: e[0][v]) {
            int cc = dist[v][mask] + cost[0];
            if (uin(dist[u][mask], cc)) q.push({-dist[u][mask], {u, mask}});
        }
        for (int u: e[1][v]) {
            int nmask = mask;
            if (!visit(nmask, u)) {
                continue;
            }
            int cc = dist[v][mask] + cost[1];
            if (uin(dist[u][nmask], cc)) q.push({-dist[u][nmask], {u, nmask}});
        }
    }

    vi ans(n, 1e9);
    forn(v, n) forn(mask, 1 << C) uin(ans[v], dist[v][mask]);
    forn(i, n) cout << ans[i] << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}