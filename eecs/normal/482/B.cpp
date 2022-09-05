#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, a[maxn], l[maxn], r[maxn], v[maxn], sum[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &l[i], &r[i], &v[i]);
    }
    for (int i = 0; i < 30; i++) {
        memset(sum, 0, sizeof(sum));
        for (int j = 1; j <= m; j++) if (v[j] >> i & 1) {
            sum[l[j]]++, sum[r[j] + 1]--;
        }
        for (int j = 1; j <= n; j++) {
            sum[j] += sum[j - 1];
            if (sum[j]) a[j] |= 1 << i;
        }
        for (int j = 1; j <= n; j++) {
            sum[j] = sum[j - 1] + (sum[j] > 0);
        }
        for (int j = 1; j <= m; j++) if (!(v[j] >> i & 1)) {
            if (sum[r[j]] - sum[l[j] - 1] == r[j] - l[j] + 1) puts("NO"), exit(0);
        }
    }
    puts("YES");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}