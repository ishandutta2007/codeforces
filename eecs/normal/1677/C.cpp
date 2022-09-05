#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, a[maxn], b[maxn], p[maxn];
bool vis[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]), p[a[i]] = b[i];
        }
        fill(vis + 1, vis + n + 1, 0);
        int num = 0, num2 = 0;
        for (int i = 1; i <= n; i++) if (!vis[i]) {
            int cnt = 0;
            for (int j = i; !vis[j]; j = p[j]) {
                cnt++, vis[j] = 1;
            }
            num += cnt / 2;
            if (cnt % 2) num2++;
        }
        long long ans = 0;
        for (int i = 1; i <= n - num - num2; i++) ans -= 2 * i;
        for (int i = n - num + 1; i <= n; i++) ans += 2 * i;
        printf("%lld\n", ans);
    }
    return 0;
}