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

    int n, m1, m2, t;
    cin >> n >> m1 >> m2 >> t;
    vector<pii> p(m1 + m2);
    forn(i, m1 + m2) {
        cin >> p[i].fi;
        p[i].se = int(i >= m1);
    }

    vi xs = {0, n + 1};
    for (auto [x, y]: p) {
        xs.pb(x); xs.pb(x + 1);
    }
    sort(all(xs));
    xs.erase(unique(all(xs)), xs.end());

    vvi a(2, vi(xs.size()));
    for (auto [x, y]: p) {
        x = lower_bound(all(xs), x) - xs.begin();
        a[y][x] = 1;
    }

    const int INF = 1.1e9;
    vvi cl(2, vi(xs.size(), INF));
    ford(x, xs.size() - 1) forn(y, 2) {
        cl[y][x] = (a[y][x + 1] ? x + 1 : cl[y][x + 1]);
    }

    vvi dp(2, vi(xs.size(), INF));
    vector<vector<pii> > prv(2, vector<pii>(xs.size()));
    vvi sh(2, vi(xs.size(), -1));
    dp[0][0] = t;

    forn(x, xs.size() - 1) {
        forn(y, 2) if (!a[y][x]) {
            if (uin(dp[y][x], max(dp[y ^ 1][x], xs[x]))) {
                prv[y][x] = {x, y ^ 1};
                sh[y][x] = -1;
            }
        }
/*        forn(y, 2) {
            if (dp[x][y] < 1.5e9) cerr << xs[x] << ' ' << y << ' ' << dp[x][y] << ' ' << xs[prv[x][y].fi] << ' ' << prv[x][y].se << ' ' << sh[x][y] << '\n';
        }*/
        forn(y, 2) {
            if (!a[y][x + 1]) {
                if (uin(dp[y][x + 1], max(dp[y][x], xs[x + 1]))) {
                    prv[y][x + 1] = {x, y};
                    sh[y][x + 1] = -1;
                }
            }
            if (cl[y][x] <= n && xs[cl[y][x]] > dp[y][x]) {
                if (uin(dp[y][cl[y][x]], dp[y][x] + t)) {
                    prv[y][cl[y][x]] = {x, y};
                    sh[y][cl[y][x]] = dp[y][x];
                }
            }
        }
    }

    int fy = -1;
    forn(y, 2) if (dp[y].back() < INF) fy = y;;
    if (fy == -1) {
        cout << "No\n";
    } else {
        int x = xs.size() - 1, y = fy;
        vi chs;
        vector<pii> shs;
        while (mp(x, y) != mp(0, 0)) {
            auto [px, py] = prv[y][x];
            if (x == px) chs.pb(xs[x]);
            if (sh[y][x] != -1) shs.pb(mp(sh[y][x], y));
            x = px, y = py;
        }
        sort(all(chs));
        sort(all(shs));
        cout << "Yes\n";
        cout << chs.size() << '\n';
        for (int x: chs) cout << x << ' ';
        cout << '\n';
        cout << shs.size() << '\n';
        for (auto [x, y]: shs) cout << x << ' ' << y + 1 << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}