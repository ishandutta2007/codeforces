#include <bits/stdc++.h>
using namespace std;
int mod, n;
int power(int a, int b) {
    long long res = a, ans = 1;
    for (; b; b >>= 1, res = res * res % mod) if (b & 1) ans = ans * res % mod;
    return ans;
}
int fac[5010], facinv[5010];
int C(int n, int m) {
    return 1ll * fac[n] * facinv[m] % mod * facinv[n - m] % mod;
}
int main() {
    scanf("%d%d", &n, &mod);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = 1ll * i * fac[i - 1] % mod;
    facinv[n] = power(fac[n], mod - 2);
    for (int i = n; i > 0; i--) facinv[i - 1] = 1ll * i * facinv[i] % mod;
    int qwq = 1, ans = 0;
    for (int i = 1; i <= n; i++) {
        qwq = 1ll * qwq * (n - 1) % mod * power(i, mod - 2) % mod;
        for (int j = 2 * i; j <= n; j++) {
            int cur = 1ll * qwq * facinv[n - j] % mod * C(i - 1 + j - 2 * i, i - 1) % mod;
            cur = 1ll * cur * power(j - i, n - j) % mod;
            if ((ans += cur) >= mod) ans -= mod;
        }
    }
    cout << 1ll * fac[n] * ans % mod << endl;
}