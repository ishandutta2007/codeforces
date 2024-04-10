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
    pii res;
    int val;
};

const int maxn = 310000;
TNode t[2 * maxn];
int tc = 0;

#define dn TNode &n = t[node]

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {0, R - 1}, 0};
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
    }  
    return node;
}

void addVal(int node, int x) {
    dn;
    n.res.fi += x;
    n.val += x;
}

void push(int node) {
    dn;
    if (!n.val) return;
    addVal(n.l, n.val);
    addVal(n.r, n.val);
    n.val = 0;
}

pii operator+(pii a, pii b) {
    if (a.fi != b.fi) return min(a, b);
    else return max(a, b);
}

void relax(int node) {
    dn;
    n.res = t[n.l].res + t[n.r].res;
}

void addSeg(int node, int L, int R, int x) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return;
    if (L <= n.L && n.R <= R) {
        addVal(node, x);
        return;
    }
    push(node);
    addSeg(n.l, L, R, x);
    addSeg(n.r, L, R, x);
    relax(node);
}

pii getMin(int node, int L, int R) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return {1e9, -1};
    if (L <= n.L && n.R <= R) return n.res;
    push(node);
    return getMin(n.l, L, R) + getMin(n.r, L, R);
}

int fenw[maxn];

int fenwSum(int i) {
    --i;
    int res = 0;
    for (; i >= 0; i &= i + 1, --i) res += fenw[i];
    return res;
}

void fenwAdd(int i, int x) {
    for (; i < maxn; i |= i + 1) fenw[i] += x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, q;
    cin >> n >> q;
    vi a(n);
    forn(i, n) {
        cin >> a[i];
        a[i] = i - a[i] + 1;
        if (a[i] < 0) a[i] = 1e9;
    }

    vector< vector<pii> > qByL(n);
    forn(i, q) {
        int x, y;
        cin >> x >> y;
        qByL[x].pb(mp(y, i));
    }

    vi ans(q, -1);
    int root = buildTree(0, n);
    ford(l, n) {
        addSeg(root, l, l + 1, a[l]);
        while (1) {
            auto p = getMin(root, l, n);
            if (p.fi) break;
            int j = p.se;
            fenwAdd(j, 1);
            addSeg(root, j, j + 1, 1e9);
            addSeg(root, j + 1, n, -1);
        }

        for (auto [y, qi]: qByL[l]) ans[qi] = fenwSum(n - y);
    }
    forn(i, q) cout << ans[i] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}