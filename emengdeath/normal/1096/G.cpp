#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 4e6;
const ll MOD = 998244353;
const ll G = 3;
int n, len, bitr[N];
ll wi, invl, u, v;
ll w[N], tp[N], a[N];
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

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    set(n / 2 * 9 + 10);
    while (k --) {
        int x;
        scanf("%d", &x);
        a[x] ++;
    }
    dft(a, 0);
    for (int i = 0; i < len; i ++)
        a[i] = calc(a[i], n / 2);
    dft(a, 1);
    long long ans = 0;
    for (int i = 0; i < len ; i++) {
        a[i] = a[i] * invl % MOD;
        ans = (ans + a[i] * a[i]) % MOD;
    }
    printf("%lld\n", ans);
}