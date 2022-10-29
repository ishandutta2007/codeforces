#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 511;
long long f[2][N][N];
struct node{
    int a, b, k;
}a[N];
int n;
long long ans = 0;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d %d %d", &a[i].a, &a[i].b, &a[i].k);
    }
    sort(a + 1, a + n + 1, [](const node&a, const node&b) {
        return a.b > b.b;
    });
    for (int i = 0; i < 2; i ++)
        for (int j = 0; j <= n; j ++)
            for (int l = 0; l <= n; l ++)
                f[i][j][l] = -1e18;
    bool bz = 0, bz1 = 1;
    f[0][0][0]= 0;
    for (int i = 1; i <= n; i ++, swap(bz, bz1)) {
        for (int j = 0; j <= n; j ++)
            for (int k = 0; k <= n; k ++)
                f[bz1][j][k] = 1e-18;
        for (int j = i; j >= 0; j --)
        for (int l = i - j; l >=0; l --){
            f[bz1][j][l] = f[bz][j][l];
            if (j)
                f[bz1][j][l] = max(f[bz1][j][l], f[bz][j - 1][l] + a[i].a - 1ll * (j -1) * a[i].b);
            if (l)
                f[bz1][j][l] = max(f[bz1][j][l], f[bz][j][l - 1] + a[i].a - 1ll * a[i].k * a[i].b);
        }
    }
    for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= n; j ++)
            ans = max(ans, f[bz][i][j]);
    printf("%lld\n", ans);
    return 0;
}