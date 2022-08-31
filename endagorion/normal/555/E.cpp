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

const int MAXN = 210000;
vector<pii> e[MAXN];
vi ce[MAXN];
int vis[MAXN];
int dup[MAXN], tin[MAXN];
int comp[MAXN], ccomp[MAXN];
int tt = 0, cs = 0, ccs = 0;
vi st;

void dfs(int v, int p) {
    if (vis[v]) return;
    tin[v] = tt++;
    vis[v] = 1;
    dup[v] = tin[v];
    ccomp[v] = ccs;
    st.pb(v);
    for (pii w: e[v]) {
        if (w.se == p) continue;
        int u = w.fi;
        if (vis[u] == 0) {
            dfs(u, w.se);
            uin(dup[v], dup[u]);
        } else if (vis[u] == 1) {
            uin(dup[v], tin[u]);
        }
        if (dup[u] > tin[v]) {
            while (st.back() != u) {
                comp[st.back()] = cs;
                st.pop_back();
            }
            comp[u] = cs;
            st.pop_back();
            ++cs;
        }
    }
    vis[v] = 2;
}

const int LOG = 20;

int par[MAXN], h[MAXN];
int up[LOG + 1][MAXN];
int qu[MAXN], qd[MAXN];

void cdfs(int v, int p) {
    vis[v] = 1;
    par[v] = p;
    for (int u: ce[v]) {
        if (u == p || vis[u]) continue;
        h[u] = h[v] + 1;
        cdfs(u, v);
    }
}

int jump(int v, int h) {
    ford(k, LOG) {
        if ((1 << k) <= h) {
            h -= (1 << k);
            v = up[k][v];
        }
    }
    return v;
}

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    u = jump(u, h[u] - h[v]);
    if (u == v) return u;
    ford(k, LOG) {
        if (up[k][u] != up[k][v]) {
            u = up[k][u];
            v = up[k][v];
        }
    }
    if (par[u] != par[v]) return -1;
    return par[u];
}

void dfs_prop(int v, int p) {
    vis[v] = 1;

    for (int u: ce[v]) {
        if (u == p || vis[u]) continue;
        dfs_prop(u, v);
        uax(qu[v], qu[u] - 1);
        uax(qd[v], qd[u] - 1);
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

    int N, M, Q;
    cin >> N >> M >> Q;
    forn(i, M) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        e[x].pb(mp(y, i));
        e[y].pb(mp(x, i));
    }
    forn(i, N) {
        if (vis[i]) continue;
        dfs(i, -1);
        while (!st.empty()) {
            comp[st.back()] = cs;
            st.pop_back();
        }
        ++cs;
    }
    cerr << cs << '\n';
    forn(i, N) for (auto v: e[i]) {
        if (comp[i] != comp[v.fi]) ce[comp[i]].pb(comp[v.fi]);
    }
    forn(i, cs) vis[i] = 0;
    forn(i, cs) {
        if (!vis[i]) cdfs(i, i);
    }
    forn(i, cs) up[0][i] = par[i];
    forn(k, LOG) forn(i, cs) up[k + 1][i] = up[k][up[k][i]];

    forn(q, Q) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        x = comp[x]; y = comp[y];
        if (x == y) continue;
        int w = lca(x, y);
        if (w == -1) {
            cout << "No\n";
            return 0;
        }
        uax(qu[x], h[x] - h[w]);
        uax(qd[y], h[y] - h[w]);
    }
    forn(i, cs) vis[i] = 0;
    forn(i, cs) {
        if (!vis[i]) dfs_prop(i, i);
    }
    bool ok = true;
    forn(i, cs) ok &= !qu[i] || !qd[i];
    cout << (ok ? "Yes" : "No") << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}