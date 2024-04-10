#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e5  + 10;
int a[N];
long long all;
int n;
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        long long mx = 0;
        all = 0;
        for (int i = 1; i <= n; i ++)
        {
            scanf("%d", &a[i]);
            mx = max(mx, 1ll * a[i]);
            all += a[i];
        }
        long long x = (all + n - 2) / (n - 1);
        mx = max(x, mx);
        printf("%lld\n", mx * (n - 1) - all);
    }
    return 0;
}