#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <complex>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;
typedef complex<lint> point;
typedef complex<double> point2;

lint cross(const point &a, const point &b) { return real(a) * imag(b) - imag(a) * real(b); }
lint cross(const point &a, const point &b, const point &c) { return cross(b-a, c-a); }

double cross(const point2 &a, const point2 &b) { return real(a) * imag(b) - imag(a) * real(b); }
double cross(const point2 &a, const point2 &b, const point2 &c) { return cross(b-a, c-a); }

int main() {
  int n, p, q;
  scanf("%d %d %d", &n, &p, &q);
  point pq(p, q);

  vector<point> points(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    points[i] = point(a, b);
  }

  sort(points.begin(), points.end(), [](const point &a, const point &b) {
      lint c = cross(a, b);
      if (c != 0) return c > 0;
      return norm(a) > norm(b);
    });
  points.resize(unique(points.begin(), points.end(), [](const point &a, const point &b) {
	return cross(a, b) == 0;
      }) - points.begin());

  {
    vector<point> hull;
    for (int i = 0; i < (int)points.size(); ++i) {
      while (hull.size() >= 2 && cross(hull.end()[-2], points[i], hull.end()[-1]) >= 0)
	hull.pop_back();
      hull.push_back(points[i]);
    }
    points = move(hull);
    n = points.size();
  }

  double result = 1e10;

  for (int i = 0; i < n; ++i)
    result = min(result, max(1.0 * p / points[i].real(), 1.0 * q / points[i].imag()));
  
  int j = 0;
  while (j < (int)points.size() && cross(points[j], pq) >= 0) ++j;

  if (0 <= j-1 && j < (int)points.size()) {
    double l = 0, r = result;
    for (int rep = 0; rep < 100000; ++rep) {
      double m = (l+r)/2;
      point2 a = point2(points[j].real()*m, points[j].imag()*m);
      point2 b = point2(points[j-1].real()*m, points[j-1].imag()*m);
      if (cross(b, a, point2(p, q)) >= 0) r = m;
      else l = m;
    }
    result = l;
  }
  
  printf("%.9f\n", result);
  
  return 0;
}