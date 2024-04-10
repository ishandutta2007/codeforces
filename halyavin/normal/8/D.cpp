#include <iostream>
#include <cmath>
#include <vector>

struct point {
  double x, y;

  point() : x(0), y(0) {}

  point(double x, double y) : x(x), y(y) {}
};

struct circle {
  point center;
  double r;

  circle(point center, double r) : center(center), r(r) {}
};

const double eps = 1e-10;

bool check_point(const std::vector<circle>& circles, point p) {
  for (auto& circle : circles) {
    if (std::hypot(circle.center.x - p.x, circle.center.y - p.y) >
        circle.r + eps) {
      return false;
    }
  }
  return true;
}

void add_intersect_points(const circle c1,
                          const circle c2,
                          std::vector<point>* points) {
  double d = std::hypot(c1.center.x - c2.center.x, c1.center.y - c2.center.y);
  if (c1.r < c2.r - d + eps)
    return;
  if (c2.r < c1.r - d + eps)
    return;
  if (c1.r + c2.r < d - eps)
    return;
  if (c1.r + c2.r < d + eps) {
    point p;
    p.x = (c1.center.x * c2.r + c2.center.x * c1.r) / (c1.r + c2.r);
    p.y = (c1.center.y * c2.r + c2.center.y * c1.r) / (c1.r + c2.r);
    points->push_back(p);
    return;
  }
  if (d < eps)
    return;
  double dist1 = (c1.r * c1.r - c2.r * c2.r + d * d) / (2 * d * d);
  double dist2 = std::sqrt(c1.r * c1.r / d / d - dist1 * dist1);
  point v1(c2.center.x - c1.center.x, c2.center.y - c1.center.y);
  point v2(-v1.y, v1.x);
  points->emplace_back(c1.center.x + v1.x * dist1 + v2.x * dist2,
                       c1.center.y + v1.y * dist1 + v2.y * dist2);
  points->emplace_back(c1.center.x + v1.x * dist1 - v2.x * dist2,
                       c1.center.y + v1.y * dist1 - v2.y * dist2);
}

bool intersect(const std::vector<circle>& circles) {
  std::vector<point> points;
  for (auto& c : circles) {
    points.push_back(c.center);
  }
  for (size_t i = 0; i < circles.size(); i++) {
    for (size_t j = i + 1; j < circles.size(); j++) {
      add_intersect_points(circles[i], circles[j], &points);
    }
  }
  for (auto& p : points) {
    if (check_point(circles, p))
      return true;
  }
  return false;
}

void run(std::istream& in, std::ostream& out) {
  double t1 = 0, t2 = 0;
  in >> t1 >> t2;
  point cinema;
  point shop;
  point home;
  in >> cinema.x >> cinema.y;
  in >> home.x >> home.y;
  in >> shop.x >> shop.y;
  out.precision(7);
  out << std::fixed;
  double a = std::hypot(cinema.x - shop.x, cinema.y - shop.y);
  double b = std::hypot(shop.x - home.x, shop.y - home.y);
  double c = std::hypot(cinema.x - home.x, cinema.y - home.y);
  if (a + b <= c + t2 + eps) {
    out << std::min(a + b + t1, c + t2) << std::endl;
    return;
  }
  double range_left = std::min(t1, t2);
  double range_right = std::min(a + t1, c + t2);
  std::cerr.precision(5);
  while (range_right - range_left > eps) {
    double middle = (range_left + range_right) / 2;
    std::vector<circle> circles;
    circles.emplace_back(cinema, middle);
    circles.emplace_back(shop, a + t1 - middle);
    circles.emplace_back(home, c + t2 - middle);
    if (intersect(circles)) {
      range_left = middle;
    } else {
      range_right = middle;
    }
  }
  out << range_left << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  run(std::cin, std::cout);
  return 0;
}