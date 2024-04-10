#include <cassert>
#include <cstdio>
#include <cstring>

const int N = 2000;
const int MOD = (int)1e9 + 7;

int partition[N + 1][N + 1], factorial[N + 1], binom[N + 1][N + 1];

int main() {
    memset(partition, 0, sizeof(partition));
    partition[0][0] = 1;
    for (int i = 1; i <= N; ++ i) {
        for (int j = 1; j <= i; ++ j) {
            partition[i][j] = (partition[i - j][j - 1] + partition[i - j][j]) % MOD;
        }
    }
    factorial[0] = 1;
    for (int i = 1; i <= N; ++ i) {
        factorial[i] = (long long)factorial[i - 1] * i % MOD;
    }
    memset(binom, 0, sizeof(binom));
    for (int i = 0; i <= N; ++ i) {
        binom[i][0] = 1;
        for (int j = 1; j <= i; ++ j) {
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
        }
    }
    int tests;
    scanf("%d", &tests);
    while (tests --) {
        int n, k;
        scanf("%d%d", &n, &k);
        int result = 0;
        for (int sum = (k - 1) * k / 2; sum + k <= n; ++ sum) {
            result += (long long)partition[sum + k][k] * binom[n - sum][k] % MOD;
            if (result >= MOD) {
                result -= MOD;
            }
        }
        printf("%d\n", (int)((long long)result * factorial[k] % MOD));
    }
    return 0;
}