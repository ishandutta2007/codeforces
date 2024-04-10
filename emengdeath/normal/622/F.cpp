#include <algorithm>
#include <cstdio>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e7 + 1;
int f[N], b[N], a[N], nia[N];
int calc(int x, int y) {
    int z = 1;
    x %= mod;
    while (y) {
        if (y & 1) z = 1ll * z * x % mod;
        x = 1ll * x * x % mod, y /= 2;
    }
    return z;
}
void init(int n) {
    a[0] = a[1] = 1;
    for (int i = 2; i <= n; i ++) a[i] = 1ll * a[i - 1] * i % mod;
    nia[n] = calc(a[n], mod - 2);
    for (int i = n - 1; i >= 0; i --) nia[i] = 1ll * nia[i + 1] * (i + 1) % mod;
}
int solve(int n, int *y, int xk) {
    int ans = 0;
    f[0] = 1;
    b[n] = 1;
    for (int i = 1; i <= n; i ++)
        f[i] = 1ll * f[i - 1] * (xk - i) % mod;
    for (int i = n - 1; i >= 0; i --)
        b[i] = 1ll * b[i + 1] * (xk - (i + 1)) % mod;
    for (int i = 1; i <= n; i ++) {
        if ((n - i) & 1)
            ans = (ans - 1ll * y[i - 1] * nia[i - 1] % mod * nia[n - i] % mod * f[i - 1] % mod * b[i] % mod) % mod;
        else    ans = (ans + 1ll * y[i - 1] * nia[i - 1] % mod * nia[n - i] % mod * f[i - 1] % mod * b[i] % mod) % mod;
    }
    return (ans + mod) % mod;
}
int n, k;
int y[N];
int main() {
    scanf("%d %d", &n, &k);
    init(k + 10);
    for (int i= 1; i <= k + 2; i ++)
        y[i] = (y[i - 1] + calc(i, k)) %mod;
    printf("%d\n", solve(k + 2, y, n + 1));
    return 0;
}