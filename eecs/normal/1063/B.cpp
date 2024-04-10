#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n, m, r, c, X, Y, ans, mn[maxn][maxn], vis[maxn][maxn];
char s[maxn][maxn];

int main() {
    scanf("%d %d %d %d", &n, &m, &r, &c);
    scanf("%d %d", &X, &Y);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    memset(mn, 0x3f, sizeof(mn));
    deque<pair<int, int>> Q;
    Q.emplace_back(r, c), mn[r][c] = 0;
    while (!Q.empty()) {
        int x = Q.front().first, y = Q.front().second; Q.pop_front();
        if (vis[x][y]) continue;
        vis[x][y] = 1;
        for (int dx : {-1, 0, 1}) for (int dy : {-1, 0, 1}) {
            if (abs(dx) + abs(dy) != 1) continue;
            int _x = x + dx, _y = y + dy;
            if (_x < 1 || _x > n || _y < 1 || _y > m) continue;
            if (s[_x][_y] == '*' || mn[_x][_y] <= mn[x][y]) continue;
            int cost = dy == -1;
            mn[_x][_y] = mn[x][y] + cost;
            if (!cost) Q.emplace_front(_x, _y);
            else Q.emplace_back(_x, _y);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mn[i][j] <= X && j - (c - mn[i][j]) <= Y) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}