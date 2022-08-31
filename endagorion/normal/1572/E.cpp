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

struct TPoint {
    i64 x, y;

    TPoint operator-(const TPoint &p) const {
        return {x - p.x, y - p.y};
    }

    i64 operator%(const TPoint &p) const {
        return x * p.y - y * p.x;
    }
};

const int maxn = 201;

int n, k;

TPoint p[maxn];
pi64 dp[maxn][maxn];

int maxcuts(i64 S) {
    forn(i, n + 1) forn(j, n + 1) dp[i][j] = {-1e9, -1e9};
    for (int l = n - 1; l >= 0; --l) {
        dp[l][l + 1] = {0, 0};
        for (int r = l + 1; r <= n; ++r) {
            for (int rr = r + 1; rr <= n; ++rr) {
                i64 cs = dp[l][r].fi + dp[r][rr].fi;
                i64 maxs = dp[l][r].se + dp[r][rr].se + (p[r] - p[l]) % (p[rr] - p[l]);
                if (maxs >= S) {
                    ++cs;
                    maxs = 0;
                }
                uax(dp[l][rr], mp(cs, maxs));
            }
        }
    }
//    cerr << S << ' ' << dp[0][n].fi << ' ' << dp[0][n].se << '\n';
    return dp[0][n].fi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> k;
    forn(i, n) cin >> p[i].x >> p[i].y;
    p[n] = p[0];

    i64 L = 0, R = 1e18;
    while (R - L > 1) {
        i64 M = (L + R) / 2;
        (maxcuts(M) <= k ? R : L) = M;
    }
    cout << L << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}