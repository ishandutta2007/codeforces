#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1010;
const int mod = 1e9 + 7;
int a[N][N], f[N][N][2][2];
int n;
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
int calc(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x), y >>= 1;
    }
    return z;
}

bool can_link(int x, int y) {
    if (x > n) x -= n;
    if (y > n) y -= n;
    return a[x][y];
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n + n ; i ++)
        for (int j = 0; j < 2; j ++)
            for (int k = 0; k < 2; k ++)f[i][i + 1][j][k] = 1;
    for (int i = 3; i <= n; i ++)
        for (int l = 1; l + i - 1 <= n + n ; l ++) {
            int r = l + i - 1;
            for (int ls = 0; ls < 2; ls ++)
                for (int rs = 0; rs < 2; rs ++)
                    for (int k = l + 1; k < r ; k ++) {
                        if (ls && can_link(l, k)) {
                            f[l][r][ls][rs] = add(f[l][r][ls][rs], mul(f[l][k][1][1], f[k][r][1][rs]));
                        }
                        if (rs && can_link(k, r)) {
                            f[l][r][ls][rs] = add(f[l][r][ls][rs], mul(f[l][k][0][1], f[k][r][1][rs]));
                        }
                    }
        }
    int ans = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = i + 1; j <= n; j ++)
            if (can_link(i, j))
            ans = add(ans, mul(f[i][j][1][1], f[j][i + n][1][1]));
    printf("%d\n", mul(ans, calc(n - 1, mod - 2)));
    return 0;
}