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

struct Edge {
    int u, v, x;
    i64 w;
};

const int maxn = 210000;
Edge edges[maxn];
vi e[maxn];

struct PathInfo {
    vi64 dist;
    vi prv;
};

int n, m, q;

PathInfo dijkstra(int s) {
    vi64 dist(n, 1e18);
    vi prv(n, -1);
    dist[s] = 0;
    set<pair<i64, int> > q = {{0LL, s}};
    while (!q.empty()) {
        int v = q.begin()->se;
        q.erase(q.begin());
        for (int eid: e[v]) {
            auto &edge = edges[eid];
            int u = v ^ edge.x;
            i64 nd = dist[v] + edge.w;
            if (nd < dist[u]) {
                q.erase(mp(dist[u], u));
                dist[u] = nd;
                prv[u] = eid;
                q.insert(mp(dist[u], u));
            }
        }
    }
    return {dist, prv};
}

void dfs(int v, int pl, vector< vector<pii> > &te, vi &ans) {
    ans[v] = pl;
    for (auto [u, id]: te[v]) dfs(u, max(pl, id + 1), te, ans);
}

vi path_edges(int root, const vi &prv, vi &spid) {
    vector<vector<pii> > te(n);
    forn(v, n) {
        if (prv[v] == -1) {
            continue;
        }
        int eid = prv[v];
        int u = v ^ edges[eid].x;
        te[u].pb({v, spid[eid]});
    }
//    cerr << root << '\n';

    vi ans(n, 0);
    dfs(root, 0, te, ans);
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

    cin >> n >> m >> q;
    forn(i, m) {
        auto &edge = edges[i];
        cin >> edge.u >> edge.v >> edge.w;
        --edge.u; --edge.v;
        edge.x = edge.u ^ edge.v;
        e[edge.u].pb(i);
        e[edge.v].pb(i);
    }

    auto path0 = dijkstra(0), path1 = dijkstra(n - 1);
    if (path0.dist[n - 1] > 1e17) {
        forn(i, q) cout << (i64)1e18 << '\n';
        return 0;
    }
    vi spath;
    vi spid(m, -1);
    
    for (int v = n - 1; v; ) {
        int eid = path0.prv[v];
        auto &edge = edges[eid];
        int u = v ^ edge.x;
        assert(path1.dist[u] == path1.dist[v] + edge.w);
        path1.prv[u] = eid;
        spath.pb(eid);
        v = u;
    }

    reverse(all(spath));
    forn(i, spath.size()) spid[spath[i]] = i;

    vi pe0, pe1;
    forn(z, 2) {
        (z ? pe1 : pe0) = path_edges((z ? n - 1 : 0), (z ? path1.prv : path0.prv), spid);

//        forn(v, n) cerr << (z ? pe1 : pe0)[v] << ' ';
//        cerr << '\n';

        for (auto &x: spid) {
            if (x != -1) x = spath.size() - x - 1;
        }
    }

//    vi pe0 = path_edges(path0.prv, spid), pe1 = path_edges(path1.prv, spid);
    vector< vector<pair<i64, int> > > evs(spath.size() + 1);
    forn(v, n) for (auto eid: e[v]) {
        if (spid[eid] != -1) continue;
        auto &edge = edges[eid];
        int u = v ^ edge.x;
        int L = pe0[v], R = spath.size() - pe1[u];
        i64 w = path0.dist[v] + edge.w + path1.dist[u];
//        cerr << eid << ' ' << v << ' ' << u << ' ' << L << ' ' << R << ' ' << w << '\n';
//        cerr << path0.dist[v] << ' ' << edge.w << ' ' << path1.dist[u] << '\n';
        if (L >= R) continue;
        evs[L].pb({w, 0});
        evs[R].pb({w, -1});
    }

    vi64 shortcuts(spath.size(), (i64)1e18);
    multiset<i64> shw = {(i64)1e18};
    forn(i, spath.size()) {
        for (auto [w, f]: evs[i]) {
            if (!f) shw.insert(w);
            else shw.erase(shw.find(w));
        }
        shortcuts[i] = *shw.begin();
    }

/*    forn(i, spath.size()) {
        cerr << spath[i] << ' ' << shortcuts[i] << '\n';
    }*/

    while (q--) {
        int eid;
        i64 nw;
        cin >> eid >> nw;
        --eid;
        auto &edge = edges[eid];
        int u = edge.u, v = edge.v;

        i64 ans = 1e18;
        uin(ans, path0.dist[u] + nw + path1.dist[v]);
        uin(ans, path0.dist[v] + nw + path1.dist[u]);
        if (spid[eid] != -1) uin(ans, shortcuts[spid[eid]]);
        else uin(ans, path0.dist[n - 1]);
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}