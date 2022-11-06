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
  int n;
  struct node_t {
    int max_value;
    int lazy;
  };
  vector<node_t> tree;
  segtree_t(const vector<int> &init_values)
      : n(init_values.size()), tree(4 * n) {
    build_tree(0, 0, n - 1, init_values);
  }
  void build_tree(int v, int l, int r, const vector<int> &init_values) {
    if (l == r) {
      tree[v].max_value = init_values[l];
      tree[v].lazy = 0;
    } else {
      int m = l + (r - l) / 2;
      build_tree(2*v+1, l, m, init_values);
      build_tree(2*v+2, m+1, r, init_values);
      tree[v].max_value = max(tree[2 * v + 1].max_value,
                              tree[2 * v + 2].max_value);
      tree[v].lazy = 0;
    }
  }
  void propag(int v, int l, int r) {
    if (tree[v].lazy != 0) {
      tree[v].max_value += tree[v].lazy;
      if (l != r) {
        tree[2 * v + 1].lazy += tree[v].lazy;
        tree[2 * v + 2].lazy += tree[v].lazy;
      }
      tree[v].lazy = 0;
    }
  }
  void update(int a, int b, int delta) {
    auto update_node = [&](auto &&self, int v, int l, int r) -> void {
      this->propag(v, l, r);
      if (a > r || b < l) {
      } else if (a <= l && r <= b) {
        tree[v].lazy += delta;
        this->propag(v, l, r);
      } else {
        int m = l+(r-l)/2;
        self(self, 2*v+1, l, m);
        self(self, 2*v+2, m+1, r);
        tree[v].max_value = max(tree[2 * v + 1].max_value,
                                tree[2 * v + 2].max_value);
        assert(tree[v].lazy == 0);
      }
    };
    update_node(update_node, 0, 0, n - 1);
  }
  int query(int a, int b) {
    auto query_node = [&](auto &&self, int v, int l, int r) {
      propag(v, l, r);
      if (a > r || b < l) return INT_MIN;
      else if (a <= l && r <= b) return tree[v].max_value;
      else {
        int m = l+(r-l)/2;
        return max(self(self, 2*v+1, l, m),
                   self(self, 2*v+2, m+1, r));
      }
    };
    return query_node(query_node, 0, 0, n - 1);
  }
};

int main() {
  int n, K;
  scanf("%d %d", &n, &K);
  vector<int> values(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &values[i]), --values[i];
  vector<int> dp(n + 1, INT_MIN / 2);
  dp[n] = 0;
  for (int k = 1; k <= K; ++k) {
    segtree_t seg(dp);
    vector<int> next_of_value(n, n);
    vector<int> next_dp(n + 1);
    next_dp[n] = INT_MIN / 2;
    for (int i = n - 1; i >= 0; --i) {
      seg.update(i + 1, next_of_value[values[i]], +1);
      next_of_value[values[i]] = i;
      next_dp[i] = seg.query(i + 1, n);
    }
    dp = next_dp;
  }
  printf("%d\n", dp[0]);
  return 0;
}