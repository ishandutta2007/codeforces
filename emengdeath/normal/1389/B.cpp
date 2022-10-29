#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int T, n, k, z;
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d %d", &n, &k, &z);
        for (int i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        int all = 0;
        int mx = 0;
        int ans = 0;
        for (int i = 1; i <= k + 1; i ++) {
            all += a[i];
            if (i != n)
                mx = max(mx, a[i] + a[i + 1]);
            if (!((k + 1 - i) & 1)) {
                int sum = ((k + 1)- i) / 2;
                if (sum <= z)
                    ans = max(ans, mx * sum + all);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}