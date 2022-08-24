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
int par[maxn], rk[maxn], sz[maxn];
int nodd;

vector<pair<int *, int> > chs;

int root(int x) {
    return x == par[x] ? x : root(par[x]);
}

void change(int &x, int y) {
    if (x == y) return;
    chs.pb(mp(&x, x));
    x = y;
}

void undo(int zst) {
    while (chs.size() > zst) {
        auto p = chs.back();
        *p.fi = p.se;
        chs.pop_back();
    }
}

void unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return;
    if (rk[x] > rk[y]) swap(x, y);
    change(par[x], y);
    if (sz[x] && sz[y]) change(nodd, nodd - 2);
    change(sz[y], sz[x] ^ sz[y]);
    if (rk[x] == rk[y]) change(rk[y], rk[x] + 1);
}

struct TEdge {
    int u, v, w, id;

    bool operator<(const TEdge &e) const {
        if (w != e.w) return w < e.w;
        return id < e.id;
    }
};

void push_edge(set<TEdge> &e, TEdge ne, int wt, vector<pair<TEdge, int> > &ech) {
    if (ne.w <= wt) {
        unite(ne.u, ne.v);
    } else {
        ech.pb(mp(ne, 0));
        e.insert(ne);
    }
}

const int maxm = 310000;
int ans[maxm];
TEdge edges[maxm];

void dnc(int L, int R, int wt, set<TEdge> &e) {
//    cerr << L << ' ' << R << ' ' << wt << ' ' << e.size() << '\n';
    if (R == L) return;
    int M = (L + R) / 2;
    vector<pair<TEdge, int> > ech;
    int zst = chs.size();
    fore(i, L, M - 1) push_edge(e, edges[i], wt, ech);

    int zst2 = chs.size();
    push_edge(e, edges[M], wt, ech);

    dnc(M + 1, R, wt, e);
    if (edges[M].w > wt) e.erase(edges[M]);
    undo(zst2);

    int nwt = wt;
    while (!e.empty() && nodd) {
        auto fe = *e.begin();
        nwt = fe.w;
        ech.pb(mp(fe, 1));
        e.erase(fe);
        unite(fe.u, fe.v);
    }

    ans[M] = nodd ? -1 : nwt;
    undo(zst);
    while (!ech.empty()) {
        auto p = ech.back();
        if (p.se) e.insert(p.fi);
        else e.erase(p.fi);
        ech.pop_back();
    }

    while (!e.empty() && e.begin()->w <= nwt) {
        auto fe = *e.begin();
        ech.pb(mp(fe, 1));
        e.erase(fe);
        unite(fe.u, fe.v);
    }

    dnc(L, M, nwt, e);
    while (!ech.empty()) {
        auto p = ech.back();
        if (p.se) e.insert(p.fi);
        else e.erase(p.fi);
        ech.pop_back();
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
    forn(i, n) {
        par[i] = i;
        sz[i] = 1;
    }
    nodd = n;

    forn(i, m) {
        auto &e = edges[i];
        cin >> e.u >> e.v >> e.w;
        --e.u; --e.v; e.id = i;
    }
    set<TEdge> e;
    dnc(0, m + 1, 0, e);
    for1(i, m) cout << ans[i] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}