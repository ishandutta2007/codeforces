#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, ax, ay, bx, by, cx, cy;
bool vis[maxn][maxn];

int main() {
    scanf("%d", &n);
    scanf("%d %d", &bx, &by);
    scanf("%d %d", &ax, &ay);
    scanf("%d %d", &cx, &cy);
    queue<pair<int, int>> Q;
    Q.emplace(ax, ay), vis[ax][ay] = 1;
    while (!Q.empty()) {
        auto p = Q.front(); Q.pop();
        int x = p.first, y = p.second;
        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 1 || nx > n || ny < 1 || ny > n || vis[nx][ny]) continue;
            if (nx == bx || ny == by) continue;
            if (abs(nx - bx) == abs(ny - by)) continue;
            Q.emplace(nx, ny), vis[nx][ny] = 1;
        }
    }
    puts(vis[cx][cy] ? "YES" : "NO");
    return 0;
}