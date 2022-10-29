#include <algorithm>
#include <cstdio>
using namespace std;
int a[1000001];
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n;i ++) scanf("%d", &a[i]);
        int x;
        x = a[1];
        long long v = 0;
        int mx = 0;
        mx = abs(a[1] - a[2]);
        for (int i = 2; i <= n;i ++){
            int y = a[i];
            v += abs(x - y);
            x = y;
            if (i != n && 1ll * (a[i] - a[i - 1]) *(a[i] - a[i + 1]) >= 0) {
                mx = max(mx, min(abs(a[i] - a[i - 1]), abs(a[i + 1] - a[i])) * 2);
            }
            if (i == n)
                mx = max(mx, abs(a[i] - a[i - 1]));
        }
        printf("%lld\n", v - mx);
    }
    return 0;
}