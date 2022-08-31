#include <bits/stdc++.h>
using namespace std;
typedef double db;
int n, T;
db x[100010], y[100010];
inline void rmain() {
    scanf("%d", &n);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n * 2; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == 0) ::y[++cnt2] = 1ll * y * y;
        else ::x[++cnt1] = 1ll * x * x;
    }
    sort(x + 1, x + 1 + n);
    sort(y + 1, y + 1 + n);
    double ans = 0;
    for (int i = 1; i <= n; i++) ans += sqrt(x[i] + y[i]);
    printf("%.12lf\n", ans);
}
int main() {
    scanf("%d", &T);
    while (T--) rmain();
}