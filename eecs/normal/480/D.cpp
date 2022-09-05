#include <bits/stdc++.h>
using namespace std;

const int maxn = 510, maxS = 1010;
int n, S, ans, f[maxn][maxS], g[maxn], pre[maxn], id[maxn], pos[maxn];
array<int, 5> a[maxn];

int main() {
    scanf("%d %d", &n, &S);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) scanf("%d", &a[i][j]);
    }
    a[0] = {-1, 2 * n + 1, 0, S, 0};
    sort(a, a + n + 1, [&](array<int, 5> x, array<int, 5> y) {
        return x[0] ^ y[0] ? x[0] < y[0] : x[1] > y[1];
    });
    for (int i = n; ~i; i--) {
        iota(id + i + 1, id + n + 1, i + 1);
        sort(id + i + 1, id + n + 1, [&](int x, int y) {
            return a[x][1] ^ a[y][1] ? a[x][1] < a[y][1] : a[x][0] > a[y][0];
        });
        for (int $ = i + 1; $ <= n; $++) {
            int k = id[$];
            pos[$] = i;
            while (pos[$] + 1 < $ && a[id[pos[$] + 1]][1] <= a[k][0]) pos[$]++;
        }
        for (int j = a[i][2]; j <= S; j++) {
            int o = min(j - a[i][2], a[i][3]);
            g[i] = pre[i] = 0;
            int lst = i;
            for (int $ = i + 1; $ <= n && a[id[$]][1] <= a[i][1]; $++) {
                int k = id[$];
                g[$] = f[k][o] + pre[pos[$]];
                pre[$] = max(pre[$ - 1], g[$]);
                lst = $;
            }
            f[i][j] = a[i][4] + pre[lst];
        }
    }
    printf("%d\n", f[0][S]);
    return 0;
}