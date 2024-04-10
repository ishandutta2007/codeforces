#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e6 + 1;
const int mod = 998244353;
long long a[N], b[N];
int n;
long long calc(long long x, long long y) {
    long long z = 1;
    x %= mod;
    while (y) {
        if (y & 1) z = z * x % mod;
        x = x * x % mod, y /= 2;
    }
    return z;
}
int main() {
    scanf("%d", &n);
    long long ni1 = calc(n, mod - 2);
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        long long ni = calc(1ll * k * n % mod, mod - 2);
        while (k --) {
            int x;
            scanf("%d", &x);
            (a[x] += ni) %= mod;
            (b[x] += ni1) %= mod;
        }
    }
    long long ans = 0;
    for (int i = 1; i < N; i ++)
        ans = (ans + a[i] * b[i] ) % mod;
    printf("%lld\n", ans);
    return 0;
}