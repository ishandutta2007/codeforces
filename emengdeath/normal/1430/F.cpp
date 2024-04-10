#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 3001;
int n, m;
bool can[N][N];
int t[N][N];
struct node{
    int l, r, v;
}a[N];
long long all[N][N];
long long f[N][2];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n; i ++) {
        scanf("%d %d %d", &a[i].l, &a[i].r, &a[i].v);
    }
    for (int i = 1; i <= n; i ++) {
        int nowl = a[i].l - 1, lfv = 0;
        int tmp = (a[i].v + m - 1) / m;
        if (tmp > a[i].r - a[i].l + 1) continue;
        nowl += tmp;
        lfv = m * tmp - a[i].v;
        can[i][i] = 1;
        t[i][i] = nowl;
        for (int j = i + 1; j <= n;j ++) {
            nowl = max(nowl, a[j].l);
            if (nowl <= a[j].r && 1ll * m * (a[j].r - nowl) >= a[j].v - lfv) {
                can[i][j] = 1;
                if (a[j].v <= lfv) {
                    lfv -= a[j].v;
                } else {
                    int tmp = (a[j].v  - lfv + m - 1)  / m;
                    nowl += tmp;
                    lfv = tmp * m - (a[j].v - lfv);
                }
                t[i][j] = nowl;
            } else break;
        }
        for (int j = i; j <= n;j ++)
            all[i][j] = all[i][j - 1] + a[j].v;
    }
    long long ans = 1e18;
    if (can[1][n]) ans = all[1][n];
    for (int i = 1; i < n; i ++) {
        f[i][0] = f[i][1] = 1e18;
        if (can[1][i]) {
            f[i][t[1][i] == a[i + 1].l] = (all[1][i] + m - 1) / m * m;
        }
        for (int j = 2; j <= i; j ++) {
            if (can[j][i]) {
                f[i][t[j][i] == a[i + 1].l] = min(f[j - 1][0] + (all[j][i] + m - 1) / m * m,
                                                  f[i][t[j][i] == a[i + 1].l]);
            }
        }
        if (can[i + 1][n])
            ans = min(ans, f[i][0] + all[i + 1][n]);
    }
    if (ans == 1e18) ans = -1;
    printf("%lld\n", ans);
    return 0;
}