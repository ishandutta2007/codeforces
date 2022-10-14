#line 1 "sol.cpp"
#include <bits/stdc++.h>

int read_decimal() {
  double f;
  scanf("%lf", &f);
  return std::round(f * 100);
}

int signum(long long x) { return x < 0 ? -1 : x > 0; }

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  std::vector<std::pair<int, int>> polygon(n + 1);
  for (int i = 0; i < n; ++i) {
    int x = read_decimal();
    int y = read_decimal();
    polygon[i] = {x, y};
  }
  polygon[n] = polygon[0];
  std::vector<std::pair<double, int>> events;
  while (q--) {
    int x0 = read_decimal();
    int y0 = read_decimal();
    int x1 = read_decimal();
    int y1 = read_decimal();
    int dx = x1 - x0;
    int dy = y1 - y0;
    events.clear();
    for (int i = 0; i < n; ++i) {
      auto [x1, y1] = polygon[i];
      x1 -= x0;
      y1 -= y0;
      auto [x2, y2] = polygon[i + 1];
      x2 -= x0;
      y2 -= y0;
      long long det1 = 1LL * x1 * dy - 1LL * y1 * dx;
      long long det2 = 1LL * x2 * dy - 1LL * y2 * dx;
      if (signum(det2) != signum(det1)) {
        events.emplace_back(1.0 * (1LL * x1 * y2 - 1LL * y1 * x2) /
                                (1LL * (y2 - y1) * dx - 1LL * (x2 - x1) * dy),
                            signum(det2) - signum(det1));
      }
    }
    std::sort(events.begin(), events.end());
    int sum = 0;
    double result = 0.;
    for (int i = 0; i < events.size(); ++i) {
      if (sum) {
        result += events[i].first - events[i - 1].first;
      }
      sum += events[i].second;
    }
    printf("%.9f\n", result * sqrt(1LL * dx * dx + 1LL * dy * dy) / 100);
  }
}