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

struct TRes {
    int l, r;
    int m, res;

    TRes operator+(const TRes &rhs) const {
//        cerr << l << ' ' << r << ' ' << m << ' ' << res << '\n';
//        cerr << rhs.l << ' ' << rhs.r << ' ' << rhs.m << ' ' << rhs.res << '\n';
        int gm = min(m, rhs.m);
        int nres = 0;
        if (m == gm) nres += res;
        if (rhs.m == gm) nres += rhs.res;
        if (r == gm && rhs.l > gm) ++nres;
//        cerr << gm << ' ' << nres << '\n';
        return {l, rhs.r, gm, nres};
    }
};

struct TNode {
    int L, R;
    int l, r;
    TRes res;
    int val;
};

const int maxt = 4100000, maxn = 510000;
TNode t[maxt];
int a[maxn];
int tc = 0;

#define dn TNode &n = t[node]

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {0, 0, 0, 0}, 0};
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);        
    }
    return node;
}

void addval(int node, int val) {
    dn;
    n.res.l += val;
    n.res.r += val;
    n.res.m += val;
    n.val += val;
}

void push(int node) {
    dn;
    addval(n.l, n.val);
    addval(n.r, n.val);
    n.val = 0;
}

void addSeg(int node, int L, int R, int x) {
//    if (!node) cerr << L << ' ' << R << ' ' << x << '\n';
    dn;
    if (max(L, n.L) >= min(R, n.R)) return;
    if (L <= n.L && n.R <= R) {
        addval(node, x);
        return;
    }
    push(node);
    addSeg(n.l, L, R, x);
    addSeg(n.r, L, R, x);
    n.res = t[n.l].res + t[n.r].res;
}

int n, q;

void modify(int i, int delta) {
    if (i < 0) return;
    addSeg(0, 2 * a[i], 2 * max(a[i], a[i + 1]) + 1, delta);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> q;
    forn(i, n) cin >> a[i];
    a[n] = -1;
    buildTree(0, 2e6 + 2);
    forn(i, n) {
        modify(i, 1);
    }
    forn(i, q) {
        int p, x;
        cin >> p >> x;
        --p;
        forn(z, 2) modify(p - z, -1);
        a[p] = x;
        forn(z, 2) modify(p - z, 1);
        cout << t[0].res.res << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}