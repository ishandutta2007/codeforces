#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000007;
int n, K, ans, pre[10][maxn], fact[maxn], finv[maxn], pw[maxn];
char s[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d %s", &n, &K, s + 1);
    for (int i = fact[0] = finv[0] = pw[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
        pw[i] = 10LL * pw[i - 1] % P;
    }
    auto binom = [&](int x, int y) {
        if (x < y || y < 0) return 0LL;
        return 1LL * fact[x] * finv[y] % P * finv[x - y] % P;
    };
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j <= n; j++) {
            pre[i][j] = (pre[i][j - 1] + 1LL * pw[j - 1] * binom(n - 1 - j, K - 1) % P * i) % P;
        }
    }
    for (int i = 1; i <= n; i++) {
        int c = s[i] - '0';
        (ans += pre[c][n - i]) %= P;
        ans = (ans + 1LL * pw[n - i] * c % P * binom(i - 1, K)) % P;
    }
    printf("%d\n", ans);
    return 0;
}