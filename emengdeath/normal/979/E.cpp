#include <algorithm>
#include <cstdio>
using namespace std;
const int mod = 1e9 + 7;
int cnt = 0;
int f[2][51][51][51];
int n, m;
int a[51];
int C[51][51], CO[51], CE[51];
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
int main() {
    bool bz= 0, bz1 = 1;
    scanf("%d %d", &n, &m);
    C[0][0] = 1;
    CE[0] = 1;
    for (int i = 1; i <= n ; i++) {
        C[i][0] =1;
        for (int j = 1; j <= i; j ++)
            C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
        for (int j = 0; j <= i; j ++)
            if (j & 1)
                CO[i] = add(CO[i], C[i][j]);
            else
                CE[i] = add(CE[i], C[i][j]);
    }
    a[0] = 1;
    for (int i = 1; i <= n; i ++)
        a[i] = mul(a[i - 1], 2);
    f[0][0][0][0] = 1;
    for (int i = 1; i <= n; i ++, swap(bz, bz1)) {
        int v;
        scanf("%d", &v);
        int l = v, r = v;
        if (v == -1) {
            l = 0, r = 1;
        }
        for (int ob = 0; ob < i; ob ++)
            for (int eb = 0; eb + ob < i; eb ++ )
                for (int ow = 0; ow + eb + ob < i; ow ++)
                if (f[bz][ob][eb][ow]){
                    int ew = i - 1 - ob - eb - ow;
                    int v = f[bz][ob][eb][ow];
                    if (l == 0) {
                        f[bz1][ob][eb][ow + 1] = add(f[bz1][ob][eb][ow + 1], mul(a[ow + ew + eb], mul(v, CE[ob])));
                        f[bz1][ob][eb][ow] = add(f[bz1][ob][eb][ow], mul(a[ow + ew + eb], mul(v, CO[ob])));
                    }
                    if (r == 1){
                        f[bz1][ob+1][eb][ow] = add(f[bz1][ob+1][eb][ow], mul(a[ob + eb + ew], mul(v, CE[ow])));
                        f[bz1][ob][eb+1][ow] = add(f[bz1][ob][eb+1][ow], mul(a[ob + eb + ew], mul(v, CO[ow])));
                    }
                    f[bz][ob][eb][ow] = 0;
                }
    }
    int ans = 0;
    for (int ob = 0; ob <= n ; ob ++)
        for (int eb = 0; eb <= n ; eb ++)
            for (int ow = 0; ow <= n ;ow ++)
                if (!((ob + ow + m) & 1)) {
                    ans = add(ans, f[bz][ob][eb][ow]);
                }
    printf("%d\n", ans);
    return 0;
}