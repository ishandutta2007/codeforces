#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 511;
struct node{
    int fa, sum;
    int x0, x1, y0, y1;
}f[N * N];
int n, k;
int g[N][N];
bool bz[N][N];
int tag[N * N];
int cnt = 0;
#define id(x, y) (((x) - 1) * n + (y))
int getfa(int x) {
    return f[x].fa == x? x : f[x].fa = getfa(f[x].fa);
}
void merge(int x, int y) {
    x = getfa(x);
    y = getfa(y);
    if (x == y) return;
    f[x].sum += f[y].sum;
    f[x].x0 = min(f[x].x0, f[y].x0);
    f[x].x1 = max(f[x].x1, f[y].x1);
    f[x].y0 = min(f[x].y0, f[y].y0);
    f[x].y1 = max(f[x].y1, f[y].y1);
    f[y].fa = x;
}
int update(int x) {
    x = getfa(x);
    if (tag[x] == cnt) return 0;
    tag[x] = cnt;
    return f[x].sum;
}
int main() {
    scanf("%d %d", &n, &k);
    for (int i= 1; i <= n; i ++)
        for (int j = 1;j  <= n; j ++) {
            char c;
            scanf(" %c", &c);
            bz[i][j] = (c == '.');
            if (bz[i][j])
                f[id(i, j)] = {id(i, j), 1, i, i , j, j};
            if (bz[i][j] && bz[i - 1][j])
                merge(id(i,j), id(i - 1, j));
            if (bz[i][j] && bz[i][j - 1])
                merge(id(i, j), id(i, j - 1));
        }
    for (int i = 1; i <= n * n; i ++)
        if (f[i].fa && getfa(i) == i) {
            int x0 = max(f[i].x1 - k + 1, 1), x1 = f[i].x0, y0 = max(1,f[i].y1 - k + 1), y1 = f[i].y0;
            if (x0 <= x1 && y0 <= y1)
            {
                for (int j = x0; j <= x1; j ++)
                    g[j][y0] += f[i].sum, g[j][y1 + 1] -= f[i].sum;
            }
        } else
            if (!f[i].fa) {
                int x1 = (i - 1) / n + 1, y1 = (i - 1) % n + 1;
                int x0 = max(1,x1 - k + 1), y0 = max(1, y1 - k + 1);
                for (int j = x0; j <= x1; j++)
                    g[j][y0] ++, g[j][y1 + 1] --;
            }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            g[i][j] += g[i][j - 1];
    int ans = 0;
    for (int i = 1; i + k - 1<= n; i ++)
        for (int j = 1; j + k - 1<= n; j ++) {
            ++cnt;
            int v = g[i][j];
            for (int l = 0; l < k; l ++) {
                if (bz[i + l][j - 1])
                    v += update(id(i + l, j - 1));
                if (bz[i + l][j + k])
                    v += update(id(i + l, j + k));
                if (bz[i - 1][j + l])
                    v += update(id(i - 1, j + l));
                if (bz[i + k][j + l])
                    v += update(id(i + k, j + l));
            }
            ans = max(ans, v);
        }
    printf("%d\n", ans);
    return 0;
}