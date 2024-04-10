#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, P = 998244353;
int n, m, ans, fact[maxn], finv[maxn];
int a[maxn], b[maxn], cnt[maxn], c[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

void add(int p, int v) {
    for (; p < maxn; p += p & -p) (c[p] += v) %= P;
}

int sum(int p) {
    int s = 0;
    for (; p; p -= p & -p) (s += c[p]) %= P;
    return s;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), cnt[a[i]]++;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = fact[0] = finv[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    int cur = 1;
    for (int i = 1; i < maxn; i++) {
        cur = 1LL * cur * finv[cnt[i]] % P;
        if (cnt[i]) add(i, 1LL * fact[cnt[i]] * finv[cnt[i] - 1] % P);
    }
    for (int i = 1; i <= min(n, m); i++) {
        ans = (ans + 1LL * fact[n - i] * cur % P * sum(b[i] - 1)) % P;
        if (!cnt[b[i]]) break;
        cur = 1LL * cur * fact[cnt[b[i]]] % P;
        add(b[i], P - 1LL * fact[cnt[b[i]]] * finv[cnt[b[i]] - 1] % P);
        cur = 1LL * cur * finv[--cnt[b[i]]] % P;
        add(b[i], 1LL * fact[cnt[b[i]]] * finv[cnt[b[i]] - 1] % P);
        if (i == n && n < m) ++ans %= P;
    }
    printf("%d\n", ans);
    return 0;
}