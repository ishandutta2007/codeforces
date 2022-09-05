#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int T, tot, cnt, a[maxn], p[maxn], mu[maxn], phi[maxn];

void sieve() {
    fill(p, p + maxn, 1), mu[1] = phi[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (p[i]) p[++tot] = i, mu[i] = -1, phi[i] = i - 1;
        for (int j = 1; j <= tot && i * p[j] < maxn; j++) {
            int k = i * p[j]; p[k] = 0;
            if (i % p[j]) mu[k] = -mu[i], phi[k] = phi[i] * phi[p[j]];
            else { mu[k] = 0, phi[k] = phi[i] * p[j]; break; }
        }
    }
}

int S(int n, int m) {
    int s = 0;
    for (int i = 1; i <= cnt && a[i] <= m; i++) {
        s += mu[a[i]] * (m / a[i]);
    }
    return s;
}

int solve(int n, int m) { 
    return m / n * phi[n] + S(n, m % n);
}

int calc(int n, int k) {
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        S(n, mid) < k ? l = mid + 1 : r = (ans = mid) - 1;
    }
    return ans;
}

int main() {
    scanf("%d", &T), sieve();
    while (T--) {
        int x, p, k; cnt = 0;
        scanf("%d %d %d", &x, &p, &k);
        for (int i = 1; i * i <= p; i++) {
            if (!(p % i)) {
                a[++cnt] = i;
                if (i * i < p) a[++cnt] = p / i;
            }
        }
        sort(a + 1, a + cnt + 1);
        k += solve(p, x);
        int ans = 0;
        ans += 1LL * k / phi[p] * p, k %= phi[p];
        if (!k) k += phi[p], ans -= p;
        printf("%d\n", ans + calc(p, k));
    }
    return 0;
}