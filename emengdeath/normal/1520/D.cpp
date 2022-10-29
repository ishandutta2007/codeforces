#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int a[400001];
long long calc(int x) {
    return 1ll * (x - 1) * x  / 2;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        for (int i = -n; i <=  n; i ++) a[n + i] = 0;
        for (int i = 1; i <= n; i ++) {
            int x;
            scanf("%d", &x);
            a[x - i + n] ++;
        }
        long long ans = 0;
        for (int i = -n; i <= n; i++) {
            ans += calc(a[i + n]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}