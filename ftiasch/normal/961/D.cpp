#line 1 "sol.cpp"
#include <bits/stdc++.h>

struct Point {
  int x, y;
};

Point operator-(const Point &a, const Point &b) {
  return Point{a.x - b.x, a.y - b.y};
}

long long det(const Point &a, const Point &b) {
  return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

bool colinear(const Point &a, const Point &b, const Point &c) {
  return det(b - a, c - a) == 0;
}

const int N = 100'000;

int n;
Point p[N];

bool check(const Point &a, const Point &b) {
  std::vector<Point> q;
  for (int i = 0; i < n; ++i) {
    if (!colinear(a, b, p[i])) {
      q.push_back(p[i]);
    }
  }
  if (q.size() <= 2) {
    return true;
  }
  for (int i = 2; i < q.size(); ++ i) {
      if (!colinear(q[0], q[1], q[i])) {
          return false;
      }
  }
  return true;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &p[i].x, &p[i].y);
  }
  bool ok = n <= 3;
  for (int i = 0; i < 3 && !ok; ++i) {
    ok |= check(p[i], p[(i + 1) % 3]);
  }
  puts(ok ? "YES" : "NO");
}