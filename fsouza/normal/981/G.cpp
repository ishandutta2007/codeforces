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

const int mod = 998244353;

struct mat_t {
  int v[2][2] = {};
  bool operator==(const mat_t &o) const {
    for (int y = 0; y < 2; ++y)
      for (int x = 0; x < 2; ++x)
        if (v[y][x] != o.v[y][x])
          return false;
    return true;
  }
};

mat_t mult(const mat_t &a, const mat_t &b) {
  mat_t result;
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) {
      lint res = 0LL;
      for (int k = 0; k < 2; ++k)
        res += (lint)a.v[i][k] * b.v[k][j];
      result.v[i][j] = res % mod;
    }
  return result;
}

mat_t ident, plus_one, minus_one, mult_two;

struct segtree_t {
  struct node_t {
    int x, y;
    mat_t lazy;
    node_t() {
      x = 0;
      y = 0;
      lazy = ident;
    }
    node_t(int _single) {
      x = 0;
      y = 1;
      lazy = ident;
    }
    node_t(const node_t &a, const node_t &b) {
      //      assert(a.lazy == ident);
      //      assert(b.lazy == ident);

      x = a.x + b.x;
      if (x >= mod) x -= mod;

      y = a.y + b.y;

      lazy = ident;
    }
  };
  int n;
  vector<node_t> tree;
  segtree_t(int _n): n(_n), tree(4 * n) {
    build(0, 0, n - 1);
  }
  void build(int v, int l, int r) {
    if (l == r) tree[v] = node_t(-1);
    else {
      int m = l+(r-l)/2;
      build(2*v+1, l, m);
      build(2*v+2, m+1, r);
      tree[v] = node_t(tree[2*v+1], tree[2*v+2]);
    }
  }
  void update(int a, int b, mat_t trans) {
    update(a, b, trans, 0, 0, n - 1);
  }
  void update(int a, int b, mat_t trans, int v, int l, int r) {
    propag(v, l, r);
    if (a > r || b < l) {
    } else if (a <= l && r <= b) {
      tree[v].lazy = trans;
      propag(v, l, r);
    } else {
      int m = l+(r-l)/2;
      update(a, b, trans, 2*v+1, l, m);
      update(a, b, trans, 2*v+2, m+1, r);
      tree[v] = node_t(tree[2*v+1], tree[2*v+2]);
    }
  }
  node_t query(int a, int b) {
    return query(a, b, 0, 0, n - 1);
  }
  node_t query(int a, int b, int v, int l, int r) {
    propag(v, l, r);
    if (a > r || b < l) return node_t();
    else if (a <= l && r <= b) return tree[v];
    else {
      int m = l+(r-l)/2;
      node_t left = query(a, b, 2*v+1, l, m);
      node_t right = query(a, b, 2*v+2, m+1, r);
      return node_t(left, right);
    }
  }
  void propag(int v, int l, int r) {
    if (tree[v].lazy == ident)
      return;

    const mat_t &mat = tree[v].lazy;

    int new_x =
      ((lint)tree[v].x * mat.v[0][0] + (lint)tree[v].y * mat.v[0][1]) % mod;
    int new_y =
      ((lint)tree[v].x * mat.v[1][0] + (lint)tree[v].y * mat.v[1][1]) % mod;
    tree[v].x = new_x;
    tree[v].y = new_y;

    if (l != r) {
      tree[2*v+1].lazy = mult(tree[v].lazy, tree[2*v+1].lazy);
      tree[2*v+2].lazy = mult(tree[v].lazy, tree[2*v+2].lazy);
    }

    tree[v].lazy = ident;
  }
};

struct range_t {
  int a, b;
  bool operator<(const range_t &o) const {
    return a < o.a;
  }
  int size() const {
    return max(0, b - a + 1);
  }
};

range_t intersection(const range_t &r1, const range_t &r2) {
  return {max(r1.a, r2.a), min(r1.b, r2.b)};
}

bool is_covered(const range_t &r, const set<range_t> &ranges) {
  auto it = ranges.upper_bound(r);
  if (it == ranges.begin()) return false;
  --it;
  return it->b >= r.b;
}

void get_union(vector<range_t> &ranges) {
  sort(ranges.begin(), ranges.end(),
       [](const range_t &a, const range_t &b) {
         if (a.a != b.a) return a.a < b.a;
         return a.b > b.b;
       });
  int new_size = 0;
  for (int i = 0; i < (int)ranges.size(); ++i) {
    if (new_size > 0 && ranges[new_size - 1].b >= ranges[i].b) {
    } else if (new_size > 0 && ranges[new_size - 1].b >= ranges[i].a - 1) {
      ranges[new_size - 1].b = ranges[i].b;
    } else {
      swap(ranges[i], ranges[new_size++]);
    }
  }
  ranges.resize(new_size);
}

int main() {
  ident.v[0][0] = 1;
  ident.v[1][1] = 1;

  plus_one.v[0][0] = 1;
  plus_one.v[0][1] = 1;
  plus_one.v[1][1] = 1;

  minus_one.v[0][0] = 1;
  minus_one.v[0][1] = mod - 1;
  minus_one.v[1][1] = 1;

  mult_two.v[0][0] = 2;
  mult_two.v[1][1] = 1;

  int n, nq;
  scanf("%d %d", &n, &nq);

  vector<set<range_t>> ranges_v(n);
  segtree_t seg(n);

  for (int q = 0; q < nq; ++q) {
    int kind;
    scanf("%d", &kind);
    if (kind == 1) {
      int l, r, value;
      scanf("%d %d %d", &l, &r, &value), --l, --r, --value;

      set<range_t> &ranges = ranges_v[value];
      range_t new_range = {l, r};

      if (is_covered(new_range, ranges)) {
        seg.update(l, r, mult_two);
      } else {
        seg.update(l, r, plus_one);
        static vector<range_t> parsed; parsed.clear();

        auto it = ranges.upper_bound(new_range);
        if (it != ranges.begin()) --it;
        for (; it != ranges.end() && it->a <= new_range.b; ++it) {
          range_t both = intersection(*it, new_range);
          if (both.size() > 0) {
            seg.update(both.a, both.b, minus_one);
            seg.update(both.a, both.b, mult_two);
          }
          parsed.push_back(*it);
        }

        for (range_t rr : parsed) ranges.erase(rr);
        parsed.push_back(new_range);

        get_union(parsed);

        for (range_t rr : parsed) ranges.insert(rr);
      }
    } else {
      int l, r;
      scanf("%d %d", &l, &r), --l, --r;
      int result = seg.query(l, r).x;
      printf("%d\n", result);
    }
  }

  return 0;
}