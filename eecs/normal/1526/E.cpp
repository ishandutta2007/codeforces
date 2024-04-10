#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, P = 998244353;
int n, K, sa[maxn], rk[maxn], fact[maxn], finv[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 0; i < n; i++) {
        scanf("%d", &sa[i]), rk[sa[i]] = i;
    }
    for (int i = fact[0] = finv[0] = 1; i <= max(n, K); i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    auto binom = [&](int n, int m) {
        return n < m ? 0 : 1LL * fact[n] * finv[m] % P * finv[n - m] % P;
    };
    rk[n] = -1;
    int cnt = 0, ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (rk[sa[i] + 1] < rk[sa[i + 1] + 1]) cnt++;
    }
    for (int i = 0; i <= cnt; i++) if (n - i > 1) {
        ans = (ans + 1LL * binom(cnt, i) * binom(K, n - i)) % P;
    }
    bool flag = 1;
    for (int i = 0; i < n; i++) {
        flag &= sa[i] == n - i - 1;
    }
    if (flag) (ans += K) %= P;
    printf("%d\n", ans);
    return 0;
}