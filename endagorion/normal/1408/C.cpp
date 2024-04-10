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
    cout.precision(15);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    while (T--) {
        int n, l;
        cin >> n >> l;
        vi a(n);
        forn(i, n) cin >> a[i];
        ld x0 = 0, v0 = 1.0;
        ld x1 = l, v1 = 1.0;
        int p0 = 0, p1 = n - 1;
        ld ans = 0.0;
        while (1) {
            ld tt = (x1 - x0) / (v0 + v1);
            int type = 0;
            if (p0 < n) {
                ld nt = (a[p0] - x0) / v0;
                if (uin(tt, nt)) type = 1;
            }
            if (p1 >= 0) {
                ld nt = (x1 - a[p1]) / v1;
                if (uin(tt, nt)) type = 2;
            }
            ans += tt;
            x0 += v0 * tt;
            x1 -= v1 * tt;
            if (type == 0) break;
            if (type == 1) ++p0, v0 += 1;
            else --p1, v1 += 1;
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}