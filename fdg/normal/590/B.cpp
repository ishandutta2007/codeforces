#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  long double x1, y1, x2, y2, v, t, vx, vy, wx, wy;
  cin >> x1 >> y1 >> x2 >> y2 >> v >> t >> vx >> vy >> wx >> wy;

  long double dx = x2 - x1, dy = y2 - y1;

  long double l = 0, r = 1e+11;
  for (int it = 0; it < 100; ++it) {
    long double m = (l + r) / 2;

    long double t1 = min(t, m), t2 = max((long double)0.0, m - t);

    long double sx = (dx - vx * t1 - wx * t2) / (t1 + t2);
    long double sy = (dy - vy * t1 - wy * t2) / (t1 + t2);
  
    if (sx * sx + sy * sy < v * v) r = m;
    else l = m;
  }
  printf("%.10lf\n", (double) (l + r) / 2);

  return 0;
}