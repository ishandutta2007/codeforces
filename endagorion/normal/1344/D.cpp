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
    i64 s;
    cin >> n >> s;
    vi64 a(n);
    forn(i, n) cin >> a[i];
    i64 L = -3.1e18, R = 3.1e18;
    while (R - L > 1) {
        i64 M = (L + R) / 2;
        i64 cnt = 0;
        for (i64 x: a) {
            if (x <= M) continue;
            unsigned long long d = 4ULL * (x - M) - 1;
            if (d < 0) continue;
            i64 t = sqrt(d / 3.0);
            while (3ULL * t * t > d) --t;
            while (3ULL * t * t <= d) ++t;
            --t;
            cnt += min(x, (t + 1) / 2);
        }
//        cerr << M << ' ' << cnt << '\n';
        (cnt >= s ? L : R) = M;
    }

    vi64 b(n);
    vi inc;
    forn(i, n) {
        i64 x = a[i];
        i64 &t = b[i];
        if (x > R) {
            unsigned long long d = 4ULL * (x - R) - 1;
            t = sqrt(d / 3.0);
            while (3ULL * t * t > d) --t;
            while (3ULL * t * t <= d) ++t;
            --t;
            t = (t + 1) / 2;
            uin(t, x);
        }
        if (t < x && a[i] - 3 * t * t - 3 * t - 1 == L) inc.pb(i);
        s -= t;
    }

//    cerr << R << ' ' << s << ' ' << inc.size() << '\n';

    assert(inc.size() >= s);
    forn(i, s) ++b[inc[i]];
    for (i64 x: b) cout << x << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}