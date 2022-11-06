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
typedef complex<ldouble> point_t;

const ldouble E = 1e-9 / 3;

struct point2_t {
  point_t p;
  short id0, id1;
};

struct line_t {
  ldouble slope, inter;
  int id;
  ldouble eval(ldouble x) const {
    return inter + slope * x;
  }
};

void print_answer(const point_t &a, const point_t &b, const point_t &c) {
  printf("Yes\n");
  for (const point_t &p : {a, b, c})
    printf("%.0Lf %.0Lf\n", p.real(), p.imag());
  exit(0);
}

bool intersect(const line_t &a, const line_t &b, ldouble &x) {
  if (abs(a.slope - b.slope) <= E) return false;
  x = (b.inter - a.inter) / (a.slope - b.slope);
  return true;
}

void solve(vector<point2_t> &points, vector<line_t> &lines,
           const vector<point_t> &orig_points) {
  struct cross_t {
    ldouble x;
    short id0, id1;
  };
  const int nl = lines.size();
  vector<cross_t> crosses;
  crosses.reserve(nl * (nl - 1) / 2);
  for (int i = 0; i < nl; ++i)
    for (int j = i + 1; j < nl; ++j) {
      ldouble x;
      if (intersect(lines[i], lines[j], x)) {
        crosses.push_back({x, (short)i, (short)j});
      }
    }
  sort(crosses.begin(), crosses.end(),
       [](const cross_t &lhs, const cross_t &rhs) { return lhs.x < rhs.x; });

  sort(points.begin(), points.end(),
       [](const point2_t &lhs, const point2_t &rhs) {
         return lhs.p.real() < rhs.p.real();
       });

  ldouble cur_x, query_y;
  auto line_cmp = [&](int id_a, int id_b) {
    ldouble ya = (id_a >= 0 ? lines[id_a].eval(cur_x) : query_y);
    ldouble yb = (id_b >= 0 ? lines[id_b].eval(cur_x) : query_y);
    if (abs(ya - yb) > E)
      return ya < yb;
    return id_a < id_b;
  };
  set<int, decltype(line_cmp)> sorted(line_cmp);

  cur_x = 0.0;
  if (!crosses.empty()) cur_x = min(cur_x, crosses[0].x - 1.0);
  if (!points.empty()) cur_x = min(cur_x, points[0].p.real() - 1.0);

  for (int i = 0; i < nl; ++i) sorted.insert(i);

  auto cur_cross = crosses.begin();
  for (const point2_t &p2 : points) {
    const point_t &p = p2.p;

    auto until = cur_cross;
    while (until != crosses.end() && until->x <= p.real() + E) ++until;
    if (until != cur_cross) {
      for (auto it = cur_cross; it != until; ++it) {
        sorted.erase(it->id0);
        sorted.erase(it->id1);
      }
      cur_x =
        until == crosses.end()
        ? crosses.back().x + 1.0
        : (cur_cross->x + until->x) / 2.0;
      for (auto it = cur_cross; it != until; ++it) {
        sorted.insert(it->id0);
        sorted.insert(it->id1);
      }
      cur_cross = until;
    }

    ldouble back_cur_x = cur_x;
    cur_x = p.real();
    query_y = p.imag();
    auto it = sorted.lower_bound(-1);
    if (it != sorted.end()) {
      const line_t &cand = lines[*it];
      if (abs(query_y - cand.eval(cur_x)) <= E) {
        print_answer(orig_points[p2.id0], orig_points[p2.id1],
                     orig_points[cand.id]);
      }
    }
    cur_x = back_cur_x;
  }

  printf("No\n");
}

int main() {
  int n;
  lint want_area;
  scanf("%d %lld", &n, &want_area);

  vector<point_t> points(n);
  map<lint, point_t> point_for_x;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    points[i] = point_t(x, y);
    point_for_x[x] = points[i];
  }
  sort(points.begin(), points.end(),
       [](const point_t &lhs, const point_t &rhs) {
         return lhs.real() < rhs.real();
       });

  vector<point2_t> points2;
  points2.reserve(n * (n - 1) / 2);
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
      const point_t &a = points[i], &b = points[j];
      for (int dir : {-1, +1}) {
        const ldouble dist = (ldouble)2 * want_area / abs(a - b);
        point_t c = a + (b - a) / abs(b - a) * point_t(0, dir) * dist;
        if (abs(a.real() - b.real()) <= E) {
          lint c_x = round(c.real());
          if (abs(c_x - c.real()) <= E) {
            auto it = point_for_x.find(c_x);
            if (it != point_for_x.end()) {
              print_answer(a, b, it->second);
            }
          }
        } else {
          if (dir == 1) {
            ldouble slope = (b.imag() - a.imag()) / (b.real() - a.real());
            ldouble inter = c.imag() - c.real() * slope;
            points2.push_back({{slope, -inter}, (short)i, (short)j});
          }
        }
      }
    }

  vector<line_t> lines(n);
  for (int i = 0; i < n; ++i)
    lines[i] = {points[i].real(), -points[i].imag(), i};

  solve(points2, lines, points);

  return 0;
}