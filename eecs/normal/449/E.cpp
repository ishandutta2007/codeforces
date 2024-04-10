#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010, U = 1000000, P = 1000000007;
int T, n, m, phi[maxn], f0[maxn], f1[maxn], f2[maxn];
long long sum[maxn];

int main() {
    scanf("%d", &T);
    for (int i = 1; i <= U; i++) {
        phi[i] += i;
        for (int j = i + i; j <= U; j += i) phi[j] -= phi[i];
    }
    for (int i = 1; i <= U; i++) {
        sum[i] -= i;
        for (int j = i; j <= U; j += i) sum[j] += j / i * phi[i];
    }
    for (int i = 1; i <= U; i++) {
        f0[i] = (1LL * i * i + 2 * sum[i] - 2LL * i * (i - 1) % P + P) % P;
        int s1 = 1LL * (i - 1) * i / 2 % P;
        int s2 = 1LL * (i - 1) * i * (2 * i - 1) / 6 % P;
        f0[i] = (f0[i] + 2LL * i * s1 % P - 2 * s2 % P + P) % P;
        f0[i] = (f0[i] + 1LL * i * i * (i - 1)) % P;
        f0[i] = (f0[i] + 4LL * s2) % P;
        f0[i] = (f0[i] - 4LL * i * s1 % P + P) % P;
    }
    for (int i = 1; i <= U; i++) {
        f1[i] = (f1[i - 1] + 1LL * i * f0[i]) % P;
        f2[i] = (f2[i - 1] + 1LL * i * i % P * f0[i]) % P;
        (f0[i] += f0[i - 1]) %= P;
    }
    while (T--) {
        scanf("%d %d", &n, &m);
        if (n > m) swap(n, m);
        int ans = f2[n];
        ans = (ans + 1LL * (n + 1) * (m + 1) % P * f0[n]) % P;
        ans = (ans - 1LL * (n + m + 2) * f1[n] % P + P) % P;
        printf("%d\n", ans);
    }
    return 0;
}