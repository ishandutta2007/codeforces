#include <algorithm>
#include <cstdio>

const int N = 50;

int a[N], dp[N + 1][2];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
    }
    dp[n][0] = dp[n][1] = 0;
    int s = 0;
    for (int i = n - 1; i >= 0; -- i) {
        for (int j = 0; j < 2; ++ j) {
            dp[i][j] = std::max(dp[i + 1][j], s - dp[i + 1][j ^ 1] + a[i]);
        }
        s += a[i];
    }
    printf("%d %d\n", s - dp[0][1], dp[0][1]);
}