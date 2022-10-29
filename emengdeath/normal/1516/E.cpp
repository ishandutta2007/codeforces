#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int n, m;
const int mod = 1e9 + 7;
int add(int x, int y) {
    x += y;
    return x >= mod ? x - mod : x;
}
int sub(int x, int y) {
    x -= y;
    return x < 0 ? x + mod  : x;
}
int mul(int x, int y) {
    return 1ll * x * y % mod;
}
int calc(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z= mul(z, x);
        x = mul(x, x), y >>= 1;
    }
    return z;
}
int inv(int x) {
    return calc(x, mod-  2);
}
int CC[1000][1000];
int C(int x, int y) {
    if (x < y) return 0;
    if (CC[n - x][y]) return CC[n - x][y] - 1; 
    int ans = 1;
    for (int i = 1; i <= y;  i++)
        ans = mul(ans, mul(inv(i), x - i + 1));
    CC[n - x][y] = ans + 1;
    return ans;
}
int ans[1000];
int f[202][403];
int a[202], b[202];
int main() {
    scanf("%d %d", &n, &m);
    f[0][0] = 1;
    a[0] = b[0] = 1;
    for (int i = 1; i <= m + 1; i ++)
        a[i] = mul(a[i - 1], inv(i)), b[i] = mul(b[i - 1], i);
    for (int i = 1; i <= m; i ++)
        for (int j = m; j >= 0; j --)
            for (int k = m * 2; k >= 0; k --)
                if (f[j][k]) {
                    int v = f[j][k];
                    for (int l = 1; j + l * i <= m; l ++) {
                        v = mul(v, C(n - k - (l - 1) * (i + 1), i + 1));
                        v = mul(v, b[i]);
                        f[j + l * i][k + (i + 1) * l] = add(f[j + l * i][k + (i + 1) * l], mul(v, a[l]));
                    }
                }
    ans[0] = 1;
    for (int i = 1; i <= m; i ++) {
        for (int j =  0; j <= m * 2;  j ++)
            ans[i] = add(ans[i], f[i][j]);
        if (i != 1) ans[i] = add(ans[i], ans[i - 2]);
        printf("%d%c", ans[i], " \n"[i == m]);
    }
    return 0;
}