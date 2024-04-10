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

struct TNode {
    int L, R;
    int l, r;
    int minx;
};

const int maxn = 110000;
TNode t[2 * maxn];

int tc = 0;

#define dn TNode &n = t[node]

int ord[maxn];

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, L};
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        n.minx = min(t[n.l].minx, t[n.r].minx);
    } else n.minx = ord[n.L];
    return node;
}

int n;

int segmin(int node, int L, int R) {
//    if (!node) cerr << "M " << L << ' ' << R << '\n';
    if (L > R) return min(segmin(node, 0, R), segmin(node, L, n));
    dn;
    if (max(L, n.L) >= min(R, n.R)) return 1e9;
    if (L <= n.L && n.R <= R) return n.minx;
    return min(segmin(n.l, L, R), segmin(n.r, L, R));
}

void turnoff(int node, int i) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        n.minx = 1e9;
        return;
    }
    turnoff(n.l, i);
    turnoff(n.r, i);
    n.minx = min(t[n.l].minx, t[n.r].minx);
}

vector<pii> e[maxn];
int w[maxn], tin[maxn], tout[maxn], cid[maxn];
i64 ans = 0;

void dfsw(int v, int p) {
    w[v] = 1;
    for (auto [u, l]: e[v]) {
        if (u == p) continue;
        dfsw(u, v);
        w[v] += w[u];
        ans += 2LL * l * min(w[u], n - w[u]);
    }
}

int T = 0;

void dfs1(int v, int p, int c) {
    ord[T] = v;
    tin[v] = T++;
    cid[v] = c;
    for (auto [u, l]: e[v]) if (u != p) dfs1(u, v, p == -1 ? u : c);
    tout[v] = T;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n;
    forn(i, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        e[u].pb(mp(v, w));
        e[v].pb(mp(u, w));
    }
    dfsw(0, -1);
    cout << ans << '\n';

    int C = -1;
    forn(v, n) {
        bool isC = true;
        for (auto [u, l]: e[v]) {
            int sz = (w[u] < w[v] ? w[u] : n - w[v]);
            isC &= 2 * sz <= n;
        }
        if (isC) C = v;
    }


    dfs1(C, -1, C);
//    cerr << "here\n";
    int root = buildTree(0, n);
    set<pii> grs;
    vi grsz(n);
    grsz[C] = -1e9;
    grs.insert(mp(-1e9, C));
    for (auto [u, l]: e[C]) {
        grsz[u] = 2 * (tout[u] - tin[u]);
        grs.insert(mp(grsz[u], u));
    }

    vi perm(n);
    auto dec_gr = [&](int i) {
        i = cid[i];
        grs.erase(mp(grsz[i], i));
        --grsz[i];
        grs.insert(mp(grsz[i], i));
    };

    forn(i, n) {
        int rem = n - i;
        auto lgr = *--grs.end();
        assert(lgr.fi <= rem);
        bool danger = lgr.fi == rem;
        int to;
        if (i == C) {
            to = danger ? segmin(root, tin[lgr.se], tout[lgr.se]) : segmin(root, 0, n);
        } else {
            to = danger && cid[i] != lgr.se ? segmin(root, tin[lgr.se], tout[lgr.se]) : segmin(root, tout[cid[i]], tin[cid[i]]);
        }
//        cerr << i << ' ' << to << '\n';
        perm[i] = to;
        turnoff(root, tin[to]);
        dec_gr(i);
        dec_gr(to);
    }

    for (int x: perm) cout << x + 1 << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}