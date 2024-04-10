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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long lint;

struct point3_t {
  int x, y, z;
  bool operator<(const point3_t &o) const {
    if (x != o.x) return x < o.x;
    if (y != o.y) return y < o.y;
    return z < o.z;
  }
};

struct point_count_2d_t {
  struct node_t {
    tree<lint, null_type, less<lint>,
         rb_tree_tag, tree_order_statistics_node_update> subtree;

    void add(int y) {
      subtree.insert(((lint)y << 32) | (int)subtree.size());
    }

    int query(int y0, int y1) {
      return subtree.order_of_key((lint)(y1 + 1) << 32) -
             subtree.order_of_key((lint)y0 << 32);
    }
  };
  int n;
  vector<node_t> tree{4U * n};

  void add_point(int pos, int y) { add_point(pos, y, 0, 0, n - 1); }

  void add_point(int pos, int y, int v, int l, int r) {
    tree[v].add(y);
    if (l != r) {
      int m = l + (r - l) / 2;
      if (pos <= m) add_point(pos, y, 2*v+1, l, m);
      else add_point(pos, y, 2*v+2, m+1, r);
    }
  }

  int query(int a, int b, int y0, int y1) {
    return query(a, b, y0, y1, 0, 0, n - 1);
  }

  int query(int a, int b, int y0, int y1, int v, int l, int r) {
    if (a > r || b < l) return 0;
    else if (a <= l && r <= b) return tree[v].query(y0, y1);
    else {
      int m = l + (r - l) / 2;
      return query(a, b, y0, y1, 2 * v + 1, l, m) +
             query(a, b, y0, y1, 2 * v + 2, m + 1, r);
    }
  }
};

struct point_count_3d_t {
  int max_y;
  vector<point3_t> points;

  point_count_2d_t counter_2d{max_y};

  struct query_t {
    int x, y0, y1, z0, z1;
    int mult, *output;
  };
  vector<query_t> queries;

  void add_query(int x0, int x1, int y0, int y1, int z0, int z1, int *output) {
    *output = 0;
    queries.push_back({x0 - 1, y0, y1, z0, z1, -1, output});
    queries.push_back({x1, y0, y1, z0, z1, +1, output});
  }

  void solve() {
    sort(points.begin(), points.end());
    sort(queries.begin(), queries.end(),
         [](const query_t &lhs, const query_t &rhs) { return lhs.x < rhs.x; });

    int i = 0;
    for (query_t &q : queries) {
      while (i < (int)points.size() && points[i].x <= q.x) {
        counter_2d.add_point(points[i].y, points[i].z);
        ++i;
      }
      int result = counter_2d.query(q.y0, q.y1, q.z0, q.z1);
      *q.output += q.mult * result;
    }
  }
};

void input_incorrect() {
  printf("INCORRECT\n");
  exit(0);
}

int main() {
  int nx, ny, nz, nopen, nclosed, nq;
  scanf("%d %d %d", &nx, &ny, &nz);
  scanf("%d %d %d", &nopen, &nclosed, &nq);

  const lint volume = (lint)nx * ny * nz;

  int omaxx = INT_MIN, ominx = INT_MAX;
  int omaxy = INT_MIN, ominy = INT_MAX;
  int omaxz = INT_MIN, ominz = INT_MAX;

  set<point3_t> open, closed;
  for (int i = 0; i < nopen; ++i) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z), --x, --y, --z;
    open.insert({x, y, z});

    omaxx = max(omaxx, x);
    ominx = min(ominx, x);

    omaxy = max(omaxy, y);
    ominy = min(ominy, y);

    omaxz = max(omaxz, z);
    ominz = min(ominz, z);
  }
  nopen = open.size();

  for (int i = 0; i < nclosed; ++i) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z), --x, --y, --z;
    closed.insert({x, y, z});
  }
  nclosed = closed.size();

  point_count_3d_t counter{ny, vector<point3_t>(closed.begin(), closed.end())};

  if (nclosed == volume) input_incorrect();

  int init_invalid_closed = 0;
  if (nopen > 0) {
    counter.add_query(ominx, omaxx, ominy, omaxy, ominz, omaxz,
                      &init_invalid_closed);
  }

  enum { OPEN = 0, CLOSED = 1, UNKNOWN = 2 };
  struct query_t {
    point3_t p;
    int sub_result;
    int result = -1;
  };
  vector<query_t> queries(nq);
  for (query_t &q : queries) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z), --x, --y, --z;
    q.p = {x, y, z};

    if (open.find(q.p) != open.end()) q.result = OPEN;
    else if (closed.find(q.p) != closed.end()) q.result = CLOSED;
    else if (open.empty()) {
      if (nclosed == volume - 1) q.result = OPEN;
      else q.result = UNKNOWN;
    } else if (ominx <= x && x <= omaxx &&
               ominy <= y && y <= omaxy &&
               ominz <= z && z <= omaxz) {
      q.result = OPEN;
    } else {
      int ominx2 = min(ominx, x), omaxx2 = max(omaxx, x);
      int ominy2 = min(ominy, y), omaxy2 = max(omaxy, y);
      int ominz2 = min(ominz, z), omaxz2 = max(omaxz, z);

      counter.add_query(ominx2, omaxx2, ominy2, omaxy2, ominz2, omaxz2,
                        &q.sub_result);
    }
  }
  counter.solve();
  if (init_invalid_closed > 0) input_incorrect();

  for (query_t &q : queries) {
    if (q.result == -1) {
      if (q.sub_result > 0) q.result = CLOSED;
      else q.result = UNKNOWN;
    }
  }

  printf("CORRECT\n");
  for (query_t &q : queries) {
    if (q.result == OPEN) printf("OPEN\n");
    else if (q.result == CLOSED) printf("CLOSED\n");
    else printf("UNKNOWN\n");
  }

  exit(0);
  return 0;
}