#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 14, maxm = 110;
int n, m, ans, f[maxn][maxm], g[maxn][maxm], d1[maxn][14], d2[maxn][maxm];

struct P { int x, y, t; } a[14], b[maxm];
int dist(P a, P b) { return abs(a.x - b.x) + abs(a.y - b.y); }

void chk_min(int &x, int y) { if (x > y) x = y; }
void chk_max(int &x, int y) { if (x < y) x = y; }

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &b[i].x, &b[i].y, &b[i].t);
    }
    sort(b, b + m, [&](P a, P b) { return a.t < b.t; });
    memset(f, 0x3f, sizeof(f));
    memset(g, -0x3f, sizeof(g));
    memset(d1, 0x3f, sizeof(d1));
    memset(d2, 0x3f, sizeof(d2));
    for (int i = 0; i < n; i++) f[1 << i][0] = 0;
    for (int i = 0; i < m; i++) g[0][i] = 1;
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) if (!(i >> j & 1)) {
            for (int k = 0; k < n; k++) if (i >> k & 1) {
                d1[i][j] = min(d1[i][j], dist(a[j], a[k]));
            }
        }
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) if (i >> k & 1) {
                d2[i][j] = min(d2[i][j], dist(b[j], a[k]));
            }
        }
    }
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < m; j++) if (f[i][j] <= 1e9) {
            for (int k = 0; k < n; k++) if (!(i >> k & 1)) {
                chk_min(f[i | (1 << k)][j], f[i][j] + d1[i][k]);
            }
            for (int k = 0; k < m; k++) if (f[i][j] + d2[i][k] <= b[k].t) {
                chk_max(g[i][k], j + 1);
            }
        }
        for (int j = 0; j < m; j++) if (g[i][j] >= 0) {
            for (int k = j + 1; k < m; k++) {
                if (b[j].t + min(dist(b[j], b[k]), d2[i][k]) > b[k].t) continue;
                chk_max(g[i][k], g[i][j] + 1);
            }
            for (int k = 0; k < n; k++) if (!(i >> k & 1)) {
                chk_min(f[i | (1 << k)][g[i][j]], b[j].t + min(dist(b[j], a[k]), d1[i][k]));
            }
            chk_max(ans, g[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}