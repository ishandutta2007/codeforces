#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
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
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 110000, BUBEN = 300;
vi e[maxn];
int par[maxn], sz[maxn];
vi d[maxn];
vi64 ps[maxn];
int down[maxn], dp[maxn], rad[maxn];

int root(int x) {
    if (x == par[x]) return x;
    return par[x] = root(par[x]);
}

void unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    par[y] = x;
}

void dfs0(int v, int p) {
    for (int u: e[v]) {
        if (u == p) continue;
        dfs0(u, v);
        uax(down[v], down[u] + 1);
    }
}

void upd(int *v, int x) {
    forn(i, 2) if (x > v[i]) swap(x, v[i]);
}

int exc(int *v, int x) {
    forn(i, 2) {
        if (v[i] == x) x = -1;
        else return v[i];
    }
    return -1e9;
}

void dfs_up(int v, int p, int dup, vi &res) {
    dp[v] = max(down[v], dup);
    res.pb(dp[v]);
    int ds[2] = {};
    forn(i, 2) ds[i] = -1e9;
    for (int u: e[v]) {
        if (u == p) continue;
        upd(ds, down[u]);
    }

    for (int u: e[v]) {
        if (u == p) continue;
        dfs_up(u, v, max(dup, exc(ds, down[u]) + 1) + 1, res);
    }
}

map<pii, double> memo;

double pair_up(int i, int j) {
    if (sz[i] < sz[j]) swap(i, j);
    int L = max(d[i].back(), d[j].back());
    double ans = 0.0;
    int K = d[i].size();

    forn(k, d[j].size()) {
        int x = upper_bound(all(d[i]), L - d[j][k] - 1) - d[i].begin();
        ans += 1.0 * x * L + (ps[i][K] - ps[i][x]) + 1.0 * (K - x) * (d[j][k] + 1);
    }
    ans /= d[i].size(); ans /= d[j].size();
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m, q;
    cin >> n >> m >> q;
    forn(i, n) par[i] = i, sz[i] = 1;
    forn(i, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        e[x].pb(y); e[y].pb(x);
        unite(x, y);
    }

    forn(i, n) {
        if (par[i] != i) continue;
        dfs0(i, -1);
        dfs_up(i, -1, 0, d[i]);
        sort(all(d[i]));
        int K = d[i].size();
        ps[i].resize(K + 1);
        forn(j, K) ps[i][j + 1] = ps[i][j] + d[i][j];
    }

    forn(i, q) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        x = root(x); y = root(y);
        if (x == y) {
            cout << -1 << '\n';
            continue;
        }
        if (x > y) swap(x, y);
        if (!memo.count(mp(x, y))) memo[{x, y}] = pair_up(x, y);
        cout << memo[{x, y}] << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}