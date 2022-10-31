#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-10;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 555;
const int MOD = 1e9 + 7;

int n, m;
char s[N][N];
ll dp[N][N], ndp[N][N];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf(" %s", s[i]);
//        cout << s[i] << endl;
    }
    dp[0][n - 1] = (s[0][0] == s[n - 1][m - 1]);
    for (int k = 1; k <= (n + m - 2) / 2; k++) {
        for (int i = 0; i <= k; i++) {
            int j = k - i;
            if (i < n && j < m) {
                for (int i2 = 0; i2 <= k; i2++) {
                    int j2 = k - i2;
                    if (i2 < n && j2 < m) {
                        int i3 = n - 1 - i2;
                        int j3 = m - 1 - j2;
                        ndp[i][i3] = 0;
                        if (s[i][j] == s[i3][j3]) {
                            if (i > 0) {
                                ndp[i][i3] += dp[i - 1][i3] + dp[i - 1][i3 + 1];
                            }
                            ndp[i][i3] += dp[i][i3] + dp[i][i3 + 1];
                            ndp[i][i3] %= MOD;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = ndp[i][j];
            }
        }
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << dp[i][j] << ' ';
//        }
//        cout << endl;
//    }
    ll ans = 0;
    if ((n + m) % 2 == 0) {
        for (int i = 0; i < n; i++) {
            ans += dp[i][i];
        }
    } else {
        for (int i = 0; i < n; i++) {
            ans += dp[i][i] + dp[i][i + 1];
        }
    }
    ans %= MOD;
    printf("%d\n", (int) ans);
    return 0;
}