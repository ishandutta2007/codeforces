#include <bits/stdc++.h>
using namespace std;

const int maxn = 1100010, P = 998244353;
int K, ans, a[maxn], c1[maxn], c2[maxn], fact[maxn], finv[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &K);
    for (int i = 1; i <= K; i++) {
        scanf("%d", &a[i]);
    }
    int mx = *max_element(a + 1, a + K + 1), N = mx + K;
    for (int i = 1; i <= K; i++) {
        for (int j = a[i] + 1; j <= mx; j += K) c1[j]++;
        c2[a[i] + 1]++;
    }

    for (int i = fact[0] = 1; i <= N; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
    }
    finv[N] = qp(fact[N], P - 2);
    for (int i = N - 1; ~i; i--) {
        finv[i] = 1LL * (i + 1) * finv[i + 1] % P;
    }
    auto binom = [&](int n, int m) {
        return 1LL * fact[n] * finv[m] % P * finv[n - m] % P;
    };

    for (int i = 0; i <= mx; i++) {
        c1[i] += c1[i - 1], c2[i] += c2[i - 1];
        int j = i - c1[i], k = K - c2[i];
        if (j < 0) break;
        (ans += binom(j + K - 1, K - 1)) %= P;
        if (j >= k) ans = (ans - binom(j - k + K - 1, K - 1) + P) % P;
    }
    printf("%d\n", ans);
    return 0;
}