#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;
typedef complex<double> point;

const double pi = acos(-1.0);

double cross(const point &a, const point &b) { return a.real() * b.imag() - a.imag() * b.real(); }

int main() {
  vector<int> sides(6);
  for (int &side : sides) scanf("%d", &side);

  point at(0.0, 0.0), dir(1.0, 0);
  vector<point> points(6);

  for (int i = 0; i < 6; ++i) {
    points[i] = at;
    if (i+1 < 6) {
      at += dir * (double)sides[i];
      dir *= polar(1.0, pi/3);
    }
  }
  double area = 0;
  for (int i = 0; i < 6; ++i)
    area += cross(points[i], points[(i+1)%6]);
  area = abs(area/2);

  double t3area = sqrt(0.75) / 2;

  lint many = round(area / t3area);
  printf("%lld\n", many);

  return 0;
}