#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e6;
int n, k, m;
int l[N], r[N], x[N];
int L[N], R[N], bz[N];
int g[N];
const int mod = 998244353;
int f[N], ff[N];
int add(int x, int y) {
    x+= y;
    return x >= mod ?x - mod : x;
}
int sub(int x, int y) {
    x -= y;
    return x < 0 ? x +mod : x;
}
int mul(int x, int y){
    return 1ll * x * y % mod;
}
int work(int n) {
    f[0] = 1;
    int all = 1;
    int l = 0;
    for (int i = 1; i <= n; i ++) {
        f[i] = all;
        all = add(all, f[i]);
        while (l < g[i])
            all = sub(all, f[l ++]);
    }
    return all;
}
int calc(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x), y >>= 1;
    }
    return z;
}
int main() {
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 1; i <= m; i ++)
        scanf("%d %d %d", &l[i], &r[i], &x[i]);
    int ans = 1;
    for (int i = 0; i < k; i ++) {
        for (int j = 0; j <= n + 1; j ++)
            bz[j] = 0, g[j] = 0, ff[j] = 0;
        for (int j = 1; j <= m; j ++)
            if ((x[j] >> i) & 1){
                bz[l[j]] ++;
                bz[r[j] + 1] --;
            }
        for (int i = 1; i <= n; i ++) {
            bz[i] += bz[i - 1];
            if (!bz[i])
                L[i] = L[i - 1] + 1;
            else
                L[i] = L[i - 1];
        }
        R[n + 1] = L[n] + 1;
        for (int i = n ; i >= 1; i --)
            if (bz[i])
                R[i] = R[i + 1];
            else
                R[i] = R[i + 1] - 1;
        for (int j = 1; j <= m; j ++)
            if (!((x[j] >> i) & 1))
            {
                if (R[l[j]] > L[r[j]]){
                    printf("0");
                    return 0;
                }
                g[L[r[j]]] = max(g[L[r[j]]], R[l[j]]);
            }
        ans = mul(ans, work(R[n + 1] - 1));
    }
    printf("%d\n", ans);
    return 0;
}