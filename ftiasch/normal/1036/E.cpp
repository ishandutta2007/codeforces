#line 1 "sol.cpp"
#include <bits/stdc++.h>

struct Point {
  long long x, y;
};

bool operator<(const Point &a, const Point &b) {
  return a.x != b.x ? a.x < b.x : a.y < b.y;
}

std::istream &operator>>(std::istream &in, Point &p) {
  return in >> p.x >> p.y;
}

long long det(const Point &a, const Point &b) {
  return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

long long dot(const Point &a, const Point &b) {
  return 1LL * a.x * b.x + 1LL * a.y * b.y;
}

Point operator*(const Point &a, long long k) { return Point{a.x * k, a.y * k}; }

Point operator-(const Point &a, const Point &b) {
  return Point{a.x - b.x, a.y - b.y};
}

int signum(long long x) { return x < 0 ? -1 : x > 0; }

bool on(const Point &p, const Point &a, const Point &b) {
  if (signum(p.x - a.x) * signum(p.x - b.x) > 0 ||
      signum(p.y - a.y) * signum(p.y - b.y) > 0) {
    return false;
  }
  return dot(p - a, p - b) <= 0;
}

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::pair<Point, Point>> s(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> s[i].first >> s[i].second;
  }
  std::map<Point, int> points;
  long long result = 0;
  for (int i = 0; i < n; ++i) {
    auto [a, b] = s[i];
    result += std::__gcd(std::abs(a.x - b.x), std::abs(a.y - b.y)) + 1;
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        auto [c, d] = s[j];
        long long cda = det(d - c, a - c);
        long long cdb = det(d - c, b - c);
        // (p - a) / (p - b) = cda / cdb
        // <=> cdb * (p - a) = cda * (p - b)
        // <=> (cdb - cda) * p = cdb * a - cda * b
        Point tmp = a * cdb - b * cda;
        long long denom = cdb - cda;
        if (denom != 0 && tmp.x % denom == 0 && tmp.y % denom == 0) {
          Point q{tmp.x / denom, tmp.y / denom};
          if (on(q, a, b)) {
            if (points[q] != i + 1) {
              result--;
            }
            points[q] = i + 1;
          }
        }
      }
    }
  }
  result += points.size();
  printf("%lld\n", result);
}