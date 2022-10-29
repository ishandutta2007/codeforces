#include <algorithm>
#include <cstdio>
using namespace std;
int n;
int f[2][2][32];
const int mod = 1e9 + 7;
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
int main()
{
    scanf("%d", &n);
    bool bz = 0, bz1 = 1;
    f[0][1][0] = 1;
    for (int i = 29; i >= 0; i --, swap(bz, bz1))
        for (int j = 0; j < 2; j ++)
            for (int k = 0; k <= 29;k ++)
            if (f[bz][j][k]){
                if (j) {
                    if ((n >> i) & 1) {
                        f[bz1][0][k] = add(f[bz1][0][k], mul(f[bz][j][k], max((1 << k) >> 1, 1)));
                        f[bz1][1][k] = add(f[bz1][1][k], mul(f[bz][j][k], (1 << k) >> 1));

                        f[bz1][1][k + 1] = add(f[bz1][1][k + 1], f[bz][j][k]);
                    } else {
                        f[bz1][1][k] = add(f[bz1][1][k], mul(f[bz][j][k], max((1 << k) >> 1, 1)));
                    }
                } else {
                    f[bz1][0][k] = add(f[bz1][0][k], mul(f[bz][j][k], (1 << k)));
                    f[bz1][0][k + 1] = add(f[bz1][0][k + 1], f[bz][j][k]);
                }
                f[bz][j][k] = 0;
            }
    int ans = 0;
    for (int i = 0; i <= 29; i ++)
        ans = add(ans, add(f[bz][0][i], f[bz][1][i]));
    printf("%d\n", ans);
    return 0;
}