#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int a[10000010], b[10000010];
int np[10000010], prime[1000010], cnt, mu[10000010];
int pw2[500010];
int n;
const int m = 1e7;
inline int Mod(int x) {
    return x >= mod ? x - mod : x;
}
int main() {
    mu[1] = 1;
    for (int i = 2; i <= m; i++) {
        if (!np[i]) prime[++cnt] = i, mu[i] = -1;
        for (int j = 1; prime[j] * i <= m; j++) {
            np[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            }
            mu[i * prime[j]] = -mu[i];
        }
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        pw2[i] = (pw2[i - 1] + pw2[i - 1] + 1) % mod;
        static int a;
        scanf("%d", &a);
        ::a[a]++, ::b[a]++;
    }
    for (int i = 1; i <= cnt; i++) {
        for (int j = m / prime[i]; j > 0; j--) b[j] += b[j * prime[i]];
    }
    for (int i = 1; i <= m; i++) a[i] = pw2[b[i]], b[i] = 1ll * (mod + mu[i]) * b[i] % mod;
    for (int i = 1; i <= cnt; i++) {
        for (int j = 1, j_end = m / prime[i]; j <= j_end; j++) b[j * prime[i]] = Mod(b[j * prime[i]] + b[j]);
        for (int j = 1, j_end = m / prime[i]; j <= j_end; j++) a[j] = Mod(a[j] - a[j * prime[i]] + mod);
    }
    int ans = 0;
    for (int i = 2; i <= m; i++) {
        ans = (ans + 1ll * a[i] * b[i]) % mod;
    }
    return cout << ans << endl, 0;
}