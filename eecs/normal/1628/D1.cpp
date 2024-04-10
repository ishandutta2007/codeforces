#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;
int T, n, m, K, f[2010][2010];

int main() {
    scanf("%d", &T);
    f[0][0] = 0;
    for (int i = 1; i <= 2000; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j) f[i][j] = (f[i - 1][j - 1] + 1) % P;
            else f[i][j] = 1LL * (P + 1) / 2 * (f[i - 1][j - 1] + f[i - 1][j]) % P;
        }
    }
    while (T--) {
        scanf("%d %d %d", &n, &m, &K);
        printf("%lld\n", 1LL * K * f[n][m] % P);
    }
    return 0;
}