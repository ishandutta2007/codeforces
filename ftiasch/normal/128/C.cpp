#include <cstdio>
#include <cstring>

using namespace std;

const int MOD = 1000000007;

int mul(int a, int b) {
    return ((long long)a * b) % MOD;
}

int add(int a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) {
        a += MOD;
    }
    return a;
}

const int N = 1111;

int dp[N][N], sum[N][2];

int solve(int k, int n) {
    memset(dp, 0, sizeof(dp));
    for (int j = 1; j <= n; ++ j) {
        dp[0][j] = 1;
    }
    for (int i = 1; i <= k; ++ i) {
        sum[0][0] = sum[0][1] = 0;
        for (int j = 1; j <= n; ++ j) {
            dp[i][j] = sub(mul(j, sum[j - 1][0]), sum[j - 1][1]);
            sum[j][0] = add(sum[j - 1][0], dp[i - 1][j]);
            sum[j][1] = add(sum[j - 1][1], mul(dp[i - 1][j], j + 1));
        }
    }
    return dp[k][n];
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    printf("%d\n", mul(solve(k, n), solve(k, m)));
    return 0;
}