#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
namespace ntt {
    const int N = 1e6;
    const ll MOD = 998244353;
    const ll G = 3;
    int n, len, bitr[N];
    ll wi, invl, u, v, invl2;
    ll w[N], tp[N];
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
}
const int N = 1e6;
char s[N], t[N];
int n, m;
bool edge[N][6][6];
long long f[6][N], g[6][N], tmp[N];
int fa[N];
int getfa(int x) {
    return x == fa[x] ? x: fa[x] =getfa(fa[x]);
}
int main() {
    scanf("%s", s);
    scanf("%s", t);
    n = strlen(s), m = strlen(t);
    reverse(t, t + m);
    ntt::set(n + m + 2);
    for (int i = 0; i < 6; ntt::dft(f[i], 0), i ++)
        for (int j = 0; j < n ; j++)
            f[i][j] = (s[j] - 'a' == i);
    for (int i = 0; i < 6; ntt::dft(g[i], 0), i ++)
        for (int j = 0; j < m ; j++)
            g[i][j] = (t[j] - 'a' == i);
    for (int i = 0; i < 6; i ++)
        for (int j = 0; j < 6; j ++) {
            for (int k = 0; k < ntt::len; k ++) tmp[k] = f[i][k] * g[j][k] % ntt::MOD;
            ntt::dft(tmp, 1);
            for (int k = m - 1; k < n; k ++)
                edge[k - m + 1][i][j] = tmp[k];
        }
    for (int i = 0; i < n - m + 1; i ++) {
        for (int i = 0; i < 6; i ++)
            fa[i] = i;
        int cnt = 0;
        for (int j = 0; j < 6; j ++)
            for (int k = 0; k < 6; k ++) {
                if (edge[i][j][k] && getfa(j) != getfa(k))
                    cnt++, fa[getfa(j)] = k;
            }
        printf("%d ", cnt);
    }
    return 0;
}