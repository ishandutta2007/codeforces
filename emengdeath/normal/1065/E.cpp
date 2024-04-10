#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int mod = 998244353;
const long long mod2 =1ll *  mod * mod;
long long a[4], b[4][4], c[4][4];
int A, n, m;
int ans;
int d[1000000];
int add(int x, int y) {
    x+= y;
    return x >= mod ?x - mod : x;
}

long long add2(long long x, long long y) {
    x+= y;
    return x >= mod2 ?x - mod2 : x;
}
int sub(int x, int y) {
    x -= y;
    return x < 0 ? x +mod : x;
}
int mul(int x, int y){
    return 1ll * x * y % mod;
}
int f(int n) {
    int v = A % mod;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    a[2] = v;
    a[3] = 1ll * A * (A - 1) / 2 % mod;
    b[2][0] = 1;
    b[3][1] = 1;
    b[2][2] = v;
    b[2][3] = 1ll * A * (A - 1) / 2 % mod;
    b[3][3] = mul(v, v);
    while (n) {
        if (n & 1) {
            for (int i = 0; i < 4; i ++)
                for (int j = 0; j < 4; j ++)
                    c[0][j] = add2(c[0][j],a[i] * b[i][j]);
            for (int i = 0; i < 4; i ++)
                a[i] = c[0][i] % mod, c[0][i] = 0;
        }
        for (int i = 0; i < 4; i ++)
            for (int j = 0; j < 4; j ++)
                for (int k = 0; k < 4; k ++)
                    c[i][k] = add2(c[i][k], b[i][j] * b[j][k]);
        for (int i = 0; i < 4; i ++)
            for (int j = 0; j < 4; j ++)
                b[i][j] = c[i][j] % mod, c[i][j] = 0;
        n >>= 1;
    }
    return add(a[0], a[1]);
}
int calc(int x, int y) {
    x %= mod;
    int z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x), y >>= 1;
    }
    return z;
}
int main() {
    scanf("%d %d %d", &n, &m, &A);
    for (int i = 1; i <= m; i ++)
        scanf("%d", &d[i]);
    sort(d + 1, d + m + 1);
    ans = 1;
    for (int i = 1; i <= m; i ++)
        ans = mul(ans, f(d[i] - d[i -1]));
    ans = mul(ans, calc(A, max(n - d[m] * 2, 0)));
    printf("%d\n", ans);
    return 0;
}