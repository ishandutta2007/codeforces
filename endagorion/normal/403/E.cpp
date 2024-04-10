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

const int INF = 1e9;

struct TRes {
    pii minx, maxx;

    TRes():
        minx(INF, -1),
        maxx(-INF, -1)
    {
    }

    TRes operator+(const TRes &r) const {
        TRes res;
        res.minx = min(minx, r.minx);
        res.maxx = max(maxx, r.maxx);
        return res;
    }
};

TRes from_set(const set<pii> &s) {
    if (s.empty()) return TRes();
    TRes res;
    res.minx = *s.begin();
    res.maxx = *prev(s.end());
    return res;
}

struct TNode {
    int L, R;
    int l, r;
    TRes res;
    set<pii> xs;
};

const int maxn = 210000;
TNode t[4 * maxn];

int tc = 0;
#define dn TNode &n = t[node]

void relax(int node) {
    dn;
    n.res = t[n.l].res + t[n.r].res;
}

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, TRes(), {}};
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
    }
    return node;
}

TRes segq(int node, int L, int R) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return TRes();
    if (L <= n.L && n.R <= R) return n.res;
    return segq(n.l, L, R) + segq(n.r, L, R);
}


void update(int node, int i, pii p, bool ins) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        if (ins) n.xs.insert(p);
        else {
            assert(n.xs.count(p));
            n.xs.erase(p);
        }
        n.res = from_set(n.xs);
        return;
    }
    update(n.l, i, p, ins);
    update(n.r, i, p, ins);
    relax(node);
}

pii elst[2][maxn];
vi e[2][maxn];
int tin[2][maxn], tout[2][maxn], h[2][maxn];
int dead[2][maxn];
int root[2];
int T;

void dfs(int z, int v, int p) {
    tin[z][v] = T++;
    for (int u: e[z][v]) {
        if (u == p) continue;
        h[z][u] = h[z][v] + 1;
        dfs(z, u, v);
    }
    tout[z][v] = T;
}

int edge_in(int z, int v, int id) {
    auto [u, w] = elst[z ^ 1][id];
    if (tin[z][v] <= tin[z][u] && tin[z][u] < tout[z][v]) return u;
    if (tin[z][v] <= tin[z][w] && tin[z][w] < tout[z][v]) return w;
    assert(false);
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    forn(z, 2) forn(i, n - 1) {
        auto &[u, v] = elst[z][i];
        u = i + 1;
        cin >> v; --v;
        e[z][u].pb(v);
        e[z][v].pb(u);
    }

    forn(z, 2) {
        T = 0;
        dfs(z, 0, -1);
        root[z] = buildTree(0, n);
    }

    forn(z, 2) {
        forn(i, n - 1) {
            auto [u, v] = elst[z][i];
//            cerr << z << ' ' << i << ' ' << u << ' ' << v << '\n';
            update(root[z ^ 1], tin[z ^ 1][u], {tin[z ^ 1][v], i}, true);
            update(root[z ^ 1], tin[z ^ 1][v], {tin[z ^ 1][u], i}, true);
        }           
    }

    vi eids(1);
    cin >> eids[0];
    --eids[0];
    dead[0][eids[0]] = 1;

    int z = 0;
    while (!eids.empty()) {
        cout << (z ? "Red" : "Blue") << '\n';
        sort(all(eids));
        for (int id: eids) cout << id + 1 << ' ';
        cout << endl;
        
        vi neids;
        for (int id: eids) {
            auto [u, v] = elst[z][id];
            if (h[z][u] > h[z][v]) swap(u, v);
            int L = tin[z][v], R = tout[z][v];
            while (1) {
                auto res = segq(root[z], L, R);
//                cerr << z << ' ' << L << ' ' << R << ' ' << res.minx.se << ' ' << res.maxx.se << '\n';
                if (res.minx.fi < L) {
                    int nid = res.minx.se;
                    if (!dead[z ^ 1][nid]) neids.pb(nid);
                    dead[z ^ 1][nid] = true;
                    update(root[z], tin[z][edge_in(z, v, nid)], res.minx, false);
                } else if (res.maxx.fi >= R) {
                    int nid = res.maxx.se;
                    if (!dead[z ^ 1][nid]) neids.pb(nid);
                    dead[z ^ 1][nid] = true;
                    update(root[z], tin[z][edge_in(z, v, nid)], res.maxx, false);
                } else break;
            }
        }

        eids = neids;
        z ^= 1;
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}