#include <bits/stdc++.h>
using namespace std;
const int S1 = 200, S2 = 500;
int n, a[100010];
int b[100010], cnt[100010];
int rmain() {
    int ans = 0;
    for (int i = 0; i <= S1; i++) {
        for (int j = 1; j <= n; j++) b[j] = a[j] - j * i;
        sort(b + 1, b + 1 + n);
        for (int l = 1, r; l <= n; l = r + 1) {
            for (r = l; r < n && b[r + 1] == b[r]; r++);
            ans = max(ans, r - l + 1);
        }
    }
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n && j <= i + S2; j++) {
            int dy = a[j] - a[i];
            int dx = j - i;
            if (dy % dx == 0 && dy > 0) ans = max(ans, ++cnt[dy / dx] + 1);
        }
        for (int j = i + 1; j <= n && j <= i + S2; j++) {
            int dy = a[j] - a[i];
            int dx = j - i;
            if (dy % dx == 0 && dy > 0) cnt[dy / dx]--;
        }
    }
    return ans;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int ans = 1;
    ans = max(ans, rmain());
    for (int i = 1; i <= n; i++) a[i] = -a[i];
    ans = max(ans, rmain());
    printf("%d\n", n - ans);
}