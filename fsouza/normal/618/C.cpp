#include <algorithm>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;
typedef complex<int> point;

lint dist2(point a, point b) {
  point d = a-b;
  return (lint)d.real() * d.real() + (lint)d.imag() * d.imag();
}

lint cross(point a, point b) { return (lint)real(a) * imag(b) - (lint)imag(a) * real(b); }
lint cross(point a, point b, point c) { return cross(b-a, c-a); }

int main() {
  int n;
  scanf("%d", &n);
  vector<point> points(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    points[i] = point(x, y);
  }

  int a = 0, b = 1;
  for (int i = 2; i < n; ++i)
    b = min(b, i, [start = points[a], &points](int a, int b) { return dist2(start, points[a]) < dist2(start, points[b]); });
  int c = -1;

  for (int i = 0; i < n; ++i)
    if (cross(points[a], points[b], points[i])) {
      if (c == -1) c = i;
      else c = min(c, i, [A = points[a], B = points[b], &points](int x, int y) {
	  point px = points[x], py = points[y];
	  return abs(cross(A, B, px)) < abs(cross(A, B, py));
	});
    }

  printf("%d %d %d\n", a+1, b+1, c+1);
  
  return 0;
}