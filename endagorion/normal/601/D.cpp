#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

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

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxt = 500000;
int nxt[maxt][26];
vi vs[maxt];
string s;
int tc = 2;

int c[maxt];
vector<pii> e[maxt];

int get_nxt(int v, int c) {
    if (!nxt[v][c]) nxt[v][c] = tc++;
    return nxt[v][c];
}

const int LOG = 20;
int up[LOG + 1][maxt];
int dp[maxt], d[maxt];

void dfs(int v, int p, int tv) {
    vs[tv].pb(v);
    for (pii w: e[v]) {
        int u = w.fi, c = w.se;
        if (u == p) continue;
//        cerr << v << ' ' << u << ' ' << c << ' ' << get_nxt(tv, c) << '\n';
        up[0][u] = v;
        d[u] = d[v] + 1;
        dfs(u, v, get_nxt(tv, c));
    }
}

int jmp(int v, int h) {
    ford(i, LOG) {
        if (h >= (1 << i)) {
            h -= 1 << i;
            v = up[i][v];
        }
    }
    return v;
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    u = jmp(u, d[u] - d[v]);
    if (u == v) return u;
    ford(i, LOG) {
        int uu = up[i][u], vv = up[i][v];
        if (uu != vv) u = uu, v = vv;
    }
    return up[0][u];
}

void dfs_col(int v, int p) {
    for (pii w: e[v]) {
        int u = w.fi;
        if (u == p) continue;
        dfs_col(u, v);
        dp[v] += dp[u];
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

    int n;
    cin >> n;
    forn(i, n) cin >> c[i];
    cin >> s;
    forn(i, n - 1) {
        int x, y;
        cin >> x >> y; --x; --y;
        e[x].pb(mp(y, s[y] - 'a'));
        e[y].pb(mp(x, s[x] - 'a'));
    }
    dfs(0, -1, 1);
    forn(i, LOG) forn(j, n) up[i + 1][j] = up[i][up[i][j]];
    forn(i, n) dp[i] = 1;
    forn(i, tc) {
        if (vs[i].empty()) continue;
        forn(j, vs[i].size() - 1) {
//            cerr << vs[i][j] << ' ' << vs[i][j + 1] << ' ' << lca(vs[i][j], vs[i][j + 1]) << '\n';
            --dp[lca(vs[i][j], vs[i][j + 1])];
        }
    }
    dfs_col(0, -1);
    int maxv = -1, cv = 0;
    forn(i, n) {
//        cerr << i << ' ' << dp[i] << '\n';
        if (c[i] + dp[i] > maxv) maxv = c[i] + dp[i], cv = 0;
        if (c[i] + dp[i] == maxv) ++cv;
    }
    cout << maxv << '\n' << cv << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}