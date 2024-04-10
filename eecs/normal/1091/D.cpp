#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010, P = 998244353;
int n, ans, fact[maxn], num[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &n);
    for (int i = fact[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        num[i] = 1LL * qp(fact[i], P - 2) * fact[n] % P;
    }
    for (int i = 1; i <= n; i++) {
        ans = (ans + 1LL * (num[i] - num[i + 1] + P) * (n - i) % P) % P;
    }
    printf("%d\n", ans);
    return 0;
}