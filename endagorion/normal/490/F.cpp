#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T>
bool uin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const int MAXN = 7000;
int tin[MAXN], tout[MAXN];
int maxd[2][MAXN];
int lca[MAXN][MAXN];
int a[MAXN], par[MAXN];
int N;

int tt = 0;

vi e[MAXN];

void dfs(int v, int p) {
    par[v] = p;
    tin[v] = tt++;
    for (int u: e[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
    tout[v] = tt++;
}                       

int get_max(int v, int k) {
    int &res = maxd[k][v];
    if (res != -1) return res;
    res = 1;
    forn(i, N) {
        if (tin[i] > tin[v] && tout[i] < tout[v] && (k ? a[i] < a[v] : a[i] > a[v])) uax(res, get_max(i, k) + 1);
    }
    return res;
}

int get_lca(int v, int u) {
    if (tin[v] > tin[u]) swap(v, u);
    int &res = lca[v][u];
    if (res != -1) return res;
    if (tout[u] <= tout[v]) return res = v;
    return res = get_lca(par[v], u);
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> N;
    forn(i, N) cin >> a[i];
    forn(i, N) forn(j, 2) maxd[j][i] = -1;
    forn(i, N - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }
    forn(i, N) forn(j, N) lca[i][j] = -1;
    dfs(0, -1);
    int ans = 0;
    forn(u, N) forn(v, N) {
        if (tin[u] <= tin[v] && tout[v] <= tout[u]) continue;
        if (tin[v] <= tin[u] && tout[u] <= tout[v]) continue;
        if (a[u] >= a[v]) continue;
        int res = get_max(v, 0) + get_max(u, 1);
        int w = get_lca(u, v);
        if (a[w] > a[u] && a[w] < a[v]) ++res;
//        cerr << u << ' ' << v << ' ' << w << ' ' << res << '\n';
        uax(ans, res);
    }
    forn(i, N) forn(j, 2) uax(ans, get_max(i, j));
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}