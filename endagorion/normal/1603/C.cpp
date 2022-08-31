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

const int B = 500;
const i64 P = 998244353;
pi64 ldp[2][B + 1], sdp[2][B + 1];

pi64 add(pi64 a, i64 x) {
    (a.se += x * a.fi) %= P;
    return a;
}

pi64 operator+(pi64 a, const pi64 &b) {
    (a.fi += b.fi) %= P;
    (a.se += b.se) %= P;
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

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi a(n);
        forn(i, n) cin >> a[i];
        forn(z, 2) forn(i, B + 1) ldp[z][i] = sdp[z][i] = {0, 0};
        i64 ans = 0;
        ford(i, n - 1) {
            ++ldp[0][1].fi;
            for1(j, B) {
                if (ldp[0][j] == mp(0LL, 0LL)) continue;
                i64 v = a[i + 1] / j;
                int k = (a[i] - 1) / v + 1;
//                cerr << i << ' ' << j << ' ' << v << ' ' << ldp[0][j].fi << ' ' << ldp[0][j].se << ' ' << k << '\n';
                pi64 &to = (k <= B ? ldp[1][k] : sdp[1][a[i] / k]);
                to = to + add(ldp[0][j], k - 1);
            }
            for1(j, B) {
                if (sdp[0][j] == mp(0LL, 0LL)) continue;
                i64 v = j;
                int k = (a[i] - 1) / v + 1;
                pi64 &to = (k <= B ? ldp[1][k] : sdp[1][a[i] / k]);
                to = to + add(sdp[0][j], k - 1);
            }
            for1(j, B) {
                swap(sdp[0][j], sdp[1][j]); sdp[1][j] = {0, 0};
                swap(ldp[0][j], ldp[1][j]); ldp[1][j] = {0, 0};
                (ans += sdp[0][j].se + ldp[0][j].se) %= P;
            }
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}