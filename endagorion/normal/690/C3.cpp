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

const int maxn = 210000;
const int LOG = 20;
vi e[maxn];
int vis[maxn], dist[maxn];
int up[LOG + 1][maxn];
int d[maxn];

void dfs0(int v, int p) {
    up[0][v] = p;
    for (int u: e[v]) {
        if (u == p) continue;
        d[u] = d[v] + 1;
        dfs0(u, v);
    }
}

int jump(int v, int k) {
    ford(i, LOG) {
        if (k >= (1 << i)) {
            v = up[i][v];
            k -= 1 << i;
        }
    }
    return v;
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    u = jump(u, d[u] - d[v]);
    if (u == v) return u;
    ford(i, LOG) {
        int uu = up[i][u], vv = up[i][v];
        if (uu != vv) u = uu, v = vv;
    }
    return up[0][u];
}

int find_dist(int u, int v) {
    return d[u] + d[v] - 2 * d[lca(u, v)];
}

int moveto(int u, int v) {
    int w = lca(u, v);
    if (u == w) return jump(v, d[v] - d[u] - 1);
    else return up[0][u];
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
        int p;
        cin >> p;
        --p;
        e[p].pb(i + 1);
        e[i + 1].pb(p);
    }
    dfs0(0, 0);
    forn(i, LOG) forn(j, n) up[i + 1][j] = up[i][up[i][j]];
    int c1 = 0, c2 = 0, r = 0, ans = 0;
    for1(i, n - 1) {
        int d1 = find_dist(i, c1), d2 = find_dist(i, c2);
        if (d1 > r || d2 > r) {
            if (c1 == c2) {
                c2 = moveto(c1, i);
                ++r;
            } else {
                if (d1 > d2) c1 = c2;
                else c2 = c1;
            }
            ++ans;
        }
        cout << ans << ' ';
    }
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}