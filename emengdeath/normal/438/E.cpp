#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
typedef long long ll;
namespace ntt {
    const int N = 1e6;
    const ll MOD = 998244353;
    const ll G = 3;
    int n, len, bitr[N];
    ll wi, invl, u, v, invl2;
    ll w[N], tp[N], a[N], b[N];

    ll calc(ll x, ll y) {
        static ll s;
        s = 1;
        while (y) {
            if (y & 1)(s *= x) %= MOD;
            (x *= x) %= MOD, y >>= 1;
        }
        return s;
    }

    void set(int n) {
        for (len = 1; len <= n; len <<= 1);
        invl = calc(len, MOD - 2);
        w[0] = 1, w[1] = calc(G, (MOD - 1) / len);
        for (int i = 0, j, k, l; i < len; bitr[j] = i++)
            for (j = 0, k = 1, l = i; k < len; k <<= 1, l >>= 1)j = (j << 1) + (l & 1);
        for (int i = 2; i <= len; i++)w[i] = w[i - 1] * w[1] % MOD;
    }

    void dft(ll *a, bool sig) {
        for (int i = 0; i < len; i++)tp[bitr[i]] = a[i];
        for (int i = 2, stp = len, cur, hal, j, k; i <= len; i <<= 1) {
            stp >>= 1, cur = sig ? len : 0, hal = i >> 1;
            for (j = 0; j < hal; j++, sig ? cur -= stp : cur += stp)
                for (k = j, wi = w[cur]; k < len; k += i) {
                    u = tp[k], v = tp[k + hal] * wi % MOD;
                    tp[k] = (u + v) % MOD;
                    tp[k + hal] = (u - v + MOD) % MOD;
                }
        }
        for (int i = 0; i < len; i++)a[i] = tp[i];
    }

    void ntt(ll *ap, ll *bp, int na, int nb, ll *c) {
        for (int i = 0; i < na; i++)a[i] = ap[i];
        for (int i = 0; i < nb; i ++)b[i] = bp[i];
        for (int i = na; i < len; i++)a[i] = 0;
        for (int i = nb; i < len; i++)b[i] = 0;
        dft(a, 0), dft(b, 0);
        for (int i = 0; i < len; i++)c[i] = a[i] * b[i] % MOD;
        dft(c, 1);
        for (int i = 0; i < len; i++)(c[i] *= invl) %= MOD;
    }
    void get_inv(ll *a, ll* inv_a, int n) { //n2
        static ll tmp[N];
        if (n == 1) {
            inv_a[0] = calc(a[0], MOD - 2);
            return;
        }
        get_inv(a, inv_a, n >> 1);
        for (int i = 0; i < n ; i ++) tmp[i] = a[i], tmp[i + n] = 0;
        set(n);
        dft(tmp, 0), dft(inv_a, 0);
        for (int i = 0; i < len; i ++)
            tmp[i] = inv_a[i] * (2 + MOD - tmp[i] * inv_a[i] % MOD) % MOD;
        dft(tmp, 1);
        for (int i = 0; i < len; i++)(tmp[i] *= invl) %= MOD;
        for (int i = 0; i < n ; i ++) inv_a[i] = tmp[i], inv_a[i + n] = 0;
    }
    void get_sqrt(ll *a, ll* sqrt_a, int n) { //n2
        static ll tmp[N], c[N];
        if (n == 1) {
            invl2 = calc(2, MOD - 2);
            sqrt_a[0] = 1;
            return;
        }
        get_sqrt(a, sqrt_a, n >> 1);
        for (int i = 0; i < n; i ++) tmp[i] = 0;
        get_inv(sqrt_a, tmp, n);
        for (int i = 0; i < n ; i ++) c[i] = a[i], c[n + i] = 0;
        set(n);
        dft(c, 0), dft(sqrt_a, 0), dft(tmp, 0);
        for (int i = 0;i < len; i ++) sqrt_a[i] = (sqrt_a[i] + c[i] * tmp[i]) % MOD * invl2 % MOD;
        dft(sqrt_a, 1);
        for (int i = 0; i < n; i ++)sqrt_a[i] = sqrt_a[i] * invl % MOD;
        for (int i = n ; i < len ; i ++) sqrt_a[i] = 0;
    }
    void ni_ntt(ll *ap, ll *bp, int na, int nb, ll *c) { //ap * bp^-1
        set(nb);
        nb = len;
        get_inv(bp, b, nb);
        set(nb);
        for (int i = 0; i < na; i++)a[i] = ap[i];
        for (int i = na; i < len; i++)a[i] = 0;
        dft(a, 0), dft(b, 0);
        for (int i = 0; i < len; i++)c[i] = b[i] * a[i] % MOD;
        dft(c, 1);
        for (int i = 0; i < len; i++)(c[i] *= invl) %= MOD;
    }
}
const int N = 1e6;
const int MOD = 998244353;
ll a[N], b[N];
int n, m;
int main(){
    int n;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n ; i ++) {
        int x;
        scanf("%d", &x);
        if (x <= m)a[x] = 1;
    }
    for (int i = 1;i <= m; i ++)
        a[i] = (MOD - 4 * a[i] % MOD) % MOD;
    a[0] = 1;
    int kn = 1;
    while (kn <= m) kn <<= 1;
    ntt::get_sqrt(a, b, kn);
    b[0] ++;
    memset(a, 0, sizeof(a));
    ntt::get_inv(b, a, kn);
    for (int i = 1; i <= m ; i ++)
        printf("%d\n", a[i] * 2 % MOD);
    return 0;
}