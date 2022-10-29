#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
__int128 f[6], g[6], ff[6];
int T;
int n;
__int128 max1(__int128 x, __int128 y) {
    return x < y? y : x;
}
__int128 min1(__int128 x, __int128 y) {
    return x < y? x : y;
}
void output(__int128 x ){
    if (!x) return;
    output(x / 10);
    printf("%d", (int)(x % 10));
}
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        __int128 ans = 1e5;
        ans *= ans;
        ans *= ans;
        ans *= -1;
        f[0] = 1;
        g[0] = 1;
        ff[0] = 1;
        __int128 inf = -ans;
        for (int i = 1; i <= 5;  i++) f[i] = g[i] = 0, ff[i] = -ans;
        while (n --) {
            int x;
            scanf("%d", &x);
            if (!x) {
                ans = 0;
                continue;
            }
            if (x < 0) {
                x = -x;
                for (int i = 5; i >= 1; i --)
                    f[i] = max1(f[i], f[i - 1] * x), ff[i] = min1(ff[i], ff[i - 1] * x);
            } else {
                for (int i = 5; i >= 1; i --)
                    g[i] = max1(g[i], g[i - 1] * x);
            }
        }
        for (int i = 0; i <= 5; i ++) {
            if (f[i] && g[5 - i]) {
                ans = max1(ans, f[i] * g[5 - i] * (1 - 2 * (i & 1)));
            }
            if (ff[i] !=inf && g[5 - i]) {
                ans = max1(ans, ff[i] * g[5 - i] * (1 - 2 * (i & 1)));
            }
        }
        if (!ans) puts("0");
        else {
            if (ans < 0) putchar('-'), ans = -ans;
            output(ans);
            puts("");
        }
    }
    return 0;
}