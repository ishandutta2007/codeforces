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

const int maxn = 101;
vi e[maxn][maxn];
int vis[maxn], w[maxn], maxch[maxn];

int n;
int forb;

void dfs(int t, int v, vi &path) {
    if (vis[v]) return;
    vis[v] = 1;
    path.pb(v);
    for (int u: e[t][v]) dfs(t, u, path);
}

vvi comps(int t) {
    vvi res;
    forn(i, n) vis[i] = 0;
    forn(i, n) {
        if (vis[i]) continue;
        vi p;
        dfs(t, i, p);
        res.pb(p);
    }
    return res;
}

map<vi, int> types;

int getType(vi v) {
    sort(all(v));
    if (!types.count(v)) {
        int z = types.size();
        types[v] = z;
    }
    return types[v];
}

int dfsType(int t, int v, int p) {
    vi z;
    if (v == forb) return getType(z);
    for (int u: e[t][v]) {
        if (u == forb || u == p) continue;
        z.pb(dfsType(t, u, v));
    }
    return getType(z);
}

void dfsw(int t, int v, int p, vi &path) {
    w[v] = 1;
    maxch[v] = 0;
    path.pb(v);
    if (v == forb) return;
    for (int u: e[t][v]) {
        if (u == p || u == forb) continue;
        dfsw(t, u, v, path);
        w[v] += w[u];
        uax(maxch[v], w[u]);
    }
}

vi getCentroids(int t, int v) {
    vi path;
    dfsw(t, v, -1, path);
    vi centrs;
    for (int u: path) {
        if (2 * maxch[u] <= w[v] && 2 * (w[v] - w[u]) <= w[v]) centrs.pb(u);
    }
    assert(centrs.size() <= 2);
    for (int u: path) vis[u] = 1;
    return centrs;
}

int getForestType(int t) {
    forn(i, n) vis[i] = 0;
    vi v;
    forn(i, n) {
        if (vis[i]) continue;
        vi c = getCentroids(t, i);
        int T = 1e9;
        for (int u: c) {
            uin(T, dfsType(t, u, -1));
        }
        v.pb(T);
    }
    return getType(v);
}

int ZZ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int Q;
    cin >> Q;
    while (Q-->0) {
        types.clear();
        cin >> n >> n;
        forn(i, n) forn(j, n) e[i][j].clear();
        forn(i, n) {
            int m;
            cin >> m;
            forn(j, m) {
                int x, y;
                cin >> x >> y;
                --x; --y;
                e[i][x].pb(y);
                e[i][y].pb(x);
            }
        }

        forb = -1;
        vi Z;
        forn(i, n) Z.pb(getForestType(i));
        ZZ = getType(Z);

        int b = 0;
        while (comps(b).size() != 2) ++b;
        vvi c = comps(b);
        if (c[0].size() != 1) swap(c[0], c[1]);
        assert(c[0].size() == 1);
        int X = c[0][0];
        bool done = false;
        forn(i, n) {
            if (i == X) continue;
            e[b][i].pb(X);
            e[b][X].pb(i);

            vi Y;
            forn(i, n) {
                forb = i;
                Y.pb(getForestType(b));
            }
            if (getType(Y) == ZZ) {
                cout << "YES\n";
                forn(i, n) for (int j: e[b][i]) if (i < j) cout << i + 1 << ' ' << j + 1 << '\n';
                done = true;
                break;
            }
            e[b][i].pop_back();
            e[b][X].pop_back();
        }
        if (!done) cout << "NO\n";
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}