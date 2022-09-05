#include <bits/stdc++.h>
using namespace std;

const int maxn = 1510, maxk = 100010, P = 1000000007;
int n, m, pa, pb, p, K, ans, q[maxn], g[maxn][maxn], s[maxn][maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d %d %d %d", &n, &m, &pa, &pb, &K);
    p = 1LL * pa * qp(pb, P - 2) % P;
    for (int i = 0, j = 1; i <= min(m, K); i++) {
        q[i] = 1LL * j * qp(p, i) % P * qp(P + 1 - p, K - i) % P;
        j = 1LL * j * (K - i) % P * qp(i + 1, P - 2) % P;
    }
    g[0][m] = s[0][m] = 1;
    for (int i = 1; i <= n; i++) {
        int s1 = 0, s2 = 0;
        for (int j = 1; j <= m; j++) {
            (s1 += q[j - 1]) %= P;
            s2 = (s2 + 1LL * q[j - 1] * s[i - 1][j - 1]) % P;
            g[i][j] = 1LL * q[m - j] * (1LL * (s[i - 1][m] - s[i - 1][m - j] + P)
                * s1 % P - s2 + P) % P;
            s[i][j] = (s[i][j - 1] + g[i][j]) % P;
        }
    }
    printf("%d\n", s[n][m]);
    return 0;
}