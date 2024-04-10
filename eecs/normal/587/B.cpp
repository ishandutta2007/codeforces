#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1000010, P = 1000000007;
int n, K, ans, a[maxn], b[maxn], f[maxn], g[maxn], binom[maxn], binom2[maxn], cnt[maxn];
ll l;

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %lld %d", &n, &l, &K);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]), b[i] = a[i];
    }
    sort(a, a + n), f[0] = 1;
    ll m = l / n + 1;
    K = min((ll)K, m);
    for (int i = l % n; i < n; i++) {
        cnt[lower_bound(a, a + n, b[i]) - a]++;
    }
    for (int i = 0, j; i < n; i = j) {
        for (j = i; j < n && a[i] == a[j]; j++);
        for (int k = 1; k <= K; k++) {
            g[k] = f[k];
            f[k] = (f[k - 1] + 1LL * qp(j - i, P - 1 - k) * f[k]) % P;
        }
        for (int k = 0; k <= K; k++) {
            f[k] = 1LL * qp(j - i, k) * f[k] % P;
            int o = (f[k] - g[k] + P) % P;
            if (k) ans = (ans - 1LL * cnt[i] * o % P * qp(j - i, P - 2) % P + P) % P;
        }
    }
    for (int i = 1; i <= K; i++) {
        ans = (ans + 1LL * (m - i + 1) % P * f[i]) % P;
    }
    printf("%d\n", ans);
    return 0;
}