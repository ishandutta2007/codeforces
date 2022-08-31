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

const int MAXN = 200000;
const int LOG = 20;
int f[MAXN];

struct TResult {
    int l1, r1;
    int sum;
    bool f1;

    TResult(int l1, int r1, int sum, bool f1)
        : l1(l1)
        , r1(r1)
        , sum(sum)
        , f1(f1)
    {
    }

    TResult(int x = 1)
        : l1(x)
        , r1(x)
        , sum(0)
        , f1(x)
    {
    }

    TResult operator+(const TResult &res) const {
        int ll1 = l1, rr1 = res.r1;
        if (f1) ll1 += res.l1;
        if (res.f1) rr1 += r1;
        int ssum = sum + res.sum;
        if (!f1 && !res.f1) ssum += f[r1 + res.l1];
        return TResult(ll1, rr1, ssum, f1 && res.f1);
    }

    TResult sw() const {
        return TResult(r1, l1, sum, f1);
    }
};

struct TNode {
    int L, R;
    int left, right;
    TResult res;
    
    TNode(int L = -1, int R = -1)
        : L(L)
        , R(R)
        , left(0)
        , right(0)
        , res()
    {
    }
};

const int MAXT = 2000000;
TNode t[MAXT];
int tc = 1;

int buildTree(int L, int R) {
    int node = tc++;
    t[node] = TNode(L, R);
    TNode &n = t[node];
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.left = buildTree(L, M);
        n.right = buildTree(M, R);
        n.res = t[n.left].res + t[n.right].res; 
    }
    return node;
}

TResult query(int node, int L, int R) {
    TNode &n = t[node];
    if (max(L, n.L) >= min(R, n.R)) return TResult(0, 0, 0, true);
    if (L <= n.L && n.R <= R) return n.res;
    return query(n.left, L, R) + query(n.right, L, R);
}

int sset(int node, int i, int x) {
    if (i < t[node].L || i >= t[node].R) return node;
    int nnode = tc++;
    TNode &n = t[nnode];
    n = t[node];
    if (i == n.L && i + 1 == n.R) {
        n.res = TResult(x);
        return nnode;
    }
    n.left = sset(n.left, i, x);
    n.right = sset(n.right, i, x);
    n.res = t[n.left].res + t[n.right].res;
    return nnode;
}

vector<pii> e[MAXN];
int up[LOG + 1][MAXN], par[MAXN];
int sz[MAXN], root[MAXN], rpos[MAXN];
int h[MAXN];
vector<pii> tr[MAXN];

void dfs_build(int v, int p) {
    par[v] = p;
    sz[v] = 1;
    for (pii w: e[v]) {
        if (w.fi == p) continue;
        int u = w.fi;
        h[u] = h[v] + 1;
        dfs_build(u, v);
        sz[v] += sz[u];
    }
}

void dfs_sroot(int v, int p) {
    rpos[v] = 0;
    for (pii w: e[v]) {
        int u = w.fi;
        if (u == p) continue;
        root[u] = (2 * sz[u] >= sz[v] ? root[v] : u);
        dfs_sroot(u, v);
        if (root[u] == root[v]) rpos[v] = rpos[u] + 1;
    }
}

int get_up(int v, int d) {
    ford(i, LOG + 1) {
        if ((1 << i) <= d) {
            d -= (1 << i);
            v = up[i][v];
        }
    }
    return v;
}

int lca(int v, int u) {
    if (h[v] < h[u]) swap(v, u);
    v = get_up(v, h[v] - h[u]);
    if (v == u) return v;
    ford(i, LOG + 1) {
        if (up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    }
    return par[u];
}

int get_ver(int r, int w) {
    return (--lower_bound(all(tr[r]), mp(w, -1)))->se;
}

TResult hld_res(int v, int w, int d) {
    int r = root[v];
    int ver = get_ver(r, w);
    TResult res = query(ver, rpos[v], min(rpos[v] + d, rpos[r] + 1));
    int dd = d - (rpos[r] - rpos[v] + 1);
    if (dd > 0) res = res + hld_res(par[r], w, dd);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, Q;
    cin >> N >> Q;
    for1(i, N - 1) cin >> f[i];
    forn(i, N - 1) {
        int x, y, w;
        cin >> x >> y >> w;
        --x; --y;
        e[x].pb(mp(y, w));
        e[y].pb(mp(x, w));
    }

    dfs_build(0, 0);
    dfs_sroot(0, 0);
    forn(i, N) {
        if (root[i] == i) tr[i].pb(mp(0, buildTree(0, rpos[i] + 1)));
    }
    forn(i, N) up[0][i] = par[i];
    for1(i, LOG) forn(j, N) {
        up[i][j] = up[i - 1][up[i - 1][j]];
    }

    vector<pii> s;
    forn(x, N) {
        for (pii w: e[x]) {
            if (h[x] < h[w.fi]) continue;
            s.pb(mp(w.se, x));
        }
    }
    sort(all(s));
    for (pii ch: s) {
        int x = ch.se, w = ch.fi;
        int r = root[x];
        int tt = tr[r].back().se;
        tr[r].pb(mp(w, sset(tt, rpos[x], 0)));
    }

    forn(q, Q) {
        int x, y, l;
        cin >> x >> y >> l;
        --x; --y;
        int w = lca(x, y);
        TResult res = hld_res(x, l, h[x] - h[w]) + hld_res(y, l, h[y] - h[w]).sw();
        int ans = res.sum;
        if (res.f1) ans += f[res.l1];
        else ans += f[res.l1] + f[res.r1];
        cout << ans << '\n';
    }
                  
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}