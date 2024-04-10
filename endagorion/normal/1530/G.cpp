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

int n, k;

vi gaps(string s) {
    int n0 = 0;
    vi res;
    for (char c: s) {
        if (c == '0') ++n0;
        else res.pb(n0), n0 = 0;
    }
    res.pb(n0);
    return res;
}

void make_op(bool tol, int i, vi &g, vector<pii> &ops) {
    int j = i + k;
    assert(j < g.size());
    int L = -1, R = 0;
    forn(k, g.size()) {
        if (k <= i) L += g[k] + 1;
        if (k < j) R += g[k] + 1;
    }
//    cerr << i << ' ' << tol << ' ' << L << ' ' << R << '\n';
    if (tol) R += g[j];
    else L -= g[i];
    reverse(g.begin() + i + 1, g.begin() + j);
    if (tol) {
        g[i] += g[j];
        g[j] = 0;
    } else {
        g[j] += g[i];
        g[i] = 0;
    }
    ops.pb({L, R});
//    cerr << L << ' ' << R << '\n';
//    for (int x: g) cerr << x << ' ';
//    cerr << '\n';
}

vi canon(string &s, vector<pii> &ops) {
//    cerr << s << '\n';
    auto g = gaps(s);
    if (k == 0) return g;
    int S = g.size();
    if (k >= S) return g;
    for (int i = S - 1; i >= k; --i) make_op(true, i - k, g, ops);
    if (k + 1 == S) {
        vi ng = g;
        make_op(true, 0, ng, ops);
        if (ng < g) g = ng;
        else ops.pop_back();
        return g;
    }
    int L = k;
    while (L - 2 >= 2) {
        make_op(false, 1, g, ops);
        make_op(true, 0, g, ops);
        L -= 2;
    }
    make_op(true, 1, g, ops);
    while (k % 2 && count(1 + all(g), 0) < S - 1) {
//        cerr << "here\n";
        make_op(true, 0, g, ops);
        make_op(false, 1, g, ops);
    }
    assert(ops.size() <= 2 * n);
    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

/*    int n, k;
    cin >> n >> k;
    vi init(n);
    forn(i, k) init[i] = 1;
    set<vi> vis = {init};
    map<vi, vi> prv;
    map<vi, pii> prvp;
    vvi q = {init};
    vi target = init;
    forn(cur, q.size()) {
        vi v = q[cur];
        if (vi(rall(v)) < vi(rall(target))) target = v;
        forn(i, n - k) forn(z, 2) {
            if (i > 1) continue;
            int j = i + k;
            auto u = v;
            reverse(u.begin() + i + 1, u.begin() + j);
            u[z ? j : i] = 0;
            u[z ? i : j] = v[i] | v[j];
            if (vis.count(u)) continue;
            vis.insert(u);
            prv[u] = v;
            prvp[u] = mp(i, z);
            q.pb(u);
        }
    }

    if (!vis.count(target)) {
        cout << "FAIL\n";
    } else {
        vvi path;
        vector<pii> ops;
        for (auto v = target; v != init; v = prv[v]) {
            path.pb(v);
            ops.pb(prvp[v]);
        }
        path.pb(init);
        reverse(all(path));
        reverse(all(ops));
        forn(i, ops.size()) {
            auto [p, z] = ops[i];
            cout << p << ' ' << z << ' ';
            for (int x: path[i]) cout << x;
            cout << '\n';
        }
        for (int x: path.back()) cout << x;
        cout << '\n';

    }*/

    
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        string s, t;
        cin >> s >> t;
        vector<pii> ops, opt;
        auto rs = canon(s, ops);
        auto rt = canon(t, opt);
        if (rs != rt) {
            cout << -1 << '\n';
        } else {
            cout << ops.size() + opt.size() << '\n';
            reverse(all(opt));
            for (auto [l, r]: ops) cout << l + 1 << ' ' << r << '\n';
            for (auto [l, r]: opt) cout << l + 1 << ' ' << r << '\n';
//            cout << 0 << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}