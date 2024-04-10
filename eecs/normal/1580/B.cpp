#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, m, K, P, binom[maxn][maxn], f[maxn][maxn][maxn], fact[maxn];

inline int solve(int n, int m, int K) {
    if (K > n) return 0;
    if (m < 0 || m > n) return !K ? fact[n] : 0;
    if (!n) return !K;
    if (~f[n][m][K]) return f[n][m][K];
    int ans = 0;
    for (int i = 1; i + i <= n + 1; i++) {
        int t = m == 1;
        for (int j = 0; j <= K - t; j++) {
            ans = (ans + 1LL * (1 + (i + i <= n)) * binom[n - 1][i - 1] *
                solve(i - 1, m - 1, j) % P * solve(n - i, m - 1, K - t - j)) % P;
        }
    }
    return f[n][m][K] = ans;
}

int main() {
    scanf("%d %d %d %d", &n, &m, &K, &P);
    for (int i = 0; i <= n; i++) {
        for (int j = binom[i][0] = 1; j <= i; j++) {
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % P;
        }
    }
    for (int i = fact[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
    }
    memset(f, -1, sizeof(f));
    printf("%d\n", solve(n, m, K));
    return 0;
}