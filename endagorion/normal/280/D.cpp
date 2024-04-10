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
    bool empty;
    pii seg; int segsum;
    int prefi, sufi;
    int prefsum, sufsum;
    int sum;

    TRes()
        : empty(true)
        , segsum(0)
    {
    }

    TRes(int x, int i) {
        empty = false;
        sum = x;
        if (x > 0) {
            segsum = prefsum = sufsum = x;
            seg = mp(i, i + 1);
            prefi = i + 1;
            sufi = i;
        } else {
            segsum = prefsum = sufsum = 0;
            seg = mp(i, i);
            prefi = i;
            sufi = i + 1;
        }
    }

    TRes operator+(const TRes &r) const {
        if (empty) return r;
        if (r.empty) return *this;
        TRes res = *this;
        res.sum += r.sum;
        res.sufsum += r.sum;
        if (uax(res.segsum, r.segsum)) {
            res.seg = r.seg;
        }
        if (uax(res.segsum, sufsum + r.prefsum)) {
            res.seg = mp(sufi, r.prefi);
        }
        if (uax(res.prefsum, sum + r.prefsum)) {
            res.prefi = r.prefi;
        }
        if (uax(res.sufsum, r.sufsum)) {
            res.sufi = r.sufi;
        }
        return res;
    }
};

struct TNode {
    int L, R;
    int l, r;
    int val;
    TRes res;
};

const int maxn = 110000;
TNode t[4 * maxn];
int a[maxn];
int tc = 0;

#define dn TNode &n = t[node]

void relax(int node) {
    dn;
    n.res = t[n.l].res + t[n.r].res;
/*    cerr << n.L << ' ' << n.R << ":\n";
    cerr << n.res.seg.fi << ' ' << n.res.seg.se << ' ' << n.res.segsum << '\n';
    cerr << n.res.prefi << ' ' << n.res.prefsum << '\n';
    cerr << n.res.sufi << ' ' << n.res.sufsum << '\n';*/
}

int buildTree(int L, int R, int z) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, 0, {}};
    if (R - L == 1) {
        n.res = TRes(a[L] * (z ? -1 : 1), L);
    } else {
        int M = (L + R) / 2;
        n.l = buildTree(L, M, z);
        n.r = buildTree(M, R, z);
        relax(node);
    }
    return node;
}

void change(int node, int i, int x) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        n.res = TRes(x, i);
        return;
    }
    change(n.l, i, x);
    change(n.r, i, x);
    relax(node);
}

TRes query(int node, int L, int R) {
    if (L >= R) return TRes();
    dn;
    if (max(L, n.L) >= min(R, n.R)) return TRes();
    if (L <= n.L && n.R <= R) return n.res;
    return query(n.l, L, R) + query(n.r, L, R);
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
    forn(i, n) cin >> a[i];
    vi root(2);
    forn(z, 2) root[z] = buildTree(0, n, z);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 0) {
            int i, x;
            cin >> i >> x;
            --i;
            forn(z, 2) change(root[z], i, x * (z ? -1 : 1));
        } else {
            int L, R, k;
            cin >> L >> R >> k;
            --L;
            vector<pair<int, TRes> > seq = {{L, query(root[0], L, R)}, {R, TRes()}};
            int ans = 0;
            while (k--) {
                int bi = -1, bs = 0;
                forn(i, (int)seq.size() - 1) {
                    if (uax(bs, seq[i].se.segsum)) bi = i;
//                    cerr << i << ' ' << seq[i].fi << ' ' << seq[i].se.segsum << ' ' << seq[i].se.seg.fi << ' ' << seq[i].se.seg.se << '\n';
                }
                if (!bs) break;
                ans += bs;
                int l1 = seq[bi].fi, r1 = seq[bi + 1].fi;
                TRes res = seq[bi].se;
                auto [l2, r2] = res.seg;
//                cerr << l1 << ' ' << l2 << ' ' << r2 << ' ' << r1 << '\n';
                int z = bi & 1;
                seq[bi].se = query(root[z], l1, l2);
                seq.insert(seq.begin() + bi + 1, mp(l2, query(root[z ^ 1], l2, r2)));
                seq.insert(seq.begin() + bi + 2, mp(r2, query(root[z], r2, r1)));
            }
            cout << ans << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}