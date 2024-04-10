#include <bits/stdc++.h>
using namespace std;
int t, n;
int w[100010], d[100010];
int a[100010];
inline void rmain() {
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 1; i <= n; i++) d[i] = 0, scanf("%d", w + i), ans += w[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        d[u]++, d[v]++;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j < d[i]; j++) a[++cnt] = w[i];
    sort(a + 1, a + 1 + cnt);
    reverse(a + 1, a + 1 + cnt);
    for (int i = 0; i < n - 1; i++) printf("%lld%c", ans += a[i], " \n"[i == n - 2]);
}
int main() {
    scanf("%d", &t);
    while (t--) rmain();
}