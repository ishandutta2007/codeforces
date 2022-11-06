#include <algorithm>
#include <array>
#include <bitset>
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
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  struct point_t {
    int x, y;
  };
  vector<point_t> points(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &points[i].x, &points[i].y);
  }
  auto x_cmp = [](const point_t &lhs, const point_t &rhs) {
    return lhs.x < rhs.x;
  };
  auto y_cmp = [](const point_t &lhs, const point_t &rhs) {
    return lhs.y < rhs.y;
  };
  point_t x_most[2] = {
    *min_element(points.begin(), points.end(), x_cmp),
    *max_element(points.begin(), points.end(), x_cmp),
  };
  point_t y_most[2] = {
    *min_element(points.begin(), points.end(), y_cmp),
    *max_element(points.begin(), points.end(), y_cmp),
  };

  int result4 =
      2 * (x_most[1].x - x_most[0].x) + 2 * (y_most[1].y - y_most[0].y);

  int result3 = 0;
  for (int mx : {-1, 1})
    for (int my : {-1, 1}) {
      int min_comb = INT_MAX, max_comb = INT_MIN;
      for (const point_t &p : points) {
        int comb = mx * p.x + my * p.y;
        min_comb = min(min_comb, comb);
        max_comb = max(max_comb, comb);
      }
      result3 = max(result3, 2 * (max_comb - min_comb));
    }

  for (const point_t &p1 : points)
    for (const point_t &p2 : {x_most[0], x_most[1]})
      for (const point_t &p3 : {y_most[0], y_most[1]}) {
        int min_x = min({p1.x, p2.x, p3.x});
        int max_x = max({p1.x, p2.x, p3.x});
        int min_y = min({p1.y, p2.y, p3.y});
        int max_y = max({p1.y, p2.y, p3.y});
        result3 = max(result3, 2 * (max_x - min_x) + 2 * (max_y - min_y));
      }

  for (int k = 3; k <= n; ++k) {
    int result = (k == 3 ? result3 : result4);
    if (k > 3) printf(" ");
    printf("%d", result);
  }
  printf("\n");

  return 0;
}