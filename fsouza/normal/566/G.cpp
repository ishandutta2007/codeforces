#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;
typedef complex<lint> point;

lint cross(const point &a, const point &b) { return a.real() * b.imag() - a.imag() * b.real(); }
lint cross(const point &a, const point &b, const point &c) { return cross(b-a, c-a); }

vector<point> calc_hull(vector<point> points) {
  lint maxx = 0, maxy = 0;
  for (point &p : points)
    maxx = max(maxx, p.real()), maxy = max(maxy, p.imag());
  points.push_back({maxx, 0});
  points.push_back({0, maxy});
  sort(points.begin(), points.end(), [](const point &a, const point &b) {
      if (a.real() != b.real()) return a.real() < b.real();
      return a.imag() > b.imag();
    });

  vector<point> hull;
  for (point &p : points) {
    while (hull.size() >= 2 && cross(hull.end()[-2], hull.end()[-1], p) >= 0)
      hull.pop_back();
    hull.push_back(p);
  }
  return move(hull);
}

vector<point> read_points(int n) {
  vector<point> points(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    points[i] = {x, y};
  }
  return points;
}

int main() {
  int nblue, nred;
  scanf("%d %d", &nblue, &nred);
  scanf("%*d %*d");
  vector<point> blues = read_points(nblue);
  vector<point> reds = read_points(nred);

  vector<point> hull = calc_hull(reds);
  reverse(hull.begin(), hull.end());

  sort(blues.begin(), blues.end(), [](const point &a, const point &b) {
      return cross(a, b) > 0;
    });
  
  bool enclose = true;
  int i = 0;
  for (point &p : blues) {
    while (cross(hull[i], p) > 0) ++i;
    int from = i-1, to = i;
    if (cross(hull[from], hull[to], p) <= 0)
      enclose = false;
  }

  printf(enclose ? "Min\n" : "Max\n");
  
  return 0;
}