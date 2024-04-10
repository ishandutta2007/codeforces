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

    srand(time(0));

    int n;
    cin >> n;
    vi64 a(n);
    forn(i, n) cin >> a[i];

    i64 ans = 1e18;
    forn(k, 30) {
        int i = 0;
        forn(j, 30) i = (2 * i + (rand() & 1)) % n;
        fore(d, -2, 2) {
            i64 x = a[i] + d;
            if (x < 0) continue;
            vi64 ps;
            for (i64 p = 2; p * p <= x; ++p) {
                if (x % p == 0) {
                    ps.pb(p);
                    while (x % p == 0) x /= p;
                }
            }
            if (x > 1) ps.pb(x);
            for (i64 p: ps) {
                i64 res = 0;
                forn(i, n) {
                    i64 t = a[i] % p;
                    if (t == a[i]) res += p - a[i];
                    else res += min(t, p - t);
                }
                uin(ans, res);
            }
        }
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}