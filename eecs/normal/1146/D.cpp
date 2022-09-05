#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int m, a, b, vis[maxn];
long long ans;

int main() {
    scanf("%d %d %d", &m, &a, &b);
    memset(vis, -1, sizeof(vis));
    int x = 0, y = 0, tot = 0;
    while (1) {
        vis[x] = y;
        if (x >= b) x -= b;
        else x += a;
        if (!x) break;
        y = max(y, x);
    }
    for (int i = 0; i < a + b; i++) {
        if (~vis[i]) ans += max(0, m - vis[i] + 1);
    }
    if (m >= a + b) {
        m -= a + b;
        int g = __gcd(a, b);
        int fir = m + 1;
        int lst = m - (m / g * g) + 1;
        int cnt = (fir - lst) / g + 1;
        ans += 1LL * (fir + lst) * cnt / 2;
    }
    printf("%lld\n", ans);
    return 0;
}