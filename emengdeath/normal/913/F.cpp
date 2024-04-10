#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2100;
const int mod = 998244353;
typedef long long ll;
ll p[N * (N + 1)], _p[N * (N + 1)], ni_p[N * (N + 1)];
int n, a, b;
ll f[N][N], s[N][N], g[N][N], w[N], E[N];
ll help[N];
ll add(ll x, ll y) {
    return (x + y) % mod;
}
ll mul(ll x, ll y) {
    return x * y % mod;
}
ll sub(ll x, ll y) {
    return ((x - y) % mod + mod) % mod;
}
ll calc(ll x,ll y){
    ll z = 1;
    x %= mod;
    while (y) {
        if (y & 1) z = z * x % mod;
        x = x * x % mod , y /= 2;
    }
    return z;
}
ll Div(ll x, ll y) {
    return x * calc(y, mod - 2) % mod;
}
int main() {
    cin >> n >> a >> b;
    p[0] = _p[0] = 1;
    p[1] = Div(a, b);
    _p[1] = sub(1, p[1]);
    for (int i = 2; i <= n * (n + 1) ;i ++)
        p[i] = mul(p[i - 1], p[1]), _p[i] = mul(_p[i - 1], _p[1]);
    ni_p[0] = 1;
    ni_p[1] = calc(_p[1], mod - 2);
    for (int i = 2; i <= n * (n + 1); i ++)
        ni_p[i] = mul(ni_p[i - 1], ni_p[1]);
    f[1][0] = 1;
    s[1][0] = g[1][0] = 1;
    for (int i = 1; i <= n; i ++) {
        f[1][i] = add(mul(f[1][i - 1], _p[1]), p[i]);
        s[1][i] = mul(f[1][i], Div(p[i], calc(_p[i], 2)));
        g[1][i] = add(g[1][i - 1], s[1][i]);
    }
    /*for (int i = 2; i <= n; i ++) {
        f[i][0] = 1;
        s[i][0] = f[i][0];
        g[i][0] = s[i][0];
        for (int j = 1; j <= n ; j ++)
        {
            f[i][j] = mul(calc(_p[j], i), g[i - 1][j]);
            s[i][j] = mul(f[i][j], Div(p[j], calc(_p[j], i + 1)));
            g[i][j] = add(g[i][j - 1], s[i][j]);
        }
    }*/
    for (int i = 2; i <= n; i ++) {
        f[i][0] = 1;
        s[i][0] = f[i][0];
        g[i][0] = s[i][0];
        for (int j = 1; j <= n ; j ++)
        {
            f[i][j] = mul(_p[i * j], g[i - 1][j]);
            s[i][j] = mul(f[i][j], mul(p[j], ni_p[j * (i + 1)]));
            g[i][j] = add(g[i][j - 1], s[i][j]);
        }
    }
    for (int i = 1; i <= n ; i ++) {
        w[i] = 1;
        for (int j = 1; j < i ; j ++)
            w[i] = sub(w[i], mul(f[j][i - j], w[j]));
    }
    for (int i = 2; i <= n; i ++) {
        E[i] = mul(w[i], i * (i - 1) / 2);
        for (int j = 1; j < i ; j ++)
            E[i] = add(E[i], mul(add(add(E[j], E[i - j]), (j - 1) * j / 2 + j * (i - j)), mul(f[j][i - j], w[j])));
        E[i] = Div(E[i], sub(1, w[i]));
    }
    printf("%lld\n", E[n]);
    return 0;
}