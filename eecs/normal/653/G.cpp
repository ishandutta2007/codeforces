#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010, P = 1000000007;
int n, ans, pr[maxn], cnt[maxn], coef1[maxn], coef2[maxn], num[20];
int fact[maxn], finv[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &n);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x), cnt[x]++;
    }
    for (int i = fact[0] = finv[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    for (int i = 2; i <= n; i++) {
        coef1[i] = 1LL * fact[n - 1] * finv[i - 2] % P * finv[n - i + 1] % P;
        (coef1[i] += coef1[i - 1]) %= P;
    }
    for (int i = 1; i <= n; i++) {
        coef2[i] = coef1[n - i + 1];
    }
    for (int i = 1; i <= n; i++) {
        (coef1[i] += coef1[i - 1]) %= P;
        (coef2[i] += coef2[i - 1]) %= P;
    }
    fill(pr, pr + 300001, 1);
    for (int i = 2; i <= 300000; i++) if (pr[i]) {
        memset(num, 0, sizeof(num)), num[0] = n;
        for (int j = i; j <= 300000; j += i) {
            if (j > i) pr[j] = 0;
            int c = 0, k = j;
            while (!(k % i)) k /= i, c++;
            num[c] += cnt[j], num[0] -= cnt[j];
        }
        for (int j = 1; j < 20; j++) {
            num[j] += num[j - 1];
            ans = (ans + 1LL * j * (coef1[num[j]] - coef1[num[j - 1]] + P)) % P;
            ans = (ans + 1LL * (P - j) * (coef2[num[j]] - coef2[num[j - 1]] + P)) % P;
        }
    }
    printf("%d\n", ans);
    return 0;
}