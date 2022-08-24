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

const int maxn = 210000, maxk = 2100, LOG = 21;
const i64 P = 1000000000 + 7;
i64 fact[maxn + 1], tcaf[maxn + 1];

i64 deg(i64 x, i64 d) {
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

i64 cnk(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * tcaf[k] % P * tcaf[n - k] % P;
}

vi64 dp[maxk];

void add(i64 &x, i64 y) {
    x += y;
    if (x >= P) x -= P;
    assert(x < P);
}

vi64 operator+(vi64 a, const vi64 &b) {
    forn(i, a.size()) add(a[i], b[i]);
    return a;
}

vi64 operator*(vi64 a, i64 x) {
    for (auto &y: a) (y *= x) %= P;
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    fact[0] = 1;
    for1(i, maxn) fact[i] = i * fact[i - 1] % P;
    tcaf[maxn] = deg(fact[maxn], -1);
    ford(i, maxn) tcaf[i] = tcaf[i + 1] * (i + 1) % P;

    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<pii> p(k + 2);
    forn(i, k) {
        cin >> p[i].fi >> p[i].se;
        --p[i].fi; --p[i].se;
    }
    p.back() = mp(n - 1, m - 1);
    sort(all(p));

    dp[0] = vi64(LOG);
    dp[0][0] = 1;

    for1(i, k + 1) {
        dp[i] = vi64(LOG);

        for1(ii, i - 1) {
            ford(j, LOG - 1) add(dp[i][j + 1], dp[i][j]);
            if (p[ii].fi > p[i].fi || p[ii].se > p[i].se) continue;
            forn(j, LOG) add(dp[i][j], dp[ii][j] * cnk(p[i].fi - p[ii].fi + p[i].se - p[ii].se, p[i].fi - p[ii].fi) % P);
        }

        forn(j, LOG) {
            dp[i][j] = (cnk(i - 1, j) * cnk(p[i].fi + p[i].se, p[i].fi) % P - dp[i][j] + P) % P;
        }

//        cerr << i << '\n';
//        forn(j, LOG) cerr << dp[i][j] << ' ';
//        cerr << '\n';
    }

    auto res = dp[k + 1];
    forn(j, LOG) {
        fore(jj, j + 1, LOG - 1) {
            add(res[jj], P - res[j] * cnk(k - j, jj - j) % P);
        }
//        cerr << j << ' ' << res[j] << '\n';
    }

    i64 ans = cnk(n + m - 2, n - 1);
    forn(j, LOG) {
        add(ans, (s - 1) * res[j] % P);
        s = (s + 1) / 2;
    }
    assert(s == 1);
    (ans *= deg(cnk(n + m - 2, n - 1), -1)) %= P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}