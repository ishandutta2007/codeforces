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

struct node_t {
  lint sum;
  lint min_prefix, max_prefix;
  node_t(lint v) {
    sum = v;
    min_prefix = min(0LL, v);
    max_prefix = max(0LL, v);
  }
  node_t(): node_t(0LL) {}
  node_t(const node_t &a, const node_t &b) {
    sum = a.sum + b.sum;
    min_prefix = min(a.min_prefix, a.sum + b.min_prefix);
    max_prefix = max(a.max_prefix, a.sum + b.max_prefix);
  }
};

struct segtree_t {
  int n;
  vector<node_t> nodes;
  segtree_t(const vector<int> &values): n(values.size()), nodes(4 * n) {
    build(0, 0, n - 1, values);
  }
  void build(int v, int l, int r, const vector<int> &values) {
    if (l == r) {
      nodes[v] = node_t(values[l]);
    } else {
      int m = l + (r - l) / 2;
      build(2*v+1, l, m, values);
      build(2*v+2, m+1, r, values);
      nodes[v] = node_t(nodes[2*v+1], nodes[2*v+2]);
    }
  }
  node_t query(int a, int b) { return query(a, b, 0, 0, n - 1); }
  node_t query(int a, int b, int v, int l, int r) {
    if (a > r || b < l) return {};
    else if (a <= l && r <= b) return nodes[v];
    else {
      int m = l + (r - l) / 2;
      return node_t(query(a, b, 2*v+1, l, m),
                    query(a, b, 2*v+2, m+1, r));
    }
  }
};

int main() {
  int n, nq;
  scanf("%d %d", &n, &nq);
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  vector<int> b(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &b[i]);

  vector<int> deltas(n);
  for (int i = 0; i < n; ++i) {
    deltas[i] = b[i] - a[i];
  }

  segtree_t seg(deltas);
  for (int q = 0; q < nq; ++q) {
    int l, r;
    scanf("%d %d", &l, &r), --l, --r;
    node_t res = seg.query(l, r);
    if (res.sum != 0 || res.min_prefix < 0) {
      printf("-1\n");
    } else {
      printf("%lld\n", res.max_prefix);
    }
  }

  return 0;
}