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
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int MAXN = 200001;
int val[MAXN];
vi vin[2][MAXN];
int vis[MAXN], inc[MAXN];
int w = -1;

vector<pii> e[MAXN];

int valueof(int v, int i) {
    forn(x, 2) for (int j: vin[x][i]) if (j == v) return x;
    assert(false);
}

void dfs_sat(int v) {
    vis[v] = 2;
    for (pii p: e[v]) {
        int u = p.fi;
        if (vis[u]) continue;
        val[p.se] = valueof(u, p.se);
        dfs_sat(u);
    }
}

bool dfs_cycle(int v, int pid, vi &vv, vector<pii> &cycle) {
    if (vis[v] == 2) return false;
    if (vis[v] == 1) {
        w = v;
        inc[v] = 1;
        return true;
    }
    vv.pb(v);
    vis[v] = 1;
    for (pii p: e[v]) {
        int u = p.fi, id = p.se;
        if (id == pid) continue;
        if (dfs_cycle(u, id, vv, cycle)) {
            if (w != -1) {
                inc[v] = 1;
                cycle.pb(p);
            }
            if (v == w) w = -1;
            return true;
        }
    }
    vis[v] = 2;
    return false;
}

void dfs_csat(int v, int pid) {
    vis[v] = 2;
    for (pii p: e[v]) {
        int u = p.fi, id = p.se;
        if (vis[u] || id == pid || inc[u]) continue;
        val[id] = valueof(u, id);
        dfs_csat(u, id);
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

    int N, M;
    cin >> N >> M;
    forn(i, M) val[i] = -2;
    forn(i, N) {
        int s;
        cin >> s;
        forn(j, s) {
            int x;
            cin >> x;
            int v = x > 0;
            x = abs(x) - 1;
            if (val[x] == -2) val[x] = v;
            else if (val[x] >= 0 && val[x] != v) val[x] = -1;
            vin[v][x].pb(i);
        }
    }

    forn(i, M) {
        if (val[i] != -1) continue;
        forn(j, 2) e[vin[j][i][0]].pb(mp(vin[j ^ 1][i][0], i));
    }

    forn(i, M) {
        if (val[i] >= 0) {
            for (int x: vin[val[i]][i]) dfs_sat(x);
        }
    }

    bool ok = true;
    forn(i, N) {
        if (vis[i]) continue;
        vi vv;
        vector<pii> cycle;
        if (!dfs_cycle(i, -1, vv, cycle)) {
            ok = false;
            break;
        }
        for (pii p: cycle) {
            val[p.se] = valueof(p.fi, p.se);
        }
        for (int v: vv) vis[v] = 0;
        for (int v: vv) {
            if (!inc[v]) continue;
            dfs_csat(v, -1);
        }
    }
    if (!ok) cout << "NO\n";
    else {
        cout << "YES\n";
        forn(i, M) {
            if (val[i] < 0) val[i] = 0;
            cout << val[i];
        }
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}