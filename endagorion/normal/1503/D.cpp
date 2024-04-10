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

typedef pair<pii, pii> TRes;

struct TNode {
    int L, R;
    int l, r;
    TRes ex;
};

TRes operator+(TRes a, TRes b) {
    return {min(a.fi, b.fi), max(a.se, b.se)};
}

const int maxn = 410000;

TNode t[3 * maxn];
int roots[3];
int ys[maxn];
int col[maxn];
int sw[maxn];
int tc = 0;

#define dn TNode &n = t[node];

TRes none = {{1e9, -1}, {-1e9, -1}};

int build_tree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, {}};
    if (R - L == 1) {
        n.ex = none;
    } else {
        int M = (L + R) / 2;
        n.l = build_tree(L, M);
        n.r = build_tree(M, R);
        n.ex = t[n.l].ex + t[n.r].ex;
    }
    return node;
}

TRes segq(int node, int L, int R) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return none;
    if (L <= n.L && n.R <= R) return n.ex;
    return segq(n.l, L, R) + segq(n.r, L, R);
}

void add(int node, int i) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        n.ex = {{ys[i], i}, {ys[i], i}};
        return;
    }
    add(n.l, i);
    add(n.r, i);
    n.ex = t[n.l].ex + t[n.r].ex;
}

void remove(int node, int i) {
    dn;
    if (i < n.L || i >= n.R) return;
    if (n.R - n.L == 1) {
        n.ex = none;
        return;
    }
    remove(n.l, i);
    remove(n.r, i);
    n.ex = t[n.l].ex + t[n.r].ex;
}

int n;

pii dfs(int v, int c) {
    if (col[v] != -1) {
        return col[v] == c ? mp(0, 0) : mp(-1, -1);
    }
//    cerr << v << ' ' << c << ' ' << sw[v] << '\n';
    col[v] = c;
    if (segq(roots[c + 1], v + 1, n).se.fi > ys[v] ||
        segq(roots[c + 1], 0, v).fi.fi < ys[v]) return mp(-1, -1);
    remove(roots[0], v);
    add(roots[c + 1], v);
    pii res = {0, 0};
    ++(c == sw[v] ? res.fi : res.se);
    while (1) {
        auto p = segq(roots[0], v + 1, n).se;
        if (p.fi < ys[v]) break;
//        cerr << v << ' ' << p.se << '\n';
//        cerr << v << ' ' << p.fi << ' ' << p.se << '\n';
        auto r = dfs(p.se, c ^ 1);
        if (r.fi < 0) return r;
        res.fi += r.fi;
        res.se += r.se;
    }
    while (1) {
        auto p = segq(roots[0], 0, v).fi;
        if (p.fi > ys[v]) break;
//        cerr << v << ' ' << p.se << '\n';
        auto r = dfs(p.se, c ^ 1);
        if (r.fi < 0) return r;
        res.fi += r.fi;
        res.se += r.se;
    }
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

    cin >> n;
    vector<pii> a(n);
    bool ok = true;
    forn(i, n) {
        cin >> a[i].fi >> a[i].se;
        if (a[i].fi > a[i].se) {
            swap(a[i].fi, a[i].se);
            sw[a[i].fi - 1] = 1;
        }
        ok &= a[i].fi <= n && a[i].se > n;
    }
    if (!ok) {
        cout << -1 << '\n';
        return 0;
    }
    for (auto [x, y]: a) ys[x - 1] = y - n - 1;

    forn(c, 3) roots[c] = build_tree(0, n);
    forn(i, n) add(roots[0], i);

    forn(i, n) col[i] = -1;
    int ans = 0;
    forn(i, n) {
        if (col[i] != -1) continue;
        pii res = dfs(i, 0);
//        cerr << " D " << i << ' ' << res.fi << ' ' << res.se << '\n';
        if (res.fi < 0) {
            ans = -1;
            break;
        }
        ans += min(res.fi, res.se);
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}