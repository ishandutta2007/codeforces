#include <bits/stdc++.h>
using namespace std;
    
const int maxn = 410;
int T, P, f[maxn], g[maxn][maxn], h[maxn], fact[maxn];

int main() {
    scanf("%d %d", &T, &P);
    // A(x) = x - \sum_{k >= 2} k! * A(x)^k
    int n = 400;
    for (int i = fact[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
    }
    f[1] = 1, g[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= i; j++) {
            for (int k = 1; k < i; k++) {
                g[j][i] = (g[j][i] + 1LL * g[j - 1][k] * f[i - k]) % P;
            }
        }
        for (int j = 2; j <= i; j++) {
            f[i] = (f[i] - 1LL * g[j][i] * fact[j] % P + P) % P;
        }
        g[1][i] = f[i];
        for (int j = 1; j <= i; j++) {
            for (int k = 1; j + k <= i; k++) {
                g[i + 1][j + k] = (g[i + 1][j + k] + 1LL * g[i][j] * f[k]) % P;
            }
        }
    }
    while (T--) {
        scanf("%d", &n);
        if (n == 2) puts("2");
        else printf("%d\n", (P - f[n] + (n & 1 ? 2 : P - 2)) % P);
    }
    return 0;
}