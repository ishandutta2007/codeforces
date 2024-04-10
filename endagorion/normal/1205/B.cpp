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
    vi64 a(n);
    forn(i, n) cin >> a[i];
    vvi lst(60);
    forn(i, n) forn(j, 60) if ((a[i] >> j) & 1) lst[j].pb(i);

    bool have3 = false;
    forn(j, 60) if (lst[j].size() >= 3) have3 = true;
    if (have3) {
        cout << 3 << '\n';
        return 0;
    }
    set<pii> es;
    forn(j, 60) if (lst[j].size() == 2) {
        int x = lst[j][0], y = lst[j][1];
        if (x > y) swap(x, y);
        es.insert({x, y});
    }

    vvi e(n);
    for (auto w: es) {
        e[w.fi].pb(w.se);
        e[w.se].pb(w.fi);
    }

    int ans = 1e9;
    forn(v, n) for (int u: e[v]) {
        map<pii, int> dist;
        vector<pii> q = {{v, u}};
        dist[{v, u}] = 0;
        forn(cur, q.size()) {
            int a = q[cur].fi, b = q[cur].se;
            for (int c: e[b]) {
                if (a == c || dist.count({b, c})) continue;
                dist[{b, c}] = dist[{a, b}] + 1;
                q.pb({b, c});
            }
        }
        for (auto w: dist) if (w.fi.se == v) uin(ans, w.se + 1);
    }
    if (ans > 1e8) ans = -1;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}