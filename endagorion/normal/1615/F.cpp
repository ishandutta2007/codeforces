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

const int maxn = 2100;
const i64 P = 1000000000 + 7;
pi64 dp[maxn][2 * maxn];

void add(i64 &x, i64 y) {
    x += y;
    if (x >= P) x -= P;
}

pi64 operator+(pi64 a, pi64 b) {
    add(a.fi, b.fi);
    add(a.se, b.se);
    return a;
}

pi64 add(pi64 a, i64 x) {
    (a.fi += x * a.se) %= P;
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
        string s, t;
        cin >> n;
        cin >> s >> t;
        forn(i, n) {
            if (!(i & 1)) continue;
            if (s[i] != '?') s[i] ^= 1;
            if (t[i] != '?') t[i] ^= 1;
        }
//        cout << s << ' ' << t << '\n';
        forn(i, n + 1) forn(j, 2 * n + 1) dp[i][j] = mp(0, 0);
        dp[0][n] = mp(0, (P + 1) / 2);
        forn(i, n) fore(b, n - i, n + i) {
            if (dp[i][b] == mp(0LL, 0LL)) continue;
//            cout << i << ' ' << b - n << ' ' << dp[i][b].fi << ' ' << dp[i][b].se << '\n';
            forn(x, 2) forn(y, 2) {
                if (s[i] - '0' == (x ^ 1)) continue;
                if (t[i] - '0' == (y ^ 1)) continue;
                int nb = b + ((x ? 1 : -1) - (y ? 1 : -1)) / 2;
//                cout << i << ' ' << b - n << ' ' << x << ' ' << y << ' ' << nb - n << '\n';
                dp[i + 1][nb] = dp[i + 1][nb] + add(dp[i][b], ((abs(b - n) + abs(nb - n))));
            }
        }
        cout << dp[n][n].fi << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}