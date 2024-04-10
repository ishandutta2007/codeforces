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

vi xs, ys;
vi roots;

struct TNode {
    int L, R;
    int l, r;
    int mx;
};

const int maxn = 110000;
const int INF = 1e9;
TNode t[40 * maxn];
int tc = 0;

int gx[maxn], gy[maxn], mx[maxn], my[maxn];
#define dn TNode &n = t[node]

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {ys[L], ys[R - 1] + 1, -1, -1, -(int)INF};
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
    }
    return node;
}

int copy_node(int node) {
    int nnode = tc++;
    t[nnode] = t[node];
    return nnode;
}

void relax(int node) {
    dn;
    n.mx = max(t[n.l].mx, t[n.r].mx);
}

int change(int node, int y, int x) {
    dn;
//    cerr << n.L << ' ' << n.R << ' ' << y << ' ' << x << '\n';
    if (y < n.L || y >= n.R) return node;
    if (n.R - n.L == 1) {
        node = copy_node(node);
        t[node].mx = x;
//        cerr << n.L << ' ' << n.R << ' ' << t[node].mx << '\n';
        return node;
    }
    node = copy_node(node);
    t[node].l = change(n.l, y, x);
    t[node].r = change(n.r, y, x);
    relax(node);
//    cerr << n.L << ' ' << n.R << ' ' << t[node].mx << '\n';
    return node;
}

int seg_max(int node, int L, int R) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return -INF;
    if (L <= n.L && n.R <= R) return n.mx;
    return max(seg_max(n.l, L, R), seg_max(n.r, L, R));
}

struct TRect {
    int lx, rx, ly, ry;

    bool empty() const {
        return lx > rx || ly > ry;
    }

    void norm() {
        if (lx == rx) {
            if ((lx + ly) & 1) ++ly;
            if ((lx + ry) & 1) --ry;
        }
        if (ly == ry) {
            if ((lx + ly) & 1) ++lx;
            if ((rx + ly) & 1) --rx;
        }
    }

    TRect operator+(const TRect &r) const {
        TRect res = {max(lx, r.lx), min(rx, r.rx), max(ly, r.ly), min(ry, r.ry)};
        res.norm();
        return res;
    }

    TRect expand(int d) const {
        if (empty()) return *this;
        TRect res = *this;
        res.lx -= d; res.rx += d; res.ly -= d; res.ry += d;
        res.norm();
        return res;
    }
};

TRect gr[maxn];

void print(int node) {
    if (node == -1) return;
    dn;
    print(n.l);
    cerr << n.L << ' ' << n.R << ' ' << n.mx << '\n';
    print(n.r);
}

bool has_point(TRect R) {
    R.norm();
    if (R.empty()) return false;
    int i = upper_bound(all(xs), R.rx) - xs.begin() - 1;
    bool res = seg_max(roots[i], R.ly, R.ry + 1) >= R.lx;
//    cerr << R.lx << ' ' << R.rx << ' ' << R.ly << ' ' << R.ry << ' ' << res << '\n';
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, k;
    cin >> n >> k;
    forn(i, n + k) {
        int x, y;
        cin >> x >> y;
        (i < n ? gx[i] : mx[i - n]) = x + y;
        (i < n ? gy[i] : my[i - n]) = x - y;
    }

    xs = {-INF};
    ys = {-INF};
    forn(i, k) {
        xs.pb(mx[i]);
        ys.pb(my[i]);
    }
    auto make_unique = [](vi &v) {
        sort(all(v));
        v.erase(unique(all(v)), v.end());
    };
    make_unique(xs);
    make_unique(ys);

    roots.resize(xs.size());
    roots[0] = buildTree(0, ys.size());

    vi ord(k);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j){return mx[i] < mx[j];});

    int ptr = 0;
    for (int i: ord) {
        int nptr = ptr;
        if (mx[i] > xs[ptr]) ++nptr;
        roots[nptr] = change(roots[ptr], my[i], mx[i]);
        ptr = nptr;
    }

/*    forn(i, xs.size()) {
        print(roots[i]);
        cerr << "---\n";
    }*/

//    cerr << "here\n";

    vector<pii> md;
    forn(i, n) {
        gr[i] = {gx[i], gx[i], gy[i], gy[i]};
        int L = -1, R = INF;
        while (R - L > 1) {
            int M = (L + R) / 2;
            (has_point(gr[i].expand(M)) ? R : L) = M;
        }
//        cerr << i << ' ' << R << '\n';
        md.pb(mp(R, i));
    }
    sort(rall(md));
    int L = -1, R = INF;
    while (R - L > 1) {
        int M = (L + R) / 2;
        TRect inter = {-INF, INF, -INF, INF};
        bool ok = false;
        forn(i, n) {
            int d = md[i].fi, j = md[i].se;
            ok |= d <= M && has_point(inter.expand(M - d));
            inter = inter + gr[j].expand(M);
//            cerr << M << ' ' << i << ' ' << inter.lx << ' ' << inter.rx << ' ' << inter.ly << ' ' << inter.ry << ' ' << ok << '\n';
        }
        ok |= !inter.empty();
        (ok ? R : L) = M;
    }
    cout << R << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}