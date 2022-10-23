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

const i64 P = 1000000000 + 7;
const int maxn = 101;
i64 dp[2][maxn][maxn][maxn];
int cnk[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m, k;
    cin >> n >> m >> k;
    n /= 2;

    cnk[0][0] = 1;
    forn(i, n) forn(j, i + 1) forn(z, 2) uin(cnk[i + 1][j + z] += cnk[i][j], k + 1);

    i64 ans = 0;
    forn(i, m - 1) {
        for1(t, n) ++dp[0][t][t][k];
        for1(t, n) for1(l, n) for1(x, k) {
            i64 V = dp[0][t][l][x];
            if (!V) continue;
            (ans += V) %= P;
            for1(nl, n - l) {
                i64 ways = cnk[l + nl - 1][l - 1];
                if (ways > x) continue;
                (dp[1][t + nl][nl][x / ways] += V) %= P;
            }
        }

        for1(t, n) for1(l, n) for1(x, k) {
            dp[0][t][l][x] = dp[1][t][l][x];
            dp[1][t][l][x] = 0;
        }
    }

    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}