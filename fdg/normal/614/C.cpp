#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <cmath>

using namespace std;

int x[100005], y[100005];

double dist(int i, int j) {
  return sqrt(1.0 * (x[i] - x[j]) * (x[i] - x[j]) + 1.0 * (y[i] - y[j]) * (y[i] - y[j]));
}

double dist(int i1, int i2, int i3) {
  double s = 1.0 * (x[i1] - x[i3]) * (y[i2] - y[i3]) - 1.0 * (y[i1] - y[i3]) * (x[i2] - x[i3]);
  s = fabs(s) / 2.0;
  double a = dist(i1, i2), b = dist(i3, i1), c = dist(i3, i2);
  double h = 2 * s / a;

  if (c * c > a * a + b * b || b * b > a * a + c * c) return min(b, c);
  return h;
}

int main() {
  int n, px, py;
  scanf("%d%d%d", &n, &px, &py);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
  }
  x[n] = x[0]; y[n] = y[0];
  x[n + 1] = px; y[n + 1] = py;

  double mn = 1e+9, mx = -1e+9;

  for (int i = 0; i < n; ++i) {
    mn = min(mn, dist(i, n + 1));
    mx = max(mx, dist(i, n + 1));
    mn = min(mn, dist(i, i + 1, n + 1));
  }

  printf("%.10lf\n", acos(-1.0) * (mx * mx - mn * mn));

  return 0;
}