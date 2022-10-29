#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1e5 + 1;
int n;
long long k;
int f[N], g[N];
long long a[N];
int main() {
    scanf("%d", &n);
    long long mx = 0;
    for (int i = 1; i <= n ; i ++) {
        scanf("%lld", &a[i]);
        mx = max(mx, a[i]);
    }
    for (int i = 1; i <= n; i ++)
        a[i] = mx - a[i], f[i] = 1e9;

    for (k = 0; (1ll << k) <= mx * 2; k ++) {
        sort(a + 1, a + n + 1, [](long long x, long long y) {return (x & ((1ll << k) - 1)) >(y & ((1ll << k) - 1));});
        for (int j = 0; j <= n; j  ++)
            g[j] = 1e9;
        int x = 0, y = 0;
        for (int j = 1; j <= n ; j ++)
            x += ((a[j] >> k) & 1);
        for (int j = 0; j <= n; j ++)
        {
            if (j) {
                x -= (a[j] >> k) & 1;
                y += (a[j] >> k) & 1;
            }
            if (j && j + 1 <= n && (a[j] & ((1ll << k) - 1)) == (a[j + 1] & ((1ll << k) - 1))) continue;
            g[y] = min(g[y], f[j] + x + j - y);
        }
        x = 0;
        for (int j = 1; j <= n ; j ++)
            x += ((a[j] >> k) & 1);
        y = 0;
        for (int j = 0; j <= n ; j ++) {
            if (j) {
                x -= ((a[j] >> k) & 1);
                y += ((a[j] >> k) & 1);
            }
            if (j && j + 1 <= n && (a[j] & ((1ll << k) - 1)) == (a[j+1] & ((1ll << k) - 1))) continue;
            g[j + x] = min(g[j + x], f[j] + n - j - x + y);
        }
        for (int j  =0; j <= n ; j++)
            f[j] = g[j];
    }
    printf("%d\n", f[0]);
    return 0;
}