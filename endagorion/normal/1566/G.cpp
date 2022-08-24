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

const int maxn = 110000;
int used[maxn];

struct TRes {
    array<pi64, 3> es;
    i64 min3;

    TRes() {
        forn(z, 3) es[z] = {1e18, -1};
        min3 = 1e18;
    }

    TRes operator+(const TRes &r) const {
        TRes res;
        res.min3 = min(min3, r.min3);
        int p1 = 0, p2 = 0, p3 = 0;
        while (p3 < 3) {
            bool go1 = p1 < 3 && (p2 == 3 || es[p1].fi <= r.es[p2].fi);
            auto &p = go1 ? p1 : p2;
            assert(p < 3);
            auto &e = go1 ? es : r.es;
            if (e[p].se != -1 && used[e[p].se]) {
                ++p;
                continue;
            }
            if (e[p].se != -1) used[e[p].se] = 1;
            res.es[p3++] = e[p++];
        }
        forn(z, 3) {
            int v = res.es[z].se;
            if (v != -1) used[v] = 0;
        }
        return res;
    }

    i64 bestw_except(pi64 v) const {
        forn(z, 3) {
            auto p = es[z];
            if (p.se == v.fi || p.se == v.se) continue;
            return p.fi;
        }
        assert(false);
        return 1e18;
    }
};

set<pi64> adj[maxn];
map<pi64, i64> W;
set<pair<i64, pi64> > allEs;

TRes static_vres(int v) {
    TRes res;
    res.min3 = 0;
    auto it = adj[v].begin();
    forn(z, 3) {
        if (it == adj[v].end()) {
            res.min3 = 1e18;
            res.es[z] = mp(1e18, -1);
            continue;
        } 
        res.min3 += it->fi;
        res.es[z] = *it;
        ++it;
    }
    return res;
}

struct TNode {
    int L, R;
    int l, r;
    TRes res;
};

TNode t[2 * maxn];
int tc = 0;
#define dn TNode &n = t[node]

void relax(int node) {
    dn;
    n.res = t[n.l].res + t[n.r].res;
}

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {}};
    if (R - L == 1) {
        n.res = static_vres(L);
    } else {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        relax(node);
    }
    return node;
}

void update(int node, int i) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        n.res = static_vres(i);
        return;
    }
    update(n.l, i);
    update(n.r, i);
    relax(node);
}

void print(const TRes &res) {
    cerr << res.min3 << '\n';
    for (auto [x, y]: res.es) cerr << x << ' ' << y << "; ";
    cerr << '\n';
}

TRes segres(int node, int L, int R) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return TRes();
    if (L <= n.L && n.R <= R) return n.res;
    auto res = segres(n.l, L, R) + segres(n.r, L, R);
//    cerr << L << ' ' << R << '\n';
//    print(res);
    return res;
}

int n;
int root;
i64 answer() {
    i64 ans = t[root].res.min3;
    auto it = allEs.begin();
    auto [u, v] = it->se;
//    cerr << "Min edge " << u << ' ' << v << ' ' << W[mp(u, v)] << '\n';
//    cerr << "Min3 " << ans << '\n';
    i64 w0 = it->fi;
    i64 res1 = 1e18;
    uin(res1, w0 + segres(root, 0, u).bestw_except(mp(u, v)));
    uin(res1, w0 + segres(root, u + 1, v).bestw_except(mp(u, v)));
    uin(res1, w0 + segres(root, v + 1, n).bestw_except(mp(u, v)));
    uin(ans, res1);
//    cerr << "Min edge + " << res1 << '\n';
    auto endit = [&](int v) {
        auto it = adj[v].begin();
        forn(z, 3) {
            if (it == adj[v].end()) return it;
            ++it;
        }
        return it;
    };
    vector<pi64> adju(adj[u].begin(), endit(u));
    vector<pi64> adjv(adj[v].begin(), endit(v));
    i64 res2 = 1e18;
    for (auto pu: adju) for (auto pv: adjv) {
        if (pu.se == pv.se) continue;
        if (pu.se == v) continue;
        if (pv.se == u) continue;
        uin(res2, pu.fi + pv.fi);
    }
//    cerr << "Edge u + Edge v " << res2 << '\n';
    uin(ans, res2);
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

    int m;
    cin >> n >> m;
    forn(i, m) {
        i64 u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        if (u > v) swap(u, v);
        W[mp(u, v)] = w;
        adj[u].insert(mp(w, v));
        adj[v].insert(mp(w, u));
        allEs.insert(mp(w, mp(u, v)));
    }

    root = buildTree(0, n);

    cout << answer() << '\n';
    int q;
    cin >> q;
    while (q--) {
        int type;
        i64 u, v, w;
        cin >> type >> u >> v;
        --u; --v;
        if (u > v) swap(u, v);
        if (type == 0) w = W[mp(u, v)];
        else cin >> w;
        if (type == 1) {
            W[mp(u, v)] = w;
            adj[u].insert(mp(w, v));
            adj[v].insert(mp(w, u));            
            allEs.insert(mp(w, mp(u, v)));
        } else {
            W.erase(mp(u, v));
            adj[u].erase(mp(w, v));
            adj[v].erase(mp(w, u));            
            allEs.erase(mp(w, mp(u, v)));
        }
        update(root, u);
        update(root, v);
        cout << answer() << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}