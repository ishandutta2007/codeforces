#include <bits/stdc++.h>

struct Point {
  Point(int x = 0, int y = 0) {
    if (x < 0) {
      x *= -1, y *= -1;
    }
    if (x == 0 && y < 0) {
      y *= -1;
    }
    this->x = x, this->y = y;
  }

  int x, y;
} points[100000];

bool operator<(const Point &a, const Point &b) {
  return 1LL * a.x * b.y > 1LL * a.y * b.x;
}

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    int x0, y0, xx, yy;
    scanf("%d%d", &x0, &y0);
    xx = x0, yy = y0;
    for (int i = 1, x, y; i < n; ++i) {
      scanf("%d%d", &x, &y);
      points[i] = Point(x - xx, y - yy);
      xx = x, yy = y;
    }
    points[0] = Point(x0 - xx, y0 - yy);
    std::sort(points, points + n);
    bool ok = ~n & 1;
    for (int i = 0; i < n && ok; i += 2) {
      ok &= points[i].x == points[i + 1].x && points[i].y == points[i + 1].y;
    }
    puts(ok ? "Yes" : "No");
  }
}