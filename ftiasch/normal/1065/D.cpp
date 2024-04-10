#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 10;
const int INF = 1e9;

const int DELTA_X[8] = {-1, -1, -2, -2, 2, 2, 1, 1};
const int DELTA_Y[8] = {-2, 2, -1, 1, -1, 1, -2, 2};

template <typename T>
using PQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;

int n, a[N][N];
std::pair<int, int> dist[N * N + 1][N][N][3];

int main() {
  scanf("%d", &n);
  int x0, y0, x1, y1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", a[i] + j);
      a[i][j]--;
      if (a[i][j] == 0) {
        x0 = i, y0 = j;
      }
      if (a[i][j] == n * n - 1) {
        x1 = i, y1 = j;
      }
    }
  }
  for (int i = 1; i <= n * n; ++i) {
    for (int x = 0; x < n; ++x) {
      for (int y = 0; y < n; ++y) {
        for (int t = 0; t < 3; ++t) {
          dist[i][x][y][t] = {INF, INF};
        }
      }
    }
  }
  using State = std::tuple<int, int, int, int>;
  PQ<std::pair<std::pair<int, int>, State>> pq;
  auto add = [&](int i, int x, int y, int t, std::pair<int, int> d) -> void {
    if (dist[i][x][y][t] > d) {
      dist[i][x][y][t] = d;
      pq.emplace(d, State{i, x, y, t});
    }
  };
  for (int t = 0; t < 3; ++t) {
    add(1, x0, y0, t, {0, 0});
  }
  while (!pq.empty()) {
    auto [dist_s, state] = pq.top();
    pq.pop();
    const auto [i, x, y, t] = state;
    if (dist_s == dist[i][x][y][t]) {
      dist_s.first++;
      for (int tt = 0; tt < 3; ++tt) {
        if (tt != t) {
          add(i, x, y, tt, {dist_s.first, dist_s.second + 1});
        }
      }
      if (t == 0) {
        for (int k = 0; k < 8; ++k) {
          int xx = x + DELTA_X[k];
          int yy = y + DELTA_Y[k];
          if (0 <= xx && xx < n && 0 <= yy && yy < n) {
            add(i + (a[xx][yy] == i), xx, yy, 0, dist_s);
          }
        }
      }
      if (t == 1) {
        for (int xx = 0; xx < n; ++xx) {
          {
            int yy = x + y - xx;
            if (0 <= yy && yy < n) {
              add(i + (a[xx][yy] == i), xx, yy, 1, dist_s);
            }
          }
          {
            int yy = y - x + xx;
            if (0 <= yy && yy < n) {
              add(i + (a[xx][yy] == i), xx, yy, 1, dist_s);
            }
          }
        }
      }
      if (t == 2) {
        for (int xx = 0; xx < n; ++xx) {
          int yy = y;
          add(i + (a[xx][yy] == i), xx, yy, 2, dist_s);
        }
        for (int yy = 0; yy < n; ++yy) {
          int xx = x;
          add(i + (a[xx][yy] == i), xx, yy, 2, dist_s);
        }
      }
    }
  }
  auto result = *std::min_element(dist[n * n][x1][y1], dist[n * n][x1][y1] + 3);
  printf("%d %d\n", result.first, result.second);
}