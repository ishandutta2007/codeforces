#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
using namespace std;
const int mod = 998244353;
int f[51][51][51], a[51], w[51], ni[100000];
int n, m;
void update(int&x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}
int work(int sig, int w, int all[2]){
    memset(f, 0, sizeof(f));
    f[0][0][0] = 1;
    for (int i = 0; i < m; i ++)
        for (int j = 0;j <= i ; j ++)
            for (int k = 0; k + j <= i ; k ++)
                if (f[i][j][k]) {
                    int a0 = all[0] - k, a1 = all[1] + (i - j - k);
                    int W = w;
                    if (!sig) W -= j;
                    else
                        W += j;
                    update(f[i + 1][j + 1][k], (long long)f[i][j][k] * W % mod * ni[a0 + a1 + W] % mod);
                    update(f[i + 1][j][k + 1], (long long)f[i][j][k] * a0 % mod * ni[a0 + a1 + W] % mod);
                    update(f[i + 1][j][k], (long long)f[i][j][k] * a1 % mod * ni[a0 + a1 + W] % mod);

                }
    int ans = 0;
    for (int i = 0; i <= m ; i++)
        for (int j = 0; j + i <= m; j ++) {
            int W = w;
            if (!sig) W -=i;
            else
                W += i;
            update(ans, (long long) f[m][i][j] * W % mod);
        }
    return ans;
}
long long calc(long long x,long long y) {
    long long z = 1;
    while (y) {
        if (y & 1) z = z * x % mod;
        x = x *x % mod, y /= 2;
    }
    return z;
}
int main(){
    ni[0] = 1;
    for (int i = 1; i < 100000; i ++)
        ni[i] = calc(i, mod - 2);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n ; i ++)
        scanf("%d", &a[i]);
    int all[2] = {0};
    for (int i = 1; i <= n ; i ++)
        scanf("%d", &w[i]), all[a[i]] += w[i];
    for (int i = 1; i <= n ; i ++) {
        all[a[i]] -= w[i];
        printf("%d\n", work(a[i], w[i], all));
        all[a[i]] += w[i];
    }
    return 0;
}