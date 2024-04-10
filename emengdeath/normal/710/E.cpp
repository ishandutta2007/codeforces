#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e7 +10;
long long f[N * 2];
int n, x, y, l, r;
int id[N * 2];
int main() {
    scanf("%d %d %d", &n, &x, &y);
    for (int i = 1; i <= n + n; i++)
        f[i] = 1e18;
    l = 1, r = 0;
    for (int i = 0; i <= n; i ++) {
        while (l <= r && id[l] <= i) ++l;
        if (l <= r)
            f[i] = min(f[i], f[id[l]] + 1ll * x * (id[l] - i));
        if (i) {
            f[i+i] = min(f[i+i], f[i] + y);
            id[++r] = i+i;
            while (l < r && f[id[r]] + 1ll * x * id[r] <= f[id[r - 1]] + 1ll * x * id[r - 1])
                id[r - 1] = id[r], r --;
        }
        f[i + 1] = min(f[i+1], f[i] + x);
    }
    printf("%lld\n", f[n]);
    return 0;
}