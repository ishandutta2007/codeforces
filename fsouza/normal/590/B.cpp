#include <algorithm>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
typedef complex<double> point;

point read() {
  int x, y;
  scanf("%d %d", &x, &y);
  return point(x, y);
}

int main() {
  point start = read();
  point end = read();
  double maxv, part1;
  scanf("%lf %lf", &maxv, &part1);
  point wind1 = read(), wind2 = read();

  double l = 0.0, r = 1e15;
  for (int rep = 0; rep < 10000; ++rep) {
    double after = (l+r)/2;
    
    double apply1 = min(after, double(part1));
    double apply2 = max(0.0, after - part1);
    point newend = end - apply1 * wind1 - apply2 * wind2;
    double dist = abs(newend - start);
    if (dist / maxv < after) r = after;
    else l = after;
  }

  printf("%.10f\n", l);
  
  return 0;
}