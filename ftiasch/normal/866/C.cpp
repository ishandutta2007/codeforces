#include <algorithm>
#include <cstdio>

const int N = 50;
const int M = (N + 1) * 100;

int n, m, f[N], s[N], p[N];
double dp[N + 1][5101];

int main()
{
#ifdef LOCAL_JUDGE
    freopen("C.in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d%d", f + i, s + i, p + i);
    }
    int max = m + 100;
    double low = 0.;
    double high = 1e9;
    for (int _ = 0; _ < 100; ++ _) {
        double reset = 0.5 * (low + high);
        for (int j = 0; j <= max; ++ j) {
            dp[n][j] = j <= m ? 0 : reset;
        }
        for (int i = n - 1; i >= 0; -- i) {
            for (int j = 0; j <= m; ++ j) {
                dp[i][j] = std::min((p[i] * (f[i] + dp[i + 1][j + f[i]]) + (100 - p[i]) * (s[i] + dp[i + 1][j + s[i]])) / 100.0, reset);
            }
            for (int j = m + 1; j <= max; ++ j) {
                dp[i][j] = reset;
            }
        }
        if (dp[0][0] < reset) {
            high = reset;
        } else {
            low = reset;
        }
    }
    printf("%.9f\n", 0.5 * (low + high));
}