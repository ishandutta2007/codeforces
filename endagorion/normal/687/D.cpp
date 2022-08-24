#include <iostream>
#include <tuple>
#include <sstream>
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

const int maxm = 1000000;
const int maxn = 1100;

int n, q, m;
int l[maxm], r[maxm], w[maxm];
int par[maxn], conj[maxn];

int root(int x) {
    if (x < 0) return x;
    return x == par[x] ? x : par[x] = root(par[x]);
}

struct TNode {
    int L, R;
    int l, r;
    vi edges;

    TNode(int L = -1, int R = -1)
        : L(L)
        , R(R)
        , l(-1)
        , r(-1)
        , edges()
    {
    }
};

bool byWeight(int a, int b) {
    return w[a] > w[b];
}

vi do_merge(const vi &a, const vi &b) {
    vi c(a.size() + b.size());
    merge(all(a), all(b), c.begin(), byWeight);
    return c;
}

vi refine(vi edges, int *sgn = 0) {
    vi nedges;
    forn(i, n) par[i] = i, conj[i] = -1;
    for (int e: edges) {
        int u = root(l[e]), v = root(r[e]);
        if (u == v) {
            nedges.pb(e);
            if (sgn) *sgn = 1;
            return nedges;
        }
        int pu = root(conj[u]), pv = root(conj[v]);
        if (pu == v || pv == u) {
            assert(pu == v && pv == u);
            continue;
        }
        if (pu != -1) par[pu] = v;
        if (pv != -1) par[pv] = u;
        conj[u] = v;
        conj[v] = u;
        nedges.pb(e);
    }
    if (sgn) *sgn = 0;
    return nedges;
}

const int MAXT = 1100000;
TNode t[MAXT];
int tc = 0;

int buildTree(int L, int R) {
    int node = tc++;
    t[node] = TNode(L, R);
    if (R - L == 1) {
        t[node].edges = vi(1, L);
    } else {
        int M = (L + R) / 2;
        t[node].l = buildTree(L, M);
        t[node].r = buildTree(M, R);
        t[node].edges = refine(do_merge(t[t[node].l].edges, t[t[node].r].edges));
    }
    return node;
}

vi query(int node, int L, int R) {
    if (max(L, t[node].L) >= min(R, t[node].R)) return vi();
    if (L <= t[node].L && t[node].R <= R) return t[node].edges;
    return refine(do_merge(query(t[node].l, L, R), query(t[node].r, L, R)));
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
        cin >> l[i] >> r[i] >> w[i];
        --l[i]; --r[i];
    }
    int root = buildTree(0, m);
    forn(i, q) {
        int L, R;
        cin >> L >> R;
        --L;
        vi edges = query(root, L, R);
        int fl = -1;
        refine(edges, &fl);
//        for (int x: edges) cerr << x << ' ';
//        cerr << '\n';
        assert(fl != -1);
        if (!fl) cout << -1 << '\n';
        else cout << w[edges.back()] << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}