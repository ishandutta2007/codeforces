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

    int n, k;
    cin >> n >> k;
    --k;
    vi x(n + 1), y(n + 1);
    forn(i, n + 1) cin >> x[i];
    cin >> y[n];
    
    ld ans = 1e9;
    if (k == n) {
        sort(all(x) - 1);
        forn(i, n) uin(ans, hypot(x[i] - x[n], y[n]) + x[n - 1] - x[0] + min(abs(x[i] - x[0]), abs(x[n - 1] - x[i])));
    } else {
        int xk = x[k];
        sort(all(x) - 1);
        k = find(all(x), xk) - x.begin();
        ans = hypot(x[k] - x[n], y[n]) + hypot(min(abs(x[n] - x[0]), abs(x[n] - x[n - 1])), y[n]) + x[n - 1] - x[0];
        int alen = x[n - 1] - x[0];
        forn(i, n) {
            uin(ans, alen + x[k] - x[0] + hypot(x[n - 1] - x[n], y[n]));
            uin(ans, alen + x[n - 1] - x[k] + hypot(x[0] - x[n], y[n]));
        }
        for1(i, k) {
            int fhl = x[n - 1] - x[i];
            ld fhres = fhl + min(x[n - 1] - x[k] + hypot(x[i] - x[n], y[n]), x[k] - x[i] + hypot(x[n - 1] - x[n], y[n]));
            ld shres = hypot(x[i - 1] - x[n], y[n]) + x[i - 1] - x[0];
            uin(shres, hypot(x[0] - x[n], y[n]) + x[i - 1] - x[0]);
            uin(ans, fhres + shres);
        }
        fore(i, k, n - 2) {
            int fhl = x[i] - x[0];
            ld fhres = fhl + min(x[i] - x[k] + hypot(x[0] - x[n], y[n]), x[k] - x[0] + hypot(x[i] - x[n], y[n]));
            ld shres = hypot(x[i + 1] - x[n], y[n]) + x[n - 1] - x[i + 1];
            uin(shres, hypot(x[n - 1] - x[n], y[n]) + x[n - 1] - x[i + 1]);
            uin(ans, fhres + shres);
        }
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}