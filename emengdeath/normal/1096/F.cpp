#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 1e6;
const int mod = 998244353;
ll ans;
ll a[N];
int b[N], f[N], ff[N];
int n;
void ins(int x, int*f, int v) {
    while (x <= n) {
        f[x] += v;
        x += x &-x;
    }
}
int get(int x, int*f){
    int v = 0;
    while (x) {
        v += f[x];
        x -= x & -x;
    }
    return v;
}
ll calc(ll x, ll y) {
    ll z = 1;
    while (y) {
        if (y & 1) z = z * x % mod;
        x = x * x % mod, y >>= 1;
    }
    return z;
}
ll C(int x, int y) {
    return a[x] * calc(a[y] * a[x - y] % mod, mod - 2) % mod;
}
int main() {
    scanf("%d", &n);
    int sum = 0;
    a[0] = 1;
    for (int i= 1; i <= n; i ++)
        ins(i, ff, 1);
    for (int i= 1; i <= n; i ++) {
        scanf("%d", &b[i]), sum += (b[i] == -1), a[i] = a[i - 1] * i % mod;
        if (b[i] > 0)
            ins(b[i], ff, -1);
    }
    int x = 0;
    if (sum >= 2)
        ans = C(sum, 2) * C(sum, 2)% mod * a[sum - 2] % mod;
    for (int i = n; i >= 1; i --)
        if (b[i] != -1) {
            ins(b[i], f, 1);
            ans = (ans + get(b[i] - 1, f) * a[sum]) % mod;
            int y = get(b[i] -1, ff), z = sum - y;
            ans = (ans + 1ll * y * x % mod * a[sum - 1] % mod + 1ll * z * (sum -x) % mod * a[sum - 1] % mod ) % mod;
        } else x ++;
    printf("%lld\n", ans * calc(a[sum], mod- 2) % mod);
    return 0;
}