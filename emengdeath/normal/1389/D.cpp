#include <algorithm>
#include <cstdio>
using namespace std;
int T;
int n, k, x, y, xx ,yy;
long long ans;
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        scanf("%d %d %d %d", &x, &y, &xx, &yy);
        long long a, b, stv;
        if (x > xx) swap(x, xx), swap(y, yy);
        if (xx <= min(y, yy)) {
            stv = min(y, yy) - xx;
            b = (max(y, yy) - x) - stv;
            a = 0;
        } else {
            b = yy - x;
            a = xx - y;
            stv = 0;
        }
        long long ans = 1e18;
        for (int i = 1; i <=n; i++) {
            long long V = 1ll * a * i;
            long long K = k - 1ll * stv * i;
            if (K > 0) {
                if (K <= 1ll * b * i)
                    V += K;
                else {
                    V += 1ll * b * i;
                    K -= 1ll * b * i;
                    V += K * 2;
                }
            }
            ans = min(ans, V);
        }
        printf("%lld\n", ans);
    }
    return 0;
}