#include <algorithm>
#include <cstdio>
#include <queue>
#define make(i, j, k, kk) make_pair(make_pair(i, j), make_pair(k, kk))
using namespace std;
const int N = 11;
queue<pair<pair<int, int>, pair<int,int> > > q;
int n;
int a[N][N];
pair<int, int> dis[N*N][N][N][3];
bool check(int x, int y) {
    return x >= 1 && y >= 1&& x <= n && y <= n;
}
void update(int step, int x, int y,int type, pair<int, int> v) {
    step += (a[x][y] == step + 1);
    if (!dis[step][x][y][type].first)
        q.push(make(x, y, type, step)),dis[step][x][y][type] = v;
    else
    if (dis[step][x][y][type].second > v.second && dis[step][x][y][type].first == v.first)
        dis[step][x][y][type] = v;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1) {
                dis[1][i][j][0] = {1, 0};
                dis[1][i][j][1] = {1, 0};
                dis[1][i][j][2] = {1, 0};
                q.push(make(i, j, 0, 1));
                q.push(make(i, j, 1, 1));
                q.push(make(i, j, 2, 1));
            }
        }
    pair<int, int> ans = {0, 0};
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        pair<int, int>v = dis[u.second.second][u.first.first][u.first.second][u.second.first];
        if (u.second.second == n * n) {
            if (!ans.first || (ans.first == v.first && ans.second > v.second))
                ans = v;
            continue;
        }
        if (u.second.first == 0) {
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    for (int ii = 1; ii <= 2; ii ++) {
                        int xx = u.first.first + (i * 2 - 1) * ii, yy = u.first.second + (j * 2 - 1) * (3 - ii);
                        if (check(xx, yy)) {
                            update(u.second.second, xx, yy, u.second.first, make_pair(v.first + 1, v.second));
                        }
                    }
        } else
        if (u.second.first == 1) {
            for (int i = 0; i < 2; i ++)
                for (int j = 0; j < 2 ;j ++)
                    for (int len = 1; len <= n; len ++) {
                        int xx = u.first.first + (i * 2 - 1) * len, yy = u.first.second + (j * 2 - 1) * len;
                        if (check(xx, yy)) {
                            update(u.second.second, xx, yy, u.second.first, make_pair(v.first + 1, v.second));
                        }
                    }
        } else
            if (u.second.first == 2) {
                for (int i = 0; i < 2; i ++)
                    for (int j = 0; j < 2 ;j ++)
                        for (int len = 1; len <= n; len ++) {
                            int xx = u.first.first + (i * 2 - 1) * j * len, yy = u.first.second + (i * 2 - 1) * (1 - j) * len;
                            if (check(xx, yy)) {
                                update(u.second.second, xx, yy, u.second.first, make_pair(v.first + 1, v.second));
                            }
                        }
            }

        update(u.second.second, u.first.first, u.first.second, 0, make_pair(v.first + 1, v.second + 1));
        update(u.second.second, u.first.first, u.first.second, 1, make_pair(v.first + 1, v.second + 1));
        update(u.second.second, u.first.first, u.first.second, 2, make_pair(v.first + 1, v.second + 1));
    }
    printf("%d %d\n", ans.first - 1, ans.second);
    return 0;
}