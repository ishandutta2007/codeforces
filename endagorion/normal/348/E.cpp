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
int key[maxn];
int up[LOG + 1][maxn], h[maxn];
vector<pii> e[maxn];

void dfs0(int v, int p) {
    up[0][v] = p;
    for (auto [u, w]: e[v]) {
        if (u == p) continue;
        h[u] = h[v] + 1;
        dfs0(u, v);
    }
}

pii dfs1(int v, int p) {
    pii res = mp(-1e9, -1);
    if (key[v]) res = mp(0, v);
    for (auto [u, w]: e[v]) {
        if (u == p) continue;
        auto rres = dfs1(u, v);
        rres.fi += w;
        uax(res, rres);
    }
    return res;
}

pair<int, pii> dfs2(int v, int p) {
    int D = -1e18;
    vector<pii> farthest;
    if (key[v]) D = 0, farthest = {{v, -1}};
    for (auto [u, w]: e[v]) {
        if (u == p) continue;
        auto [d, p] = dfs2(u, v);
        if (d < 0) continue;
        d += w;
        if (d > D) D = d, farthest = {};
        if (d == D) farthest.pb(p);
    }
    if (D < 0) return {-1e18, {-1, -1}};
    if (farthest.size() == 1) return {D, farthest[0]};
    return {D, {farthest[0].fi, farthest[1].fi}};
}

void dfs_dist(int v, int p, int d, vi &dist) {
    dist[v] = d;
    for (auto [u, w]: e[v]) {
        if (u == p) continue;
        dfs_dist(u, v, d + w, dist);
    }
}

int jmp(int v, int k) {
    forn(j, LOG) {
        if (!((k >> j) & 1)) continue;
        v = up[j][v];
    }
    return v;
}

int lca(int v, int u) {
    if (h[v] < h[u]) swap(v, u);
    v = jmp(v, h[v] - h[u]);
    if (v == u) return v;
    ford(j, LOG) {
        int vv = up[j][v], uu = up[j][u];
        if (vv != uu) v = vv, u = uu;
    }
    return up[0][v];
}

int dist(int v, int u, int w = -1) {
    if (w == -1) w = lca(v, u);
    return h[v] + h[u] - 2 * h[w];
}

int lca2(int v, int u, int w) {
    return lca(v, u) ^ lca(v, w) ^ lca(u, w);
}

int addp[maxn];

void dfs_sum(int v, int p) {
    for (auto [u, w]: e[v]) {
        if (u == p) continue;
        dfs_sum(u, v);
        addp[v] += addp[u];
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

    int n, m;
    cin >> n >> m;
    forn(i, m) {
        int x;
        cin >> x;
        --x;
        key[x] = 1;
    }

    forn(i, n - 1) {
        int u, v, l;
        cin >> u >> v >> l;
        --u; --v;
        e[u].pb({v, l});
        e[v].pb({u, l});
    }                                       

    int v0 = find(key, key + n, 1) - key;
    auto [d, u1] = dfs1(v0, -1);
    auto [D, v1] = dfs1(u1, -1);

    set<int> sends;
    for (int x: {u1, v1}) {
        auto [dd, p] = dfs2(x, -1);
        assert(dd == D);
        if (p.fi != -1) sends.insert(p.fi);
        if (p.se != -1) sends.insert(p.se);
    }
    
    vi vends(all(sends));
    vvi edist(vends.size(), vi(n));
    forn(i, vends.size()) {
        dfs_dist(vends[i], -1, 0, edist[i]);
    }

//    for (int v: vends) cerr << v << ' ';
//    cerr << '\n';

    dfs0(0, 0);
    forn(j, LOG) forn(v, n) up[j + 1][v] = up[j][up[j][v]];

    forn(v, n) {
        if (!key[v]) continue;
        vi rel_ends;
        int d = -1e9;
        forn(i, vends.size()) {
            int dv = edist[i][v];
            if (uax(d, dv)) rel_ends.clear();
            if (d == dv) rel_ends.pb(vends[i]);
        }
        assert(!rel_ends.empty());
        int w = rel_ends[0];
        forn(i, rel_ends.size()) forn(j, i) {
            int u = lca2(v, rel_ends[i], rel_ends[j]);
            if (dist(v, u) < dist(v, w)) w = u;
        }
//        cerr << v << ' ' << w << ' ' << rel_ends.size() << '\n';
        addp[v] += 1;
        addp[w] += 1;
        int z = lca(v, w);
        addp[z] -= 1;
        if (z) addp[up[0][z]] -= 1;
    }

    dfs_sum(0, 0);

    pii ans;
    forn(v, n) {
        if (key[v]) continue;
//        cerr << v << ' ' << addp[v] << '\n';
        if (addp[v] > ans.fi) ans = mp(addp[v], 0);
        if (addp[v] == ans.fi) ++ans.se;
    }
    cout << ans.fi << ' ' << ans.se << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}