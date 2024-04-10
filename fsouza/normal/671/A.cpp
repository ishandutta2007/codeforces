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
typedef complex<double> point;
const double E = 1e-9;

point read() {
  int x, y;
  scanf("%d %d", &x, &y);
  return point(x, y);
}

double solve1(point a, point bin, vector<point> &points) {
  const int n = points.size();
  double result = 1e50;
  double totalcost = 0;
  for (int i = 0; i < n; ++i) totalcost += 2. * abs(bin - points[i]);
  for (int i = 0; i < n; ++i) {
    double res = abs(a - points[i]) + abs(points[i] - bin) +
      totalcost - 2.0 * abs(bin - points[i]);
    result = min(result, res);
  }
  return result;
}

int main() {
  point a = read(), b = read(), bin = read();
  int n;
  scanf("%d", &n);
  vector<point> points(n);
  for (point &p : points) p = read();

  double result = min(solve1(a, bin, points), solve1(b, bin, points));
  if (n >= 2) {
    double totalcost = 0;
    for (int i = 0; i < n; ++i) totalcost += 2. * abs(bin - points[i]);

    vector<int> ida(n), idb(n);
    iota(ida.begin(), ida.end(), 0);
    iota(idb.begin(), idb.end(), 0);
    nth_element(ida.begin(), ida.begin()+1, ida.end(), [&](const int x, const int y) {
	function<double(int)> calc = [&](int x) {
	  double diffx = abs(a - points[x]) + abs(points[x] - bin) - 2.0 * abs(bin - points[x]);
	  return diffx;
	};
	return calc(x) < calc(y);
      });
    nth_element(idb.begin(), idb.begin()+1, idb.end(), [&](const int x, const int y) {
	function<double(int)> calc = [&](int x) {
	  double diffx = abs(b - points[x]) + abs(points[x] - bin) - 2.0 * abs(bin - points[x]);
	  return diffx;
	};
	return calc(x) < calc(y);
      });

    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j) {
	int awith = ida[i], bwith = idb[j];
	if (awith == bwith) continue;
	double res = abs(a - points[awith]) + abs(points[awith] - bin) +
	  abs(b - points[bwith]) + abs(points[bwith] - bin) +
	  totalcost - 2.0 * abs(bin - points[awith]) - 2.0 * abs(bin - points[bwith]);
	result = min(result, res);
      }
  }

  printf("%.12f\n", result);

  return 0;
}