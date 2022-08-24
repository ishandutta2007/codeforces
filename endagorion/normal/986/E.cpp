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

const i64 P = 1000000000 + 7;

const int maxa = 11000000;
int inv[maxa];

const int maxn = 110000, LOG = 18;
vi ps;
int md[maxa], pp[maxa];
i64 res[maxa];
int a[maxn];
int h[maxn];
int up[LOG + 1][maxn];
i64 ans[maxn], ansd[maxn];

i64 deg(i64 x, i64 d) {
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        (x *= x) %= P;
        d /= 2;
    }
    return y;
}

vi e[maxn];

struct TEvent {
    int id;
    int pp, coef;
};

vector<TEvent> evs[maxn];

void dfs_lca(int v, int p) {
    up[0][v] = p;
    for (int u: e[v]) {
        if (u == p) continue;
        h[u] = h[v] + 1;
        dfs_lca(u, v);
    }
}

int jmp(int v, int h) {
    ford(k, LOG) {
        if (h >= (1 << k)) {
            v = up[k][v];
            h -= (1 << k);
        }
    }
    return v;
}

int lca(int v, int u) {
    if (h[v] < h[u]) swap(v, u);
    v = jmp(v, h[v] - h[u]);
    if (v == u) return v;
    ford(k, LOG) {
        int vv = up[k][v], uu = up[k][u];
        if (vv != uu) v = vv, u = uu;
    }
    return up[0][v];
}

void dfs_q(int v, int par) {
    {
        int x = a[v];
        while (x > 1) {
            int p = md[x], q = pp[x];
            for (i64 y = p, z = p; y < maxa; y *= p) {
                (res[y] *= z) %= P;
                if (z != q) z *= p;
            }
            x /= q;
        }
    }
    
    for (auto w: evs[v]) {
        i64 r = res[w.pp];
//        cerr << v << ' ' << w.pp << ' ' << r << '\n';
        if (w.coef < 0) (ansd[w.id] *= deg(r, -w.coef)) %= P;
        else (ans[w.id] *= deg(r, w.coef)) %= P;
    }

    for (int u: e[v]) if (u != par) dfs_q(u, v);

    {
        int x = a[v];
        while (x > 1) {
            int p = md[x], q = pp[x];
            for (i64 y = p, z = p; y < maxa; y *= p) {
                (res[y] *= inv[z]) %= P;
                if (z != q) z *= p;
            }
            x /= q;
        }
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

    forn(i, maxa) md[i] = i;
    fore(i, 2, maxa - 1) {
        if (md[i] == i) ps.pb(i);
        if (md[i] == md[i / md[i]]) pp[i] = pp[i / md[i]] * md[i];
        else pp[i] = md[i];
        for (int p: ps) {
            if (p > md[i] || 1LL * i * p >= maxa) break;
            md[i * p] = p;
        }  
    }

    inv[1] = 1;
    fore(i, 2, maxa - 1) inv[i] = -1LL * (P / i) * inv[P % i] % P;

    int n;
    cin >> n;
    forn(i, n - 1) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        e[x].pb(y);
        e[y].pb(x);
    }
    forn(i, n) cin >> a[i];
    dfs_lca(0, 0);
    forn(k, LOG) forn(i, n) up[k + 1][i] = up[k][up[k][i]];
    int m;
    cin >> m;
    forn(i, m) {
        int u, v, x;
        cin >> u >> v >> x;
        --u; --v;
        int w = lca(u, v);
        ans[i] = __gcd(x, a[w]);
        ansd[i] = 1;
        while (x > 1) {
            int q = pp[x];
            evs[v].pb({i, q, 1});
            evs[u].pb({i, q, 1});
            evs[w].pb({i, q, -2});
            x /= q;
        }
    }

    forn(i, maxa) res[i] = 1;
    dfs_q(0, -1);

    forn(i, m) {
        (ans[i] *= deg(ansd[i], -1)) %= P;
        if (ans[i] < 0) ans[i] += P;
        cout << ans[i] << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}