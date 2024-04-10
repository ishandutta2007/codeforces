#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int DELTA_X[]{-1, 0, 0, 1};
const int DELTA_Y[]{0, -1, 1, 0};

int main() {
  int n;
  scanf("%d", &n);
  std::map<std::pair<int, int>, std::tuple<int, int, int>> result;
  std::vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    result[{x[i], y[i]}] = {-1, -1, -1};
  }
  std::queue<std::pair<int, int>> queue;
  for (auto [p, _] : result) {
    auto [x, y] = p;
    for (int k = 0; k < 4; ++k) {
      int xx = x + DELTA_X[k];
      int yy = y + DELTA_Y[k];
      if (!result.count({xx, yy})) {
        queue.emplace(x, y);
        result[{x, y}] = {1, xx, yy};
      }
    }
  }
  while (!queue.empty()) {
    auto [x, y] = queue.front();
    queue.pop();
    auto [d, sx, sy] = result[{x, y}];
    for (int k = 0; k < 4; ++k) {
      int xx = x + DELTA_X[k];
      int yy = y + DELTA_Y[k];
      auto iterator = result.find({xx, yy});
      if (iterator != result.end() && !~std::get<0>(iterator->second)) {
        iterator->second = {d + 1, sx, sy};
        queue.emplace(xx, yy);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    auto [_, sx, sy] = result[{x[i], y[i]}];
    printf("%d %d\n", sx, sy);
  }
}