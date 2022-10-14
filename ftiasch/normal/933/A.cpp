#include <algorithm>
#include <cstdio>

int main()
{
    int n, i, j, dp[5] {0};
    scanf("%d", &n);
    for (i = 0; i < n; ++ i) {
        scanf("%d", &j);
        dp[j] ++, dp[j + 2] ++;
        for (j = 2; j < 5; ++ j) {
            dp[j] = std::max(dp[j - 1], dp[j]);
        }
    }
    printf("%d\n", dp[4]);
}