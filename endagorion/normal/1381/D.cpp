#include <bits/stdc++.h>

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

const int maxn = 110000, LOG = 20;
vi e[maxn];
int h[maxn];
int up[LOG + 1][maxn];
pii pdown[maxn], pup[maxn];

void dfs0(int v, int p) {
    up[0][v] = p;
    for (int u: e[v]) {
        if (u == p) continue;
        h[u] = h[v] + 1;
        dfs0(u, v);
    }
}

int jmp(int v, int h) {
    ford(k, LOG) {
        if (h < (1 << k)) continue;
        h -= (1 << k);
        v = up[k][v];
    }
    return v;
}

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    u = jmp(u, h[u] - h[v]);
    if (u == v) return v;
    ford(k, LOG) {
        int uu = up[k][u], vv = up[k][v];
        if (uu != vv) u = uu, v = vv;
    }
    return up[0][u];
}

int dist(int u, int v) {
    return h[u] + h[v] - 2 * h[lca(u, v)];
}

int towards(int u, int v, int d) {
    int w = lca(u, v);
    int D = h[u] + h[v] - 2 * h[w];
    assert(d <= D);
    if (d <= h[u] - h[w]) return jmp(u, d);
    return jmp(v, D - d);
}

int D;

void dfs_down(int v, int p) {
    pii bp[2] = {{0, v}, {0, v}};
    for (int u: e[v]) {
        if (u == p) continue;
        dfs_down(u, v);
        pii x = pdown[u];
        x.fi += 1;
        forn(i, 2) if (x > bp[i]) swap(x, bp[i]);
    }
    if (bp[0].fi > 1e8 || bp[1].fi >= D) pdown[v] = {1e9, -1};
    else pdown[v] = bp[0];
//    cerr << "D " << v << ' ' << pdown[v].fi << ' ' << pdown[v].se << '\n';
}

void dfs_up(int v, int p, pii bup) {
    pup[v] = bup;
//    cerr << "U " << v << ' ' << pup[v].fi << ' ' << pup[v].se << '\n';
    pii bp[3];
    forn(i, 3) bp[i] = mp(-1, v);
    bp[0] = bup;
    for (int u: e[v]) {
        if (u == p) continue;
        pii x = pdown[u];
        x.fi += 1;
        forn(i, 3) if (x > bp[i]) swap(x, bp[i]);
    }
//    cerr << v << '\n';
//    forn(i, 3) cerr << bp[i].fi << ' ' << bp[i].se << '\n';
    for (int u: e[v]) {
        if (u == p) continue;
        pii ubp[2];
        int l = 0;
        pii x = pdown[u];
        x.fi += 1;
        bool skip = false;
        forn(i, 3) {
            if (x == bp[i] && !skip) skip = true;
            else if (l < 2) ubp[l++] = bp[i];
        }
        pii ubup;
//        cerr << v << ' ' << u << ' ' << l << '\n';
        assert(l == 2);
//        cerr << "E " << v << ' ' << u << '\n';
//        forn(i, 2) cerr << ubp[i].fi << ' ' << ubp[i].se << '\n';
        if (ubp[0].fi > 1e8 || ubp[1].fi >= D) ubup = mp(1e9, -1);
        else ubup = ubp[0];
        ++ubup.fi;
        dfs_up(u, v, ubup);
    }
}

pii get_tail(int v, int u) {
    assert(dist(v, u) == D);
    int pv = towards(u, v, D - 1);
    if (h[pv] < h[v]) return pdown[v];
    return pup[pv];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    while (T--) {
        int n, s, t;
        cin >> n >> s >> t;
        --s; --t;
        forn(i, n - 1) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            e[u].pb(v);
            e[v].pb(u);
        }
        dfs0(0, 0);
        forn(j, LOG) forn(v, n) up[j + 1][v] = up[j][up[j][v]];

        D = dist(s, t);
        dfs_down(0, 0);
        dfs_up(0, 0, {0, 0});

        int ll = -1;
        bool win = false;
        while (1) {
            assert(dist(s, t) == D);
            pii p = get_tail(s, t);
//            cerr << s << ' ' << t << ' ' << p.fi << ' ' << p.se << '\n';
            if (p.fi > 1e8) {
                win = true;
                break;
            }
            int nll = dist(s, p.se);
            if (nll <= ll) break;
            ll = nll;
            s = p.se;
            t = towards(t, s, nll);
            swap(s, t);
        }

        cout << (win ? "YES": "NO") << '\n';

        forn(i, n) e[i].clear();
    }


#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}