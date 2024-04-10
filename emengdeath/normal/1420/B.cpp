#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int sum[32];
int n, T;
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        long long ans = 0;
        memset(sum, 0, sizeof(sum));
        while (n --) {
            int x;
            scanf("%d", &x);
            x = __builtin_clz(x);
            ans += sum[x];
            sum[x] ++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}