#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 200;
const int mod = 1e9 + 7;
int a[N], b[N][N], c[N][N];
int add(int x, int y) {
    x += y;
    return x >= mod ? x - mod : x;
}
int mul(int x, int y) {
    return 1ll * x * y % mod;
}
int m;
long long n;
int main() {
    scanf("%lld%d", &n, &m);
    for (int i = 2; i <= m; i ++)
        b[i][i -1] =1;
    b[1][m] = 1;
    b[m][m] = 1;
    a[m] = 1;
    while (n) {
        if (n & 1) {
            for (int i = 1; i<=m; i ++)
                for (int j = 1; j <= m; j ++)
                    c[0][j] = add(c[0][j], mul(a[i], b[i][j]));
            for (int i = 1; i <= m; i ++)
                a[i] = c[0][i], c[0][i] = 0;
        }
        for (int i = 1; i <= m; i ++)
            for (int j = 1; j <= m; j ++)
                for (int k = 1; k <= m; k ++)
                    c[i][k] = add(c[i][k], mul(b[i][j], b[j][k]));
        for (int i = 1; i <=m ; i ++)
            for (int j = 1; j <= m; j ++)
                b[i][j]= c[i][j], c[i][j] = 0;
        n >>= 1;
    }
    printf("%d\n", a[m]);
    return 0;
}