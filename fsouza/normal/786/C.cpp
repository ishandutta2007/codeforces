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

struct segtree_t {
  struct node_t {
    int count = 0;
  };
  int n;
  vector<node_t> tree;
  segtree_t(int _n): n(_n), tree(4 * n) {}
  void update(int pos, int value, int v, int l, int r) {
    if (l == r) {
      tree[v].count = value;
    } else {
      int m = l+(r-l)/2;
      if (pos <= m) update(pos, value, 2*v+1, l, m);
      else update(pos, value, 2*v+2, m+1, r);
      tree[v].count = tree[2 * v + 1].count + tree[2 * v + 2].count;
    }
  }
  void update(int pos, int value) {
    update(pos, value, 0, 0, n - 1);
  }
  int query(int k, int v, int l, int r) {
    if (l == r) return l;
    else {
      int m = l+(r-l)/2;
      if (k < tree[2 * v + 1].count) return query(k, 2*v+1, l, m);
      else return query(k - tree[2 * v + 1].count, 2*v+2, m+1, r);
    }
  }
  int query(int k) {
    assert(k >= 0);
    if (k >= tree[0].count)
      return n;
    return query(k, 0, 0, n-1);
  }
};

int main() {
  int n;
  scanf("%d", &n);
  vector<int> color(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &color[i]), --color[i];

  segtree_t seg(n);
  vector<int> undo_remove(n);
  vector<int> next_of_color(n, n);
  for (int i = n - 1; i >= 0; --i) {
    int next = next_of_color[color[i]];
    undo_remove[i] = next;
    if (next != n) {
      seg.update(next, 0);
    }
    seg.update(i, 1);
    next_of_color[color[i]] = i;
  }
  vector<vector<int>> queries(n);
  for (int q = 1; q <= n; ++q)
    queries[0].push_back(q);
  vector<int> result(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    for (int q : queries[i]) {
      int q_th = seg.query(q);
      if (q_th != n)
        queries[q_th].push_back(q);
      ++result[q];
    }
    if (undo_remove[i] != n)
      seg.update(undo_remove[i], 1);
    seg.update(i, 0);
  }
  for (int q = 1; q <= n; ++q) {
    if (q > 1) printf(" ");
    printf("%d", result[q]);
  }
  printf("\n");
  return 0;
}