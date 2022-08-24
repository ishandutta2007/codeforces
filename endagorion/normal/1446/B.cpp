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

const int maxn = 5100;
int dp[2][maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    forn(z, 2) forn(i, n) forn(j, m) dp[z][i][j] = -1e9;
    int ans = 0;
    forn(i, n) forn(j, m) if (s[i] == t[j]) dp[0][i][j] = 2;
    forn(i, n) forn(j, m) {
        if (i + 1 < n) {
            uax(dp[0][i + 1][j], dp[0][i][j] - 1);
            uax(dp[1][i + 1][j], dp[0][i][j] - 1);
        }
        if (j + 1 < m) {
            uax(dp[1][i][j + 1], dp[1][i][j] - 1);
            if (s[i] == t[j + 1]) uax(dp[0][i][j + 1], dp[1][i][j] + 3);
        }
    }

    forn(z, 2) forn(i, n) forn(j, m) uax(ans, dp[z][i][j]);
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}