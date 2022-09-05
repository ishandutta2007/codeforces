#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000009;
int n, a, b, K;
char s[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d %d %d %s", &n, &a, &b, &K, s);
    int ans = 0;
    b = 1LL * qp(a, P - 2) * b % P;
    int q = qp(b, K);
    auto calc = [&](int x) {
        if (q == 1) return 1LL * (x + 1);
        return 1LL * (P + 1 - qp(q, x + 1)) * qp(P + 1 - q, P - 2) % P;
    };
    for (int i = 0; i < K && i <= n; i++) {
        ans = (ans + 1LL * (s[i] == '+' ? 1 : P - 1) * qp(b, i) % P * calc((n - i) / K)) % P;
    }
    printf("%lld\n", 1LL * ans * qp(a, n) % P);
    return 0;
}