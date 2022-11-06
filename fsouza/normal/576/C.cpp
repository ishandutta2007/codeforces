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

int main() {
  int n;
  scanf("%d", &n);
  struct point_t { int x, y, id; };
  vector<point_t> points(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    points[i] = {x, y, i};
  }
  const int div = 1000;
  sort(points.begin(), points.end(), [](const point_t &p1, const point_t &p2) {
      if (p1.x / div != p2.x / div) return p1.x < p2.x;
      return p1.y < p2.y;
    });
  bool prev = false;
  for (int j = 0, i = j; i != (int)points.size(); i = j) {
    while (j != (int)points.size() && points[j].x / div == points[i].x / div) ++j;
    if (prev) reverse(points.begin() + i, points.begin() + j);
    prev = !prev;
  }

  for (int i = 0; i < (int)points.size(); ++i) {
    if (i > 0) printf(" ");
    printf("%d", points[i].id+1);
  }
  printf("\n");

  return 0;
}