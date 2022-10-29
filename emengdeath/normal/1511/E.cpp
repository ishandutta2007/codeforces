#include <algorithm>
#include <cstdio>
using namespace std;
int n, m;
char a[1000000], aa[1000000];
int b[1000000];
int cnt;
int ans;
int f[1000000];
int id(int x, int y, int n, int m) {
    return (x - 1) * m + y;
}
const int mod = 998244353;
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
void work(char *a, int n, int m) {
    for (int i = 1; i <= n; i ++)
    {
        int sum = 0;
        for (int j = m; j >= 1; j --)
            if (a[id(i, j, n, m)] == 'o') {
                sum ++;
                int ccnt= cnt - sum;
                if (j != 1 && a[id(i, j - 1, n, m)] == 'o')
                    ccnt --;
                ans = add(ans, mul(f[sum - 1], calc(2, sum - 1 + ccnt)));
                ans = add(ans, mul(sum / 2, calc(2, ccnt)));
            } else {
                sum = 0;
            }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    b[0] = 1;
    for (int i  = 1 ;i <= n * m ; i  ++)
        b[i] = mul(b[i - 1],  2);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            scanf(" %c", &a[id(i, j, n, m)]);
            aa[id(j, i, m, n)] = a[id(i, j, n, m)];
            cnt += (a[id(i, j, n, m)] == 'o');
        }
    for (int i = 1; i <= cnt; i ++)
        f[i] = add(f[i - 1], mul(i / 2, inv(calc(2, i))));
    work(a, n, m);
    work(aa, m, n);
    printf("%d\n", ans);
    return 0;
}