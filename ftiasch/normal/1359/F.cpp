#line 1 "sol.cpp"
#include <bits/stdc++.h>

const double EPS = 1e-9;
const double INF = 1e13;

int signum(double x) { return x < 0 ? -1 : x > 0; }

struct Point {
  double norm() const { return std::sqrt(x * x + y * y); }

  Point rotate(double cos_a, double sin_a) const {
    // (x * yi) * (cos_a + sin_ai)
    return {x * cos_a - y * sin_a, x * sin_a + y * cos_a};
  }

  double x, y;
};

Point operator+(const Point &a, const Point &b) {
  return {a.x + b.x, a.y + b.y};
}

Point operator-(const Point &a, const Point &b) {
  return {a.x - b.x, a.y - b.y};
}

Point operator*(const Point &a, double k) { return {a.x * k, a.y * k}; }

double det(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }

double dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }

bool on(const Point &p, const Point &a, const Point &b) {
  return std::abs(det(p - a, p - b)) / (a - b).norm() <= EPS &&
         signum(dot(p - a, p - b)) <= 0;
}

bool cross(const Point &a, const Point &b, const Point &c, const Point &d) {
  return signum(det(b - a, c - a)) * signum(det(b - a, d - a)) < 0;
}

const int N = 25000;
const double PI = acos(-1.);

int n;
Point s0[N], v[N], a[N], b[N];

double global_x;

struct Segment {
  double y_at_global_x() const {
    return a[id].y +
           (global_x - a[id].x) / (b[id].x - a[id].x) * (b[id].y - a[id].y);
  }

  int id;
};

bool operator<(const Segment &a, const Segment &b) {
  return a.y_at_global_x() < b.y_at_global_x();
}

bool is_intersected(const Segment &u, const Segment &v) {
  //   printf("checking %d %d\n", u.id, v.id);
  const Point &p = a[u.id];
  const Point &q = b[u.id];
  const Point &r = a[v.id];
  const Point &s = b[v.id];
  return on(p, r, s) || on(q, r, s) || on(r, p, q) || on(s, p, q) ||
         cross(p, q, r, s) && cross(r, s, p, q);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y, spd;
    scanf("%d%d", &x, &y);
    s0[i] = Point{static_cast<double>(x), static_cast<double>(y)};
    scanf("%d%d%d", &x, &y, &spd);
    Point d{static_cast<double>(x), static_cast<double>(y)};
    v[i] = d * (spd / std::sqrt(x * x + y * y));
  }
  double low = 0;
  double high = INF + 1;
  // std::mt19937 gen{0};
  double random_alpha = 0.23456789;
  double cos_a = cos(random_alpha);
  double sin_a = sin(random_alpha);
  std::vector<std::pair<double, int>> events(n << 1);
  std::vector<std::set<Segment>::iterator> iterators(n);
  for (int _ = 0; _ < 100; ++_) {
    double middle = (low + high) * .5;
    // middle = 2.236067977499790 + 1e-5;
    for (int i = 0; i < n; ++i) {
      a[i] = s0[i].rotate(cos_a, sin_a);
      b[i] = (s0[i] + v[i] * middle).rotate(cos_a, sin_a);
      if (a[i].x > b[i].x) {
        std::swap(a[i], b[i]);
      }
      //   printf("(%.9f, %.9f) (%.9f, %.9f)\n", a[i].x, a[i].y, b[i].x,
      //   b[i].y);
      events[i << 1] = {a[i].x, i << 1};
      events[i << 1 | 1] = {b[i].x, i << 1 | 1};
    }
    std::sort(events.begin(), events.end());
    std::set<Segment> segments;
    bool intersection_found = false;
    for (auto [x, event] : events) {
      global_x = x;
      if (event & 1) {
        auto iterator = iterators[event >> 1];
        if (iterator != segments.begin() &&
            std::next(iterator) != segments.end() &&
            is_intersected(*std::prev(iterator), *std::next(iterator))) {
          intersection_found = true;
          break;
        }
        segments.erase(iterator);
      } else {
        Segment s{event >> 1};
        {
          auto iterator = segments.lower_bound(s);
          if (iterator != segments.end() && is_intersected(s, *iterator)) {
            intersection_found = true;
            break;
          }
          if (iterator != segments.begin() &&
              is_intersected(s, *std::prev(iterator))) {
            intersection_found = true;
            break;
          }
        }
        iterators[event >> 1] = segments.insert(s).first;
      }
    }
    if (intersection_found) {
      high = middle;
    } else {
      low = middle;
    }
    // printf("middle=%.9f found=%d\n", middle, intersection_found);
    // return 0;
  }
  if (low > INF) {
    puts("No show :(");
  } else {
    printf("%.9f\n", (low + high) * .5);
  }
}