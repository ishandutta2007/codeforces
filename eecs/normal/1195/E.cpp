#include <bits/stdc++.h>
using namespace std;

const int maxn = 3010;
int n, m, R, C, x, y, z, g[maxn * maxn], a[maxn][maxn], rr[maxn][maxn], rrr[maxn][maxn];
struct node { int x, d; } q[maxn * maxn];
long long ans;

int main() {
    scanf("%d %d %d %d", &n, &m, &R, &C);
    scanf("%d %d %d %d", &g[0], &x, &y, &z);
    for (int i = 1; i < n * m; i++) {
        g[i] = (1LL * g[i - 1] * x + y) % z;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = g[(i - 1) * m + j - 1];
        }
    }
    int id; node k;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = 0;
        for (int j = 1; j <= C; j++) {
            k.x = j, k.d = a[i][j];
            while (q[r].d > k.d && l <= r) r--;
            q[++r] = k, id = j;
        }
        for (int j = 1; j + C - 1 <= m; j++) {
            while (q[l].x < j) l++;
            rr[i][j] = q[l].d, id++;
            k.x = id, k.d = a[i][id];
            while (q[r].d > k.d && l <= r) r--;
            q[++r] = k;
        }
    }
    for (int i = 1; i <= m; i++) {
        int l = 1, r = 0;
        for (int j = 1; j <= R; j++) {
            k.x = j, k.d = rr[j][i];
            while (q[r].d > k.d && l <= r) r--;
            q[++r] = k, id = j;
        }
        for (int j = 1; j + R - 1 <= n; j++) {
            while (q[l].x < j) l++;
            rrr[j][i] = q[l].d, id++;
            k.x = id, k.d = rr[id][i];
            while (q[r].d > k.d && l <= r) r--;
            q[++r] = k;
        }
    }
    for (int i = 1; i + R - 1 <= n; i++) {
        for (int j = 1; j + C - 1 <= m; j++) {
            ans += rrr[i][j];
        }
    }
    printf("%lld\n", ans);
    return 0;
}