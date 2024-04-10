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

const i64 P = 998244353;

i64 deg(i64 x, i64 d) {
    x %= P;
    d %= P - 1;
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        d /= 2;
        (x *= x) %= P;
    }
    return y;
}

pi64 operator+(pi64 a, pi64 b) {
    if (a.fi != b.fi) return max(a, b);
    return {a.fi, (a.se + b.se) % P};
}

pi64 operator*(pi64 a, pi64 b) {
    return {a.fi + b.fi, a.se * b.se % P};
}

i64 cnk(int n, int k) {
    i64 ans = 1;
    n %= P;
    forn(i, k) {
        (ans *= n - i) %= P;
        (ans *= deg(i + 1, -1)) %= P;
    }
    return ans;
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
    vi64 x(n + 1);
    cin >> x[0];
    forn(i, n) {
        i64 d;
        cin >> d;
        x[i + 1] = x[i] + d;
    }
    vi64 xs(all(x));
    sort(all(xs));
    xs.erase(unique(all(xs)), xs.end());
//    for (int y: xs) cerr << y << ' ';
//    cerr << '\n';
    vi64 is(x.size());
    forn(i, x.size()) is[i] = find(all(xs), x[i]) - xs.begin();

    vector<vector<pi64> > ev(xs.size() - 1, vector<pi64>(n + 1));

    forn(i, ev.size()) forn(j, n + 1) {
        i64 res = 0;
        i64 m = xs[i + 1] - xs[i];
        forn(k, j + 1) (res += cnk(j, k) * cnk(m + k - 1, j)) %= P;
        ev[i][j] = mp(m, res);
//        cerr << "E " << m << ' ' << j << ' ' << res << '\n';
    }

    vi64 dis = {is[0]};
    for1(i, n) {
        int from = is[i - 1], to = is[i];
        while (from < to) dis.pb(++from);
        while (from > to) dis.pb(--from);
    }

    vector<pi64> dp(dis.size(), mp(1, 1));
    forn(i, dis.size()) {
        int A = 0;
        ford(j, i) {
            if (dis[j] >= dis[i] && dis[j + 1] < dis[i]) ++A;
            if (dis[i] == dis[j] + 1) dp[i] = dp[i] + dp[j] * ev[dis[j]][A];
        }
//        cerr << xs[dis[i]] << ' ' << dp[i].fi << ' ' << dp[i].se << ' ' << A << '\n';
    }

    pi64 ans = mp(0, 0);
    for (auto p: dp) ans = ans + p;
    if (ans.fi == 1) ans.se = (x[0] - x.back() + 1) % P;
    if (ans.se < 0) ans.se += P;
    cout << ans.fi << ' ' << ans.se << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}