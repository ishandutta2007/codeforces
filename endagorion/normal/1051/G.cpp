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

const int maxn = 410000;
int par[maxn], l[maxn], r[maxn];
int bs[maxn];

struct TRes {
    i64 s0, s1, si;

    TRes()
        : s0(0)
        , s1(0)
        , si(0)
    {
    }

    TRes(i64 x)
        : s0(1)
        , s1(x)
        , si(0)
    {
    }

    TRes operator+(const TRes &r) const {
        TRes res;
        res.s0 = s0 + r.s0;
        res.s1 = s1 + r.s1;
        res.si = si + s1 * r.s0 + r.si;
/*        print();
        cerr << " + ";
        r.print();
        cerr << " = ";
        res.print();
        cerr << '\n';*/
        return res;
    }

    void print() const {
        cerr << s0 << ' ' << s1 << ' ' << si;
    }
};

struct TNode {
    int l, r;
    int x, y;
    TRes res;
};

TNode t[maxn];
int tc = 1;

#define dn TNode &n = t[node]

int newNode(int x) {
    int node = tc++;
    dn;
    n = {0, 0, x, rand(), TRes(x)};
    return node;
}

void relax(int node) {
    dn;
    n.res = t[n.l].res + TRes(n.x) + t[n.r].res;
}

int tmerge(int l, int r) {
    if (!l) return r;
    if (!r) return l;
    if (t[l].y < t[r].y) {
        t[l].r = tmerge(t[l].r, r);
        relax(l);
        return l;
    } else {
        t[r].l = tmerge(l, t[r].l);
        relax(r);
        return r;
    }
}

pii split(int node, int x) {
    if (!node) return {0, 0};
    dn;
    pii res;
    if (n.x < x) {
        res = split(n.r, x);
        n.r = res.fi;
        res.fi = node;
    } else {
        res = split(n.l, x);
        n.l = res.se;
        res.se = node;
    }
    relax(node);
    return res;
}

int insert(int node, int v) {
    if (!v) return node;
    pii res = split(node, t[v].x);
    return tmerge(res.fi, tmerge(v, res.se));
}

int deep_merge(int n1, int n2) {
    if (t[n1].res.s0 < t[n2].res.s0) swap(n1, n2);
    if (!n2) return n1;
    n1 = deep_merge(n1, t[n2].l);
    n1 = deep_merge(n1, t[n2].r);
    t[n2].l = t[n2].r = 0;
    relax(n2);
    return insert(n1, n2);
}

i64 ans = 0;

int root(int x) {
    return par[x] == x ? x : par[x] = root(par[x]);
}

i64 col_cost(int a) {
    a = root(a);
    return t[bs[a]].res.si;
}

void pmerge(int x, int y) {
    x = root(x);
    y = root(y);
    if (!x || !y) return;
//    cerr << l[x] << ' ' << r[x] << ' ' << l[y] << ' ' << r[y] << '\n';
//    cerr << ans << '\n';
//    cerr << col_cost(x) << ' ' << col_cost(y) << ' ';
    ans -= col_cost(x);
    ans -= col_cost(y);
    ans -= t[bs[y]].res.s1 * (l[y] - l[x]);
    par[y] = x;
    r[x] = r[y];
    bs[x] = deep_merge(bs[x], bs[y]);
    ans += col_cost(x);
//    cerr << col_cost(x) << '\n';
//    cerr << ans << '\n';
}

void addab(int a, int b) {
    if (!par[a]) {
        par[a] = a;
        l[a] = r[a] = a;
        bs[a] = newNode(b);
    } else {
        int to = root(a);
        ans -= 1LL * b * (a - l[to]);
        ans -= col_cost(to);
//        cerr << a << " -> " << l[to] << ' ' << r[to] << ", " << ans << '\n';
        bs[to] = insert(bs[to], newNode(b));
        ans += col_cost(to);
//        cerr << a << " -> " << l[to] << ' ' << r[to] << ", " << ans << '\n';
//        auto res = t[bs[to]].res;
//        cerr << res.s0 << ' ' << res.s1 << ' ' << res.si << '\n';
        par[++r[to]] = to;
    }
    a = root(a);
    pmerge(l[a] - 1, a);
    pmerge(a, r[a] + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    t[0].res = TRes();

    int n;
    cin >> n;
    forn(i, n) {
        int a, b;
        cin >> a >> b;
        addab(a, b);
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}