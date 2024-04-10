#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010;
int n, m, op[maxn], l[maxn], r[maxn], d[maxn], a[maxn], ans[maxn], mn[maxn];

int main() {
    scanf("%d %d", &n, &m);
    memset(mn, 0x3f, sizeof(mn));
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d %d", &op[i], &l[i], &r[i], &d[i]);
        if (op[i] == 1) {
            for (int j = l[i]; j <= r[i]; j++) a[j] += d[i];
        } else {
            for (int j = l[i]; j <= r[i]; j++) mn[j] = min(mn[j], d[i] - a[j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        a[i] = ans[i] = min(mn[i], 1000000000);
    }
    for (int i = 1; i <= m; i++) {
        if (op[i] == 1) {
            for (int j = l[i]; j <= r[i]; j++) a[j] += d[i];
        } else {
            if (*max_element(a + l[i], a + r[i] + 1) != d[i]) puts("NO"), exit(0);
        }
    }
    puts("YES");
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}