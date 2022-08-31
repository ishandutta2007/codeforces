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

const int maxn = 17;
int a[1 << maxn];
int dp[maxn + 1][1 << maxn][2][2];

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
    forn(i, k) {
        int x;
        cin >> x;
        a[x - 1] = 1;
    }

    for1(k, n) forn(i, 1 << (n - k)) forn(a, 2) forn(b, 2) dp[k][i][a][b] = -1e9;
    forn(i, 1 << (n - 1)) {
        dp[1][i][a[2 * i]][a[2 * i + 1]] = dp[1][i][a[2 * i + 1]][a[2 * i]] = a[2 * i] | a[2 * i + 1];
    }

    fore(k, 2, n) forn(i, 1 << (n - k)) {
        forn(a, 2) forn(b, 2) forn(c, 2) forn(d, 2) {
            forn(x, 2) forn(y, 2) {
                int res = dp[k - 1][2 * i][a][b] + dp[k - 1][2 * i + 1][c][d];
                res += (a | c);
                int e = (x ? a : c);
                res += (b | d);
                int f = (y ? b : d);
                res += (e | f);
                uax(dp[k][i][a + c - e][max(e, f)], res);
            }
        }
    }

    int ans = 0;
    forn(a, 2) forn(b, 2) uax(ans, dp[n][0][a][b] + max(a, b));
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}