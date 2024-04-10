#include <bits/stdc++.h>
using namespace std;

const int maxn = 3000010, P = 1000000007;
int n, q, fact[maxn], finv[maxn], ans[maxn][3];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = fact[0] = 1; i <= 3 * n; i++) {
        fact[i] = 1LL * fact[i - 1] * i % P;
    }
    finv[3 * n] = qp(fact[3 * n], P - 2);
    for (int i = 3 * n - 1; ~i; i--) {
        finv[i] = 1LL * finv[i + 1] * (i + 1) % P;
    }
    auto binom = [&](int n, int m) {
        return n < m ? 0 : 1LL * fact[n] * finv[m] % P * finv[n - m] % P;
    };
    for (int i = 0; i < n; i++) {
        (ans[1][0] += binom(3 * i, 1)) %= P;
        (ans[1][1] += binom(3 * i + 1, 1)) %= P;
        (ans[1][2] += binom(3 * i + 2, 1)) %= P;
    }
    int i3 = qp(3, P - 2);
    for (int i = 2; i <= 3 * n; i++) {
        int d1 = ans[i - 1][0];
        int d2 = (d1 + ans[i - 1][1]) % P;
        int all = binom(3 * n, i + 1);
        ans[i][0] = (1LL * all - d1 - d2 + 2 * P) % P * i3 % P;
        ans[i][1] = (ans[i][0] + d1) % P;
        ans[i][2] = (ans[i][0] + d2) % P;
        // x + x + d1 + x + d2 = all
    }
    while (q--) {
        int x;
        scanf("%d", &x);
        printf("%lld\n", (ans[x][0] + binom(3 * n, x)) % P);
    }
    return 0;
}