#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

#define y1 my1

using namespace std;

int n, k, s;
const int N = 170;
int dp[N][N * N / 2];
int a[N];

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d%d%d", &n, &k, &s);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n * (n + 1) / 2; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            for (int k = 0, maxk = i * (i + 1) / 2; k <= maxk; k++) {
                dp[j + 1][k + i - j] = min(dp[j + 1][k + i - j], dp[j][k] + a[i]);
            }
        }
    }
    int ans = INF;
    for (int i = 0; i <= min(n * (n + 1) / 2, s); i++) {
        ans = min(ans, dp[k][i]);
    }
    printf("%d\n", ans);
    return 0;
}