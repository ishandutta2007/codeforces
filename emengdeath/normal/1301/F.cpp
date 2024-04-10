#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e3 + 1;
int n, m, k, tag;
int f[N][N], a[N][N];
int dis[N][N][41];
int bz[N][N];
int bz1[N];
int d[N *  N][3];
int ans;
int b[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
bool check(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= m;
}
void work(int c) {
    ++tag;
    int tot = 0;
    for (int i = 1;i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if (a[i][j] == c) {
                bz[i][j] = tag;
                d[++tot][0] = i;
                d[tot][1] = j;
                d[tot][2] = 0;
            }
    for (int i = 1; i <= tot ; i ++) {
        for (int j = 0; j < 4; j++) {
            int x = d[i][0] + b[j][0], y = d[i][1] + b[j][1];
            if (!check(x, y)) continue;
            if (bz[x][y] != tag) {
                bz[x][y] = tag;
                d[++tot][0] = x, d[tot][1] = y, d[tot][2] = d[i][2] + 1;
            }
        }
        dis[d[i][0]][d[i][1]][c] = d[i][2];
        f[c][a[d[i][0]][d[i][1]]] = min(f[c][a[d[i][0]][d[i][1]]], 1 + d[i][2]);
    }
}
vector<pair<int, int> > work(int x, int y) {
    vector<pair<int, int> > d;
    for (int i = 1; i <= k; i ++)
        if (dis[x][y][i] != 1e9)
            d.push_back(make_pair(i, dis[x][y][i]));
    return d;
}
int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1;i <= n; i ++)
        for (int j = 1 ;j <= m; j ++) {
            scanf("%d", &a[i][j]);
            for (int l = 1; l <= k; l ++)
                dis[i][j][l] = 1e9;
        }
    for (int i = 1; i <= k ; i ++)
        for (int j = 1; j < i; j ++)
            f[i][j] = f[j][i] = 1e9;
    for (int i = 1; i <= k; i ++)
        work(i);
    for (int i = 1; i <= k; i ++)
        for (int j = 1; j <= k; j ++)
            if (i != j)
                for (int l = 1; l <= k ;l ++)
                    if (l != i && l != j)
                        f[j][l] = min(f[j][l], f[j][i] + f[i][l]);
    int q;
    scanf("%d", &q);
    while (q --) {
        int x, y, xx, yy;
        scanf("%d %d %d %d", &x, &y, &xx, &yy);
        ans = abs(x - xx) + abs(y - yy);
        vector<pair<int, int> >d = work(x, y);
        vector<pair<int, int> >e = work(xx, yy);
        for (auto u:d)
            for (auto v:e)
                ans = min(ans, u.second + v.second + 1 + f[u.first][v.first]);
        printf("%d\n", ans);
    }
    return 0;
}