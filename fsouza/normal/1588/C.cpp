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

const lint INF = LLONG_MAX / 4;

struct segtree_t {
  struct node_t {
    lint v01;
    lint min01;
    int count01;
    lint min10;
    int count10;
    node_t() {
      v01 = 0LL;
      min01 = min10 = INF;
      count01 = count10 = 0;
    }
    node_t(int pos, int value) {
      if (pos % 2 == 0) {
        v01 = value;
        min01 = value;
        count01 = 1;
        min10 = INF;
        count10 = 0;
      } else {
        v01 = -value;
        min10 = value;
        count10 = 1;
        min01 = INF;
        count01 = 0;
      }
    }
    node_t(const node_t &l, node_t r) {
      if (r.min01 != INF) r.min01 += l.v01;
      if (r.min10 != INF) r.min10 -= l.v01;
      v01 = l.v01 + r.v01;
      if (l.min01 < r.min01) {
        min01 = l.min01, count01 = l.count01;
      } else if (r.min01 < l.min01) {
        min01 = r.min01, count01 = r.count01;
      } else {
        min01 = l.min01, count01 = l.count01 + r.count01;
      }
      if (l.min10 < r.min10) {
        min10 = l.min10, count10 = l.count10;
      } else if (r.min10 < l.min10) {
        min10 = r.min10, count10 = r.count10;
      } else {
        min10 = l.min10, count10 = l.count10 + r.count10;
      }
    }
    bool ok() const {
      return min01 >= 0 && min10 >= 0;
    }
  };
  int n;
  vector<node_t> tree;
  segtree_t(vector<int> values): n(values.size()), tree(4 * n) {
    build(0, 0, n - 1, values);
  }
  void build(int v, int l, int r, const vector<int> &values) {
    if (l == r) {
      tree[v] = node_t(l, values[l]);
    } else {
      int m = l + (r - l) / 2;
      build(2*v+1, l, m, values);
      build(2*v+2, m+1, r, values);
      tree[v] = node_t(tree[2*v+1], tree[2*v+2]);
    }
  }
  struct res_t {
    node_t cur;
    bool open = true;
  };
  int query(int a, int b) {
    res_t res = query(a, b, {node_t(), true}, 0, 0, n - 1);
    int many = 0;
    if (res.cur.min01 == 0) many += res.cur.count01;
    if (res.cur.min10 == 0) many += res.cur.count10;
    return many;
  }
  res_t query(int a, int b, res_t res, int v, int l, int r) {
    if (!res.open)
      return res;

    if (a > r || b < l) {
      return res;
    } else if (a <= l && r <= b) {
      node_t cand = node_t(res.cur, tree[v]);
      if (cand.ok()) {
        return {cand, true};
      }
      if (r - l + 1 == 1) {
        return {res.cur, false};
      }
    }

    int m = l + (r - l) / 2;
    res = query(a, b, res, 2*v+1, l, m);
    if (res.open)
      res = query(a, b, res, 2*v+2, m+1, r);
    return res;
  }
};

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);
    vector<int> values(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &values[i]);
    segtree_t seg(values);
    lint result = 0LL;
    for (int i = 0; i < n; ++i) {
      result += seg.query(i, n - 1);
    }
    printf("%lld\n", result);
  }
  return 0;
}