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

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int maxn = 550;
int n;
int c[maxn];
int dp[maxn][maxn];

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", c + i);
    }
    for (int i = 0; i < n; i++) {
        dp[i][i + 1] = 1;
    }
    for (int i = 0; i + 1 < n; i++) {
        dp[i][i + 2] = (c[i] == c[i + 1] ? 1 : 2);
    }
    for (int l = 3; l <= n; l++) {
        for (int i = 0; i + l <= n; i++) {
            int j = i + l;
            dp[i][j] = (c[i] == c[j - 1] ? dp[i + 1][j - 1] : INF);
            for (int k = i + 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    printf("%d\n", dp[0][n]);
    return 0;
}