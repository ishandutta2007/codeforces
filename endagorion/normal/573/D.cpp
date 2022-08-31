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

const int maxn = 31000;
i64 a[maxn], b[maxn];
int forb[maxn];

struct TNode {
    int L, R;
    int l, r;
    i64 dp[3][3];
};

#define dn TNode &n = t[node]

int n;

i64 seg_cost(int L, int R) {
//    cerr << "? " << L << ' ' << R << '\n';
    if (L < 0 || R > n) return -1e18;
    if (L > R) return -1e18;
    if (L == R) return 0;
    if (R - L > 3) return -1e18;
    if (R - L == 1) {
        i64 res = forb[L] == L ? -1e18 : a[L] * b[L];
//        cerr << L << ' ' << R << ' ' << res << '\n';
        return res;
    }
    i64 ans = -1e18;
    forn(z, 2) {
        i64 res = 0;
        bool ok = true;
        int delta = (z == 0 ? 1 : R - L - 1);
        forn(i, R - L) {
            int x = L + i, y = L + (i + delta) % (R - L);
            ok &= forb[x] != y;
            res += a[x] * b[y];
        }
        if (ok) uax(ans, res);
    }
//    cerr << L << ' ' << R << ' ' << ans << '\n';
    return ans;
}

TNode t[2 * maxn];
int tc = 0;

void fill_leaf(int node) {
    dn;
    forn(lc, 3) forn(rc, 3) n.dp[lc][rc] = seg_cost(n.L + lc, n.R - rc);
/*    cerr << n.L << ' ' << n.R << '\n';
    forn(lc, 3) {
        forn(rc, 3) cerr << n.dp[lc][rc] << ' ';
        cerr << '\n';
    }*/
}

void relax(int node) {
    dn;
    forn(lc, 3) forn(rc, 3) n.dp[lc][rc] = -1e18;
    int M = t[n.l].R;
    forn(mlc, 3) forn(mrc, 3) {
        if (mlc + mrc > 3) break;
        i64 sc = seg_cost(M - mlc, M + mrc);
        forn(lc, 3) forn(rc, 3) uax(n.dp[lc][rc], t[n.l].dp[lc][mlc] + sc + t[n.r].dp[mrc][rc]);
    }
    int lh = M - n.L, rh = n.R - M;
    forn(lc, 3 - lh) forn(rc, 3) uax(n.dp[lh + lc][rc], t[n.r].dp[lc][rc]);
    forn(rc, 3 - rh) forn(lc, 3) uax(n.dp[lc][rh + rc], t[n.l].dp[lc][rc]);
/*    cerr << n.L << ' ' << n.R << '\n';
    forn(lc, 3) {
        forn(rc, 3) cerr << n.dp[lc][rc] << ' ';
        cerr << '\n';
    }*/
}

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {}};
    if (R - L == 1) fill_leaf(node);
    else {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
        relax(node);
    }
    return node;
}

bool cover(int node, int p) {
    dn;
    return n.L <= p && p < n.R;
}

void update(int node, int u, int v) {
    dn;
    if (!cover(node, u) && !cover(node, v)) return;
    if (n.R - n.L == 1) {
        fill_leaf(node);
        return;
    }
    update(n.l, u, v);
    update(n.r, u, v);
    relax(node);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int q;
    cin >> n >> q;
    vector<pii> pa(n), pb(n);
    forn(i, n) cin >> pa[i].fi, pa[i].se = i;
    forn(i, n) cin >> pb[i].fi, pb[i].se = i;
    sort(all(pa)); sort(all(pb));
    vi inva(n);
    forn(i, n) inva[pa[i].se] = i;
    forn(i, n) {
        a[i] = pa[i].fi; b[i] = pb[i].fi;
        forb[inva[pb[i].se]] = i;
    }

    int root = buildTree(0, n);

    while (q--) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        u = inva[u]; v = inva[v];
        swap(forb[u], forb[v]);
//        cerr << "Updating\n";
//        forn(i, n) cerr << forb[i] << ' '; cerr << '\n';
        update(root, u, v);
        cout << t[root].dp[0][0] << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}