#include <bits/stdc++.h>
using namespace std;

const int maxn = 210;
int n, d, P;
long long ans, binom[maxn][maxn], f[maxn][maxn], s[maxn][maxn];

int main() {
    scanf("%d %d %d", &n, &d, &P);
    for (int i = 0; i <= n; i++) {
        for (int j = binom[i][0] = 1; j <= i; j++) {
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % P;
        }
    }
    fill(s[1], s[1] + d + 1, f[1][0] = 1);
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= d; j++) {
            for (int k = 1; k < i; k++) {
                f[i][j] = (f[i][j] + f[i - k][j - 1] * s[k][d - 1] % P * binom[i - 2][k - 1]) % P;
            }
            s[i][j] = (s[i][j - 1] + f[i][j]) % P;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= d; j++) {
            for (int k = 0; j + k <= d; k++) if (k ^ 1) {
                ans = (ans + f[i + 1][j] * f[n - i][k]) % P;
            }
        }
    }
    printf("%lld\n", 2LL * n * (n - 1) * ans % P);
    return 0;
}