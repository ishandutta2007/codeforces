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
typedef long double ldouble;

struct state_t {
  bool is_rect;
  lint x0, x1, x2;
  lint y0, y1, y2;
  state_t(lint _x0, lint _x1, lint _y0, lint _y1)
      : is_rect(true), x0(_x0), x1(_x1), y0(_y0), y1(_y1) {}
  state_t(lint _x0, lint _x1, lint _x2, lint _y0, lint _y1, lint _y2)
      : is_rect(false), x0(_x0), x1(_x1), x2(_x2), y0(_y0), y1(_y1), y2(_y2) {}
};

enum res_t { HIGHER_X = 1, HIGHER_Y = 2, LOWER_ANY = 3 };

int main() {
  lint n;
  scanf("%lld", &n);

  state_t s(1, n + 1, 1, n + 1);
  bool mirrored = false;

  auto mirror = [&]() {
    swap(s.x0, s.y0);
    swap(s.x1, s.y1);
    swap(s.x2, s.y2);
    mirrored = !mirrored;
  };

  auto query = [&](lint qx, lint qy) {
    if (mirrored) swap(qx, qy);
    printf("%lld %lld\n", qx, qy);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    if (ans == 0) exit(0);
    if (mirrored) {
      if (ans == 1) ans = 2;
      else if (ans == 2) ans = 1;
    }
    return (res_t)ans;
  };

  while (true) {
    if (s.is_rect) {
      lint qx = s.x0 + (s.x1 - s.x0) / 2;
      lint qy = s.y0 + (s.y1 - s.y0) / 2;
      res_t res = query(qx, qy);
      if (res == HIGHER_X) s.x0 = qx + 1;
      else if (res == HIGHER_Y) s.y0 = qy + 1;
      else s = {s.x0, qx, s.x1,
                s.y0, qy, s.y1};
    } else {
      ldouble area1 = (ldouble)(s.x1 - s.x0) * (s.y2 - s.y0);
      ldouble area2 = (ldouble)(s.x2 - s.x0) * (s.y1 - s.y0);
      if (area1 < area2) {
        swap(area1, area2);
        mirror();
      }
      ldouble total_area =
          area1 + area2 - (ldouble)(s.x1 - s.x0) * (s.y1 - s.y0);
      lint height = floor(min(total_area / ((ldouble)4 * (s.x2 - s.x0)),
                              (ldouble)(s.y1 - s.y0)));
      lint qx = s.x0 + (s.x1 - s.x0) / 2;
      lint qy = s.y0 + height;
      res_t res = query(qx, qy);
      if (res == HIGHER_X) {
        s.x0 = qx + 1;
        if (s.x0 >= s.x1) s = {s.x0, s.x2, s.y0, s.y1};
      } else if (res == HIGHER_Y) {
        s.y0 = qy + 1;
        if (s.y0 >= s.y1) s = {s.x0, s.x1, s.y0, s.y2};
      } else {
        s.x1 = qx;
        s.y1 = qy;
        if (s.x0 >= s.x1) s = {s.x0, s.x2, s.y0, s.y1};
        else if (s.y0 >= s.y1) s = {s.x0, s.x1, s.y0, s.y2};
      }
    }
  }

  return 0;
}