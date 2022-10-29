#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
const int M = 1e3 + 10;
struct node{
    int x[2], y[2];
    int id;
}w[N];
int a[M][M], f[M][M];
int n, m, q;
int ans[N];
int get(int x1, int y1, int x2, int y2) {
    return a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
}
bool allone(int x1, int y1, int x2, int y2) {
    return get(x1, y1, x2, y2) == (y2 - y1 + 1) * (x2 - x1 + 1) ;
}
bool is_emp(int x1, int y1, int x2, int y2) {
    if (x2 < x1 || y2 < y1) return 1;
    return f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1 - 1][y1 - 1] == 0;
}
void work(int l, int r, int ll ,int rr) {
    if (r < l || ll > rr) return;
    int mmid = (ll + rr) / 2;
    int mid = l - 1;
    for (int i = 1; i + mmid - 1 <= n; i ++)
        for (int j = 1; j + mmid - 1 <= m; j ++)
            f[i][j] = allone(i, j, i + mmid - 1, j + mmid - 1), f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
    for (int i = l; i <= r; i ++)
        if (is_emp(w[i].x[0], w[i].y[0], w[i].x[1] - mmid + 1, w[i].y[1] - mmid + 1)) swap(w[++mid], w[i]);
        else
            ans[w[i].id] = mmid;
    work(l, mid, ll, mmid - 1);
    work(mid + 1, r, mmid + 1, rr);
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            scanf("%d", &a[i][j]), a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    scanf("%d", &q);
    for (int i = 1; i <= q; i ++) {
        scanf("%d %d %d %d", &w[i].x[0], &w[i].y[0], &w[i].x[1], &w[i].y[1]);
        w[i].id = i;
    }
    work(1, q, 1, min(n, m));
    for (int i = 1; i <= q; i ++)
        printf("%d\n", ans[i]);
    return 0;
}