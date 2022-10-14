#include <bits/stdc++.h>

int main() {
  int64_t ax, ay, bx, by, t;
  std::vector<int64_t> x(2), y(2);
  std::cin >> x[1] >> y[1] >> ax >> ay >> bx >> by >> x[0] >> y[0] >> t;
  while (true) {
    auto xx = x.back() * ax + bx;
    auto yy = y.back() * ay + by;
    if (xx - x[0] + yy - y[0] > t) {
      break;
    }
    x.push_back(xx);
    y.push_back(yy);
  }
  int n = x.size();
  auto dist = [&](int i, int j) {
    return std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]);
  };
  int result = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= i; ++j) {
      for (int k = i; k < n; ++k) {
        if (dist(0, i) + std::min(dist(i, j), dist(i, k)) + dist(j, k) <= t) {
          result = std::max(result, k - j + 1);
        }
      }
    }
  }
  std::cout << result << std::endl;
}