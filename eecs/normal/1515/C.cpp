#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, m, x, h[maxn], cur[maxn], id[maxn], ans[maxn], id2[maxn], val[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &x);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &h[i]);
        }
        iota(id + 1, id + m + 1, 1);
        fill(cur + 1, cur + m + 1, 0);
        for (int i = 1; i <= n; i += m) {
            sort(id + 1, id + m + 1, [&](int x, int y) { return cur[x] > cur[y]; });
            for (int j = 1; j <= m; j++) {
                id2[j] = j, val[j] = i + j - 1 <= n ? h[i + j - 1] : 0;
            }
            sort(id2 + 1, id2 + m + 1, [&](int x, int y) { return val[x] < val[y]; });
            for (int j = 1; j <= m; j++) {
                if (i + id2[j] - 1 <= n) ans[i + id2[j] - 1] = id[j];
                cur[id[j]] += val[id2[j]];
            }
        }
        puts("YES");
        for (int i = 1; i <= n; i++) {
            printf("%d ", ans[i]);
        }
        putchar('\n');
    }
    return 0;
}