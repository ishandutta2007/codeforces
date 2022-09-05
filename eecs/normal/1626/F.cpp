#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000010, C = 12252240, P = 998244353;
int n, X, Y, K, M, ans, a[maxn], pw[20], _pw[20], binom[20], f[C + 10], g[C + 10];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

void red(int &x) {
    x += x >> 31 & P;
}

int main() {
    scanf("%d %d %d %d %d %d", &n, &a[0], &X, &Y, &K, &M);
    for (int i = 1; i < n; i++) {
        a[i] = (1LL * X * a[i - 1] + Y) % M;
    }
    for (int i = pw[0] = _pw[0] = 1; i <= K; i++) {
        pw[i] = 1LL * (n - 1) * pw[i - 1] % P;
        _pw[i] = 1LL * n * _pw[i - 1] % P;
    }
    for (int i = 1; i < 1 << K; i++) {
        binom[__builtin_popcount(i)]++;
    }
    int sum = 0;
    for (int i = 1; i <= K; i++) {
        sum = (sum + 1LL * binom[i] * i % P * pw[K - i]) % P;
    }
    for (int i = 0; i < n; i++) {
        int t = a[i] / C * C;
        f[a[i] % C]++;
        ans = (ans + 1LL * (a[i] / C * C) * sum) % P;
    }
    for (int i = 0; i < K; i++) {
        memset(g, 0, sizeof(g));
        for (int j = 0; j < C; j++) {
            ans = (ans + 1LL * f[j] * j % P * _pw[K - i - 1]) % P;
        }
        for (int j = 0; j < C; j++) {
            g[j] = (g[j] + 1LL * f[j] * (n - 1)) % P;
            red(g[j - j % (i + 1)] += f[j] - P);
        }
        swap(f, g);
    }
    printf("%d\n", ans);
    return 0;
}