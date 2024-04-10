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
    int len;
    i64 s1, si;

    TRes()
        : len(0)
        , s1(0)
        , si(0)
    {
    }

    TRes(i64 x)
        : len(1)
        , s1(x)
        , si(x)
    {
    }

    TRes operator+(const TRes &r) const {
        TRes res;
        res.len = len + r.len;
        res.s1 = s1 + r.s1;
        res.si = si + s1 * r.len + r.si;
        return res;
    }
};

struct TNode {
    int L, R;
    int l, r;
    TRes res;
    i64 mind, maxd, val;
};

const int maxn = 110000;
TNode t[2 * maxn];
int tc;

#define dn TNode &n = t[node]

void addval(int node, i64 x) {
    dn;
    n.val += x;
    n.mind += x;
    n.maxd += x;
    n.res.s1 += x * n.res.len;
    n.res.si += x * n.res.len * (n.res.len + 1) / 2;
}

void push(int node) {
    dn;
    addval(n.l, n.val);
    addval(n.r, n.val);
    n.val = 0;
}

void relax(int node) {
    dn;
    n.res = t[n.l].res + t[n.r].res;
    n.mind = t[n.l].mind;
    n.maxd = t[n.r].maxd;
}

int buildTree(int L, int R, vi64 &a) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {}, 0, 0, 0};
    if (R - L == 1) {
        n.res = TRes(a[L]);
        n.mind = n.maxd = a[L];
    } else {
        int M = (L + R) / 2;
        n.l = buildTree(L, M, a);
        n.r = buildTree(M, R, a);
        relax(node);
    }
    return node;
}

void addSeg(int node, int L, int R, i64 x) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return;
    if (L <= n.L && n.R <= R) {
        addval(node, x);
        return;
    }
    push(node);
    addSeg(n.l, L, R, x);
    addSeg(n.r, L, R, x);
    relax(node);
}

TRes sum_until(int node, i64 cap) {
    dn;
    if (n.mind > cap) return TRes();
    if (n.maxd <= cap) return n.res;
    push(node);
    return sum_until(n.l, cap) + sum_until(n.r, cap);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m, q;
    cin >> n >> m >> q;
    vi64 a(n), b(m);
    forn(i, n) cin >> a[i];
    forn(i, m) cin >> b[i];
    ford(i, n - 1) a[i + 1] -= a[i];
    ford(i, m - 1) b[i + 1] -= b[i];

    int root = buildTree(1, m, b);

    while (q--) {
        i64 type, len, d;
        cin >> type >> len >> d;
        if (type == 1) {
            forn(i, len) a[n - i - 1] += d;
        } else {
            addSeg(root, m - len, m, d);
            if (len == m) b[0] += d;
        }
        i64 ans = (a[0] + b[0]) * (n + m - 1) + t[root].res.si;
        for1(i, n - 1) {
            TRes res = sum_until(root, a[i]);
            ans += a[i] * (m - 1 - res.len + n - i);
            ans += res.s1;
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}