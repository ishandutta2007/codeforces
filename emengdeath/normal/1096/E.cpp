#include <algorithm>
#include <cstdio>
using namespace std;
const int mod = 998244353;
const int N = 5001;
typedef long long ll;
int ans;
int ni[101];
int a[N * 2], nia[N * 2], f[N + 10];
int n, r, s;
ll calc(ll x, ll y){
    ll z = 1;
    while (y) {
        if (y & 1) z = z * x % mod;
        x = x * x % mod, y /= 2;
    }
    return z;
}
ll CC(int x,int y) {
    return y < 0 || x < y ? 0 : 1ll * a[x] * nia[y] % mod * nia[x - y] % mod;
}
int add(int x, int y) {
    x += y;
    return x >= mod ? x - mod : x;
}
int sub(int x, int y) {
    x -= y;
    return x <0 ? x + mod : x;
}
int mul(int x, int y) {
    return 1ll * x * y % mod;
}
int main() {
    scanf("%d %d %d", &n,  &s, &r);
    a[0] = 1;
    for (int i = 1; i < N * 2; i ++)
        a[i] = 1ll * a[i - 1] * i % mod;
    nia[N * 2 -1] = calc(a[N * 2 - 1], mod - 2);
    for (int i= N * 2 - 2; i >= 0; i --)
        nia[i] = 1ll * nia[i + 1] * (i + 1) % mod;
    ni[0] = ni[1] = 1;
    for (int i = 2;i <= n; i ++) ni[i] = 1ll * ni[mod % i] * (mod - mod / i) % mod;
    for (int i = 1; i * r <= s && i <= n; i ++) {
        if (i&1)
            ans = add(ans, mul(CC(n, i), CC(s - i * r + n - 1, n - 1)));
        else
            ans = sub(ans, mul(CC(n, i), CC(s - i * r + n - 1, n - 1)));
    }
    ans = mul(ans, ni[n]);
    ll all = CC(s - r + n - 1, n - 1);
    printf("%lld\n", ans * calc(all, mod - 2) % mod);
    return 0;
}