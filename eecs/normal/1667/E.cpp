#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, P = 998244353;
int n, fact[maxn], finv[maxn], ans[maxn], prob[maxn];

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
    scanf("%d", &n);
    for (int i = fact[0] = finv[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    auto binom = [&](int x, int y) {
        return x < y || y < 0 ? 0 : 1LL * fact[x] * finv[y] % P * finv[x - y] % P;
    };
    for (int i = 1; i <= n / 2 + 1; i++) {
        prob[i] = 1LL * fact[n - i] * binom(n / 2, i - 1) % P;
    }
    ans[1] = ans[n / 2 + 1] = fact[n - 1];
    for (int i = 2; i <= n / 2; i++) {
        ans[i] = 1LL * fact[i - 1] * prob[i] % P;
    }
    for (int i = n / 2, s = 0; i; i--) {
        s = (s + 1LL * prob[i + 1] * fact[i - 1]) % P;
        red(ans[i] -= s);
    }
    for (int i = 1; i <= n / 2; i++) {
        red(ans[n / 2 + 1] -= ans[i]);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}