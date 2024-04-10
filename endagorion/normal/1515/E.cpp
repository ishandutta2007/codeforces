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

const int maxn = 801;
int n, P;
i64 cnk[maxn][maxn];
i64 dp[maxn][maxn];
i64 d2[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> P;
    cnk[0][0] = 1;
    forn(i, 2 * n) forn(j, i + 1) forn(k, 2) (cnk[i + 1][j + k] += cnk[i][j]) %= P;
    d2[0] = 1;
    forn(i, 2 * n) d2[i + 1] = d2[i] * 2 % P;

    dp[0][0] = 1;
    forn(i, n + 1) forn(k, i + 1) for1(j, n - i + 1) {
        (dp[i + j + 1][k + j] += dp[i][k] * cnk[k + j][j] % P * d2[j - 1]) %= P;
    }

    i64 ans = 0;
    forn(j, n + 2) (ans += dp[n + 1][j]) %= P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}