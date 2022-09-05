#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010, P = 998244353;
int n, m, K, f[maxn][maxn];

int main() {
    scanf("%d %d %d", &n, &m, &K);
    f[1][0] = m;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= K; j++) {
            (f[i][j] += f[i - 1][j]) %= P;
            f[i][j + 1] = (f[i][j + 1] + 1LL * (m - 1) * f[i - 1][j]) % P;
        }
    }
    printf("%d\n", f[n][K]);
    return 0;
}