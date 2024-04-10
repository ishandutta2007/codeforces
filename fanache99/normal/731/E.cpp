#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 200000;

long long sum[1 + MAXN];
long long dp[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        sum[i] = sum[i - 1] + x;
    }
    dp[n] = sum[n];
    for (int i = n - 1; i >= 2; i--)
        dp[i] = max(dp[i + 1], sum[i] - dp[i + 1]);
    printf("%I64d", dp[2]);
    return 0;
}