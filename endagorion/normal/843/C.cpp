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

const int maxn = 210000;
vi e[maxn], ne[maxn];
int w[maxn];
int centr[maxn];
int n;
vector<tuple<int, int, int> > ops;

void dfsw(int v, int p) {
    w[v] = 1;
    centr[v] = 1;
    for (int u: e[v]) {
        if (u == p) continue;
        dfsw(u, v);
        w[v] += w[u];
        centr[v] &= 2 * w[u] <= n;
    }
    centr[v] &= 2 * w[v] >= n;
}

void add_nedge(int v, int u) {
//    cerr << v << ' ' << u << '\n';
    ne[v].pb(u);
    ne[u].pb(v);
}

vector<pii> dfs(int v, int p) {
    vector<pii> res;
    for (int u: e[v]) {
        if (u == p || centr[u]) continue;
        vector<pii> w = dfs(u, v);
        if (w.empty()) {
            //add_nedge()
            res.pb({u, u});
            continue;
        }
        ops.pb({v, u, w[0].se});
        //add_nedge(v, w[0].se);
        forn(i, w.size() - 1) {
            ops.pb({w[i].fi, u, w[i + 1].se});
            add_nedge(w[i].fi, w[i + 1].se);
        }
        add_nedge(w.back().fi, u);
        res.pb({w[0].se, u});
    }
    return res;
}

int dfs2(int v, int p) {
    int w = v;
    for (int u: ne[v]) {
        if (u == p) continue;
        ops.pb({v, u, w = dfs2(u, v)});
    }
    return w;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n;
    forn(i, n - 1) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        e[x].pb(y);
        e[y].pb(x);
    }
    dfsw(0, -1);
    forn(i, n) if (centr[i]) {
        vector<pii> w = dfs(i, -1);
        for (auto p: w) add_nedge(i, p.fi);
        dfs2(i, -1);
    }
    cout << ops.size() << '\n';
    for (auto w: ops) {
        int x, y, z;
        tie(x, y, z) = w;
        cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}