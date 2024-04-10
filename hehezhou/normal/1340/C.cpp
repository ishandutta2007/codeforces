#include <bits/stdc++.h>
using namespace std;
int dis[10010][1010];
int n, g, r, m;
int d[10010];
pair < int, int > a[10000010], b[10000010];
int ta, tb;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d", d + i);
    scanf("%d%d", &g, &r);
    ta = 1;
    dis[1][0] = 1;
    a[0] = {1, 0};
    sort(d + 1, d + 1 + m);
    while (ta) {
        tb = 0;
        for (int i = 0; i < ta; i++) {
            int x = a[i].first, y = a[i].second;
            if (y == g && dis[x][0] == 0) {
                b[tb++] = {x, 0};
                dis[x][0] = dis[x][y] + 1;
            }
            if (x < m && y + d[x + 1] - d[x] <= g && dis[x + 1][y + d[x + 1] - d[x]] == 0) {
                a[ta++] = {x + 1, y + d[x + 1] - d[x]};
                dis[x + 1][y + d[x + 1] - d[x]] = dis[x][y];
            }
            if (x > 1 && y + d[x] - d[x - 1] <= g && dis[x - 1][y + d[x] - d[x - 1]] == 0) {
                a[ta++] = {x - 1, y + d[x] - d[x - 1]};
                dis[x - 1][y + d[x] - d[x - 1]] = dis[x][y];
            }
        }
        for (int i = 0; i < tb; i++) a[i] = b[i];
        ta = tb;
    }
    long long ans = 1000000000000000000ll;
    for (int i = 0; i <= g; i++) if (dis[m][i]) ans = min(ans, 1ll * (r + g) * dis[m][i] + i);
    if (ans == 1000000000000000000ll) puts("-1");
    else printf("%lld\n", ans - r - g);
}