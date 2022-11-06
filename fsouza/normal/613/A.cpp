#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <complex>
#include <map>
#include <numeric>
#include <set>
#include <vector>
#include <cmath>

#define INF 1000000000

using namespace std;

typedef long long lint;
typedef complex<double> point;

point readit() {
  int x, y;
  scanf("%d %d", &x, &y);
  return point(x, y);
}

double dist(point a, point b) {return abs(a-b);}

double dot(point a, point b) {return real(a) * real(b) + imag(a) * imag(b);}

point proj(point u, point v) {
  return v * dot(u, v) / dot(v, v);
}

int main() {
  int n;
  scanf("%d", &n);
  point p = readit();
  vector<point> poly(n);
  for (int i = 0; i < n; ++i)
    poly[i] = readit();

  double mindist = 1e20, maxdist = -1e20;

  for (int i = 0; i < n; ++i) {
    point a = poly[i], b = poly[(i+1)%n];
    maxdist = max(maxdist, dist(a, p));

    mindist = min(mindist, dist(a, p));

    point m = a + proj(p-a, b-a);
    if (fabs(dist(a, b) - (dist(a, m) + dist(m, b))) < 1e-9)
      mindist = min(mindist, dist(p, m));
  }

  const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;
  double result = pi * (maxdist * maxdist - mindist * mindist);
  printf("%.8f\n", result);
  
  return 0;
}