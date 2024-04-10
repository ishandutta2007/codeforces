#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010, P = 1000000007;
int n, w, fact[maxn], finv[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d", &n, &w);
    if (n == 1) puts("1"), exit(0);
    for (int i = fact[0] = finv[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    auto solve = [&](int lim) {
        int ans = 1LL * (qp(n, lim + 1) - n + P) * qp(n - 1, P - 2) % P;
        for (int len = lim + 1; len <= lim + n; len++) {
            int x = max(0, len - lim - (lim + 1) + 1);
            int y = max(0, len - lim - x);
            int ways = 1LL * fact[n] * finv[n - x] % P;
            int v = 1LL * fact[n - x] * finv[n - x - y] % P;
            ways = 1LL * ways * v % P * v % P;
            ans = (ans + 1LL * ways * qp(n, max(0, 2 * lim - len))) % P;
        }
        return ans;
    };
    printf("%d\n", (solve(w) - solve(w - 1) + P) % P);
    return 0;
}