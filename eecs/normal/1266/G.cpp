#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000010, P = 998244353;
int n, c[maxn], fact[maxn], finv[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &n);
    for (int i = fact[0] = finv[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    c[0] = n;
    for (int i = 1; i < n; i++) {
        int t = (1LL * (n - i) * (n - i) + 1) % P;
        c[i] = 1LL * fact[n] * finv[n - i + 1] % P * t % P;
    }
    for (int i = n; i < 2 * n; i++) {
        c[i] = (fact[n] - c[i - n] + P) % P;
    }
    int len = 1LL * n * fact[n] % P;
    int ans = 1LL * len * (len + 1) % P * ((P + 1) / 2) % P;
    for (int i = 0; i < 2 * n; i++) {
        ans = (ans - 1LL * i * c[i] % P + P) % P;
    }
    printf("%d\n", ans);
    return 0;
}