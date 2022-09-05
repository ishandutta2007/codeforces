#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000007;
int n, a[maxn], fact[maxn], finv[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = fact[0] = finv[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    auto binom = [&](int n, int m) {
        return 1LL * fact[n] * finv[m] % P * finv[n - m] % P;
    };
    auto calc = [&](int a, int b) {
        return binom(a + b, b);
    };
    int l = 1, r = n, ans = 1;
    while (1) {
        int i = l, j = r;
        while (i <= n && !a[i]) i++;
        if (i > n) { ans = 1LL * ans * qp(2, r - l) % P; break; }
        while (!a[j]) j--;
        if (i == j) {
            int ways = 0;
            if (i - a[i] + 1 >= l) {
                ways = 1LL * calc(i - a[i] + 1 - l, r - i) * qp(2, max(0, a[i] - 2)) % P;
            }
            if (a[i] > 1 && i + a[i] - 1 <= r) {
                ways = (ways + 1LL * calc(i - l, r - (i + a[i] - 1)) * qp(2, max(0, a[i] - 2))) % P;
            }
            ans = 1LL * ans * ways % P; break;
        } else if (a[i] > a[j]) {
            if (i + a[i] - 1 > r) puts("0"), exit(0);
            ans = 1LL * ans * calc(i - l, r - (i + a[i] - 1)) % P;
            l = i + 1, r = i + a[i] - 1;
        } else {
            if (j - a[j] + 1 < l) puts("0"), exit(0);
            ans = 1LL * ans * calc(j - a[j] + 1 - l, r - j) % P;
            l = j - a[j] + 1, r = j - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}