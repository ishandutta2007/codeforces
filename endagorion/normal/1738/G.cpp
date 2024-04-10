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

const int maxn = 1020;
using bs = bitset<maxn>;

int a[maxn][maxn];
int dp[maxn][maxn];

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
        int n, k;
        cin >> n >> k;
        --k;
        forn(i, n) {
            string s;
            cin >> s;
            forn(j, n) a[i][j] = int(s[j] == '0');
        }

        forn(i, n) forn(j, n) dp[i][j] = 0;

        forn(i, k) forn(j, k - i) {
            dp[i][n - j - 1] = i + 1;
            dp[n - i - 1][j] = j + 1;
        }

        forn(i, n) forn(j, n) {
            if (i) uax(dp[i][j], dp[i - 1][j]);
            if (j) uax(dp[i][j], dp[i][j - 1]);
            int pv = (i && j ? dp[i - 1][j - 1] : 0);
            uax(dp[i][j], pv + a[i][j]);
        }

//        forn(i, n) forn(j, n) cerr << dp[i][j] << " \n"[j + 1 == n];

        if (dp[n - 1][n - 1] > k) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        forn(i, n) forn(j, n) {
            int pv = (i && j ? dp[i - 1][j - 1] : 0);
            cout << int(dp[i][j] > pv);
            if (j + 1 == n) cout << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}