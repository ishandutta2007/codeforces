#include <algorithm>
#include <cstdio>
using namespace std;
const int mod = 998244353;
int l[18], r[18];
int k;
int f[2][1<<10][2][2], g[2][1<<10][2][2];
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
void turn(long long x, int*a){
    while (x) {
        a[0] = x % 10;
        x /= 10;
        a += 1;
    }
}
int main() {
    long long x, y;
    scanf("%lld %lld %d", &x, &y, &k);
    turn(x, l);
    turn(y, r);
    bool bz = 0, bz1= 1;
    bool all_zerol = 1, all_zeror = 1;
    for (int i = 17; i >= 0; i --, swap(bz, bz1)) {
        for (int j = 1; j < 10; j ++) {
            if ((all_zerol && j < l[i]) || !all_zerol) continue;
            if (all_zeror && j > r[i]) continue;
            f[bz1][1<<j][all_zerol && j == l[i]][all_zeror && j == r[i]] = 1;
            g[bz1][1<<j][all_zerol && j == l[i]][all_zeror && j == r[i]] = j;
        }
        all_zerol &= !l[i];
        all_zeror &= !r[i];
        for (int j = 0; j < (1 << 10); j++)
            for (int upl = 0; upl < 2; upl++)
                for (int upr = 0; upr < 2; upr++) {
                    int v = f[bz][j][upl][upr], vv = g[bz][j][upl][upr];
                    f[bz][j][upl][upr] = 0;
                    g[bz][j][upl][upr] = 0;
                    for (int k = 0; k < 10; k++) {
                        if (upl && k < l[i]) continue;
                        if (upr && k > r[i]) continue;
                        f[bz1][j | (1 << k)][upl && k == l[i]][upr && k == r[i]] = add(
                                f[bz1][j | (1 << k)][upl && k == l[i]][upr && k == r[i]], v);
                        if (v) {
                            int yy;
                            yy = 0;
                        }
                        g[bz1][j | (1 << k)][upl && k == l[i]][upr && k == r[i]] = add(
                                g[bz1][j | (1 << k)][upl && k == l[i]][upr && k == r[i]], add(mul(vv, 10), mul(v, k)));
                    }
                }
    }
    int ans = 0;
    for (int i = 0; i < (1<<10); i ++) {
        int x = i;
        int y = 0;
        while (x) {
            y ++;
            x -= x & -x;
        }
        if (y > k) continue;
        for (int j = 0; j < 4;j ++)
            ans= add(ans, g[bz][i][j&1][j>>1]);
    }
    printf("%d\n", ans);
    return 0;
}