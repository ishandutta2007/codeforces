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
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;
typedef complex<int> point;

point read() {
  int x, y;
  scanf("%d %d", &x, &y);
  return point(x, y);
}

int solve(vector<point> points) {
  int result = 3;

  for (int inv = 0; inv < 2; ++inv) {
    if (points[0].real() == points[1].real() && points[1].real() == points[2].real())
      result = min(result, 1);

    for (int rot = 0; rot < 3; ++rot) {
      if (points[0].real() == points[1].real()) {
	int y0 = points[0].imag(), y1 = points[1].imag();
	if (y0 > y1) swap(y0, y1);
	int y = points[2].imag();
	if (y <= y0 || y >= y1)
	  result = min(result, 2);
      }
      rotate(points.begin(), points.begin()+1, points.end());
    }
    
    for (int i = 0; i < 3; ++i)
      points[i] = {points[i].imag(), points[i].real()};
  }
  
  return result;
}

int main() {
  vector<point> points(3);
  for (int i = 0; i < 3; ++i) points[i] = read();
  printf("%d\n", solve(points));
  return 0;
}