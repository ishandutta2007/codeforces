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

const int maxn = 81;
int dp[maxn][maxn][maxn * maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    vi shs;
    forn(i, n) {
        int x;
        cin >> x;
        if (x) shs.pb(i);
    }

    int K = shs.size(), L = n - K;
    int bse = L * (L - 1) / 2;
    int UB = n * (n - 1) / 2;
    forn(i, n + 1) forn(j, n + 1) forn(t, UB + 1) dp[i][j][t] = 1e9;
    dp[0][0][0] = 0;
    forn(i, K) forn(j, n + 1) forn(t, UB + 1) {
        int val = dp[i][j][t];
        if (val > 1e8) continue;
        fore(nj, j, n - 1) {
            int nt = t + abs(shs[i] - nj);
            int ng = nj - j;
            uin(dp[i + 1][nj + 1][nt], val + ng * (ng - 1) / 2);
        }
    }

    vi ans(UB + 1, 1e9);
    forn(j, n + 1) forn(t, UB + 1) {
        int fg = n - j;
        uin(ans[t], dp[K][j][t] + fg * (fg - 1) / 2);
    }
    forn(t, UB) uin(ans[t + 1], ans[t]);
    forn(t, UB + 1) cout << bse - ans[t] << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}