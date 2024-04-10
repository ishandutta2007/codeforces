#include <bits/stdc++.h>
using namespace std;
int T, n;
int a[300010], b[300010], l[300010], r[300010];
inline void rmain() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i), b[i] = a[i];
    sort(b + 1, b + 1 + n);
    int cnt = unique(b + 1, b + 1 + n) - b - 1;
    for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + 1 + cnt, a[i]) - b;
    for (int i = 1; i <= cnt; i++) l[i] = 0;
    for (int i = 1; i <= n; i++) {
        if (l[a[i]] == 0) l[a[i]] = i;
        r[a[i]] = i;
    }
    int ans = 0;
    for (int L = 1, R; L <= cnt; L = R + 1) {
        for (R = L; R < cnt && l[R + 1] > r[R]; R++);
        ans = max(ans, R - L + 1);
    }
    printf("%d\n", cnt - ans);
}
int main() {
    scanf("%d", &T);
    while (T--) rmain();
}