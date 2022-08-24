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

const int maxa = 1000101;
int mind[maxa + 1];
vi ps;

const int maxn = 150000;
int par[maxn + maxa + 1];
int a[maxn];

int root(int v) {return v == par[v] ? v : par[v] = root(par[v]);}

void unite(int u, int v) {  
    u = root(u); v = root(v);
    if (u == v) return;
    par[v] = u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    forn(i, maxa) mind[i] = i;
    fore(i, 2, maxa) {
        if (mind[i] == i) ps.pb(i);
        for (i64 p: ps) {
            if (p > mind[i]) break;
            if (p * i > maxa) break;
            uin(mind[i * p], (int)p);
        }
    }

    int n, q;
    cin >> n >> q;
    forn(i, n + maxa + 1) par[i] = i;
    forn(i, n) {
        cin >> a[i];
        for (int x = a[i]; x > 1; x /= mind[x]) {
            unite(i, n + mind[x]);
        }
    }

    vector<pii> qs(q);
    vi ans(q, 2);
    forn(i, q) {
        int s, t;
        cin >> s >> t;
        --s; --t;
        qs[i] = {s, t};
        if (root(s) == root(t)) ans[i] = 0;
    }

    vector<pii> con;
    forn(i, n) {
        vi rs = {root(i)};
        for (int x = a[i] + 1; x > 1; x /= mind[x]) rs.pb(root(n + mind[x]));
        sort(all(rs));
        rs.erase(unique(all(rs)), rs.end());
        forn(x, rs.size()) forn(y, x) con.pb({rs[y], rs[x]});
    }
    sort(all(con));
    con.erase(unique(all(con)), con.end());

    forn(i, q) {
        pii p = {root(qs[i].fi), root(qs[i].se)};
        if (p.fi > p.se) swap(p.fi, p.se);
        auto it = lower_bound(all(con), p);
        if (it != con.end() && *it == p) uin(ans[i], 1);
    }
    for (int x: ans) cout << x << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}