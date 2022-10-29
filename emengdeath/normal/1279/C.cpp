#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e6;
int n, m;
int a[N];
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n ; i ++) {
            int x;
            scanf("%d", &x), a[x] = i;
        }
        int r = 1;
        long long ans = 0;
        for (int i = 1; i <= m; i ++){
            int x;
            scanf("%d", &x);
            x = a[x];
            if (x <= r) ans ++;
            else {
                ans += (x - i) * 2 + 1;
                r = x;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}