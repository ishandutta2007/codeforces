#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 3e5 + 10;
int n;
int a[N], all;
const int mod = 998244353;
long long calc(long long x, long long y) {
    long long z = 1;
    while (y){
        if (y & 1)
            z = z * x % mod;
        x = x * x % mod, y/= 2;
    }
    return z;
}
long long ni(long long x) {
    return calc(x, mod - 2);
}
long long f[N];
long long calc(long long p) {
    if (!p) return 0;
    return ni((1 - p + mod) % mod);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]), all += a[i];
    long long ni_all = ni(all), ni_n_1 = ni(n - 1);
    f[0] = (n - 1);
    for (int i = 1; i < all; i ++) {
        long long w_0 = ni_all * i % mod, w_1 = ni_all * (all - i) % mod * ni_n_1 % mod * (n - 2) % mod, p = calc((w_0 + w_1) % mod);
        f[i] = (f[i - 1] * w_0 % mod * p % mod + p) % mod;
    }
    f[all] = 0;
    for (int i = all ; i >= 1; i --)
        f[i - 1] = (f[i - 1] + f[i]) % mod;
    long long sigma_E = 0, C = f[0];
    for (int i = 1; i <= n ; i++)
        sigma_E = (sigma_E + f[a[i]]) % mod;
    printf("%lld\n", ni(n) * ((sigma_E + mod - C * (n - 1) % mod)% mod)% mod);
    return 0;
}