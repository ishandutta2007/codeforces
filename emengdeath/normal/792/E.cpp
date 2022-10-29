#include <algorithm>
#include <cstdio>
#include <ctime>
using namespace std;
int a[1000];
int n;
int main() {
    scanf("%d", &n);
    int x = 1e9, y;
    for (int i = 1; i<= n;i ++) {
        scanf("%d", &a[i]);
        x = min(x, a[i]);
    }
    bool sig = 1;
    x ++;
    long long ans  =1e18;
    while (x >= 1) {
        sig = 0;
        for (int i = 1; i <= n; i ++)
            if (a[i] / x < a[i] % x && !((a[i] / (x + 1) + 1) * (x +1) - a[i] <= a[i] /(x + 1) + 1) && a[i] % (x + 1) != 0) {
                sig = 1;
                while (a[i] / x < a[i] % x && !((a[i] / (x + 1) + 1) * (x +1) - a[i] <= a[i] /(x + 1) + 1) && a[i] % (x + 1) != 0) {
                    x =a[i] / (a[i] / x + 1);
                }
                break;
            }
        if (!sig) {
            long long v = 0;
            for (int i = 1; i <= n; i ++) {
                long long w = 1e18;
                if ((a[i] / (x + 1) + 1) * (x +1) - a[i] <= a[i] /(x + 1) + 1)
                    w = min(1ll * a[i] /(x + 1) + 1, w);
                if (a[i] / x < a[i] % x)
                    w = min(1ll * a[i] / x, w);
                if (a[i] % (x + 1) == 0)
                    w = min(1ll * a[i] / (x + 1), w);
                v += w;
            }
            ans =min(ans, v);
            x --;
        }
    }

    printf("%lld\n", ans);
    return 0;
}