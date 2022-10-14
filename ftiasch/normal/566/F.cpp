#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 1000000;

int dp[N + 1];

int main()
{
    int n;
    scanf("%d", &n);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++ i) {
        int a;
        scanf("%d", &a);
        dp[a] = 1;
    }
    for (int i = N; i >= 1; -- i) {
        if (dp[i]) {
            for (int j = i + i; j <= N; j += i) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }
    printf("%d\n", *std::max_element(dp, dp + N + 1));
    return 0;
}