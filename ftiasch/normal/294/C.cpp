#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 1000;
const int MOD = 1000000000 + 7;

int n, m, binom[N + 1][N + 1], a[N];

int pow(int a, int n, int m) {
    int ret = 1 % m;
    while (n) {
        if (n & 1) {
            ret = (long long)ret * a % m;
        }
        a = (long long)a * a % m;
        n >>= 1;
    }
    return ret;
}


int main() {
    scanf("%d%d", &n, &m);
    memset(binom, 0, sizeof(binom));
    for (int i = 0; i <= n; ++ i) {
        binom[i][0] = 1;
        for (int j = 1; j <= i; ++ j) {
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
        }
    }
    for (int i = 0; i < m; ++ i) {
        scanf("%d", a + i);
    }
    std::sort(a, a + m);
    int ret = 1 % MOD;
    for (int i = 0; i + 1 < m; ++ i) {
        ret = (long long)ret * pow(2, std::max(a[i + 1] - a[i] - 2, 0), MOD) % MOD;
    }
    int total = n - m;
    for (int i = 0; i <= m; ++ i) {
        int size = std::max((i < m ? a[i] : n + 1) - (i ? a[i - 1] : 0) - 1, 0);
        if (size > 0) {
            ret = (long long)ret * binom[total][size] % MOD;
            total -= size;
        }
    }
    printf("%d\n", ret);
    return 0;
}