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

const int maxn = 1100000;
i64 a[maxn], cost[maxn][2];
i64 dp[maxn];
i64 suf1[maxn];
i64 r[3];
i64 D;

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
    forn(i, 3) cin >> r[i];
    cin >> D;
    forn(i, n) {
        cin >> a[i];
        cost[i][0] = a[i] * r[0] + r[2];
        cost[i][1] = min(r[1], (a[i] + 1) * r[0]) + r[0];
        uin(cost[i][0], cost[i][1] + 2 * D);
    }
    forn(i, n) suf1[i + 1] = suf1[i] + cost[n - i - 1][1];
    forn(i, n + 1) dp[i] = 1e18;
    dp[0] = 0;
    forn(i, n) {
        uin(dp[i + 1], dp[i] + cost[i][0] + D);
        if (i + 2 <= n) uin(dp[i + 2], dp[i] + cost[i][1] + cost[i + 1][1] + 4 * D);
    }

    i64 ans = dp[n] - D;
    forn(i, n) uin(ans, dp[i] + suf1[n - i] + 2 * (n - i - 1) * D + cost[n - 1][0] - cost[n - 1][1]);
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}