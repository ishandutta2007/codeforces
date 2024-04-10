#include <bits/stdc++.h>

static const int DELTA_X[] = {-1, 0, 0, 1};
static const int DELTA_Y[] = {0, -1, 1, 0};

const int N = 1000;
const int M = 40;

struct Point {
  int x, y;
};

int n, m, c, a[N][N], dist[M][N][N], visited[M];
Point queue[N * N];
std::vector<Point> entries[M];

int main() {
  while (scanf("%d%d%d", &n, &m, &c) == 3) {
    for (int i = 0; i < c; ++i) {
      entries[i].clear();
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", a[i] + j);
        entries[--a[i][j]].push_back(Point{i, j});
      }
    }
    memset(dist, -1, sizeof(dist));
    for (int s = 0; s < c; ++s) {
      int rear = 0;
      for (auto &&p : entries[s]) {
        dist[s][p.x][p.y] = 0;
        queue[rear++] = p;
      }
      memset(visited, 0, sizeof(visited));
      visited[s] = true;
      for (int head = 0; head < rear; ++head) {
        int x = queue[head].x, y = queue[head].y, c = a[x][y];
        if (!visited[c]) {
          visited[c] = true;
          for (auto &&p : entries[c]) {
            if (!~dist[s][p.x][p.y]) {
              dist[s][p.x][p.y] = dist[s][x][y] + 1;
              queue[rear++] = p;
            }
          }
        }
        for (int k = 0; k < 4; ++k) {
          int xx = x + DELTA_X[k], yy = y + DELTA_Y[k];
          if (0 <= xx && xx < n && 0 <= yy && yy < m && !~dist[s][xx][yy]) {
            dist[s][xx][yy] = dist[s][x][y] + 1;
            queue[rear++] = Point{xx, yy};
          }
        }
      }
    }
    int q, x0, y0, x1, y1;
    scanf("%d", &q);
    while (q--) {
      scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
      x0--, y0--, x1--, y1--;
      int result = std::abs(x0 - x1) + std::abs(y0 - y1);
      for (int k = 0; k < c; ++k) {
        result = std::min(result, dist[k][x0][y0] + 1 + dist[k][x1][y1]);
      }
      printf("%d\n", result);
    }
  }
}