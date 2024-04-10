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

struct tree_t {
  struct node_t {
    int leftmost = INT_MAX, rightmost = INT_MIN, min_dp = INT_MAX;
    node_t() {}
    node_t(const node_t &a, const node_t &b) {
      leftmost = min(a.leftmost, b.leftmost);
      rightmost = max(a.rightmost, b.rightmost);
      min_dp = min(a.min_dp, b.min_dp);
    }
  };
  int n;
  vector<node_t> tree;
  tree_t(const vector<int> &positions): n(positions.size()), tree(4*n) {
    build(0, 0, n - 1, positions);
  }
  void build(int v, int l, int r, const vector<int> &positions) {
    if (l == r) {
      tree[v].leftmost = tree[v].rightmost = positions[l];
    } else {
      int m = l+(r-l)/2;
      build(2*v+1, l, m, positions);
      build(2*v+2, m+1, r, positions);
      tree[v] = node_t(tree[2*v+1], tree[2*v+2]);
    }
  }
  void update(int pos, int dp) { update(pos, dp, 0, 0, n - 1); }
  void update(int pos, int dp, int v, int l, int r) {
    if (l == r) {
      tree[v].min_dp = dp;
    } else {
      int m = l+(r-l)/2;
      if (pos <= m) update(pos, dp, 2*v+1, l, m);
      else update(pos, dp, 2*v+2, m+1, r);
      tree[v] = node_t(tree[2*v+1], tree[2*v+2]);
    }
  }
  node_t query(int a, int b) { return query(a, b, 0, 0, n - 1); }
  node_t query(int a, int b, int v, int l, int r) {
    if (a > r || b < l) return node_t();
    else if (a <= l && r <= b) return tree[v];
    else {
      int m = l+(r-l)/2;
      return node_t(query(a, b, 2*v+1, l, m),
                    query(a, b, 2*v+2, m+1, r));
    }
  }
  int dp_bound_until(int from, int position, int &min_dp, int &max_dist,
                     int v, int l, int r) {
    if (r < from) return from - 1;
    else if (l >= from) {
      const int dist_for_node = max(abs(position - tree[v].leftmost),
                                    abs(position - tree[v].rightmost));
      if (min(min_dp, tree[v].min_dp) > max(max_dist, dist_for_node)) {
        min_dp = min(min_dp, tree[v].min_dp);
        max_dist = max(max_dist, dist_for_node);
        return r;
      }
      if (min_dp <= max_dist) {
        min_dp = min(min_dp, tree[v].min_dp);
        max_dist = max(max_dist, dist_for_node);
        return from - 1;
      }
      if (l == r) {
        min_dp = min(min_dp, tree[v].min_dp);
        max_dist = max(max_dist, dist_for_node);
        return from - 1;
      } else {
        int m = l+(r-l)/2;
        int res_left =
          dp_bound_until(from, position, min_dp, max_dist, 2*v+1, l, m);
        int res_right =
          dp_bound_until(from, position, min_dp, max_dist, 2*v+2, m+1, r);
        return max(res_left, res_right);
      }
    } else {
      int m = l+(r-l)/2;
      int res_left =
        dp_bound_until(from, position, min_dp, max_dist, 2*v+1, l, m);
      int res_right =
        dp_bound_until(from, position, min_dp, max_dist, 2*v+2, m+1, r);
      return max(res_left, res_right);
    }
  }
  int dp_bound_until(int from, int position) {
    int min_dp = INT_MAX;
    int max_dist = INT_MIN;
    return dp_bound_until(from, position, min_dp, max_dist, 0, 0, n - 1);
  }
};

vector<int> compute_dp(const vector<int> &positions) {
  const int n = positions.size();
  vector<int> result(n);
  tree_t tree(positions);
  result[n - 1] = 0;
  tree.update(n - 1, 0);
  for (int i = n - 2; i >= 0; --i) {
    int until = tree.dp_bound_until(i + 1, positions[i]);
    int result_i = INT_MAX;
    if (until >= i + 1) {
      tree_t::node_t res = tree.query(i + 1, until);
      result_i = min(result_i, res.min_dp);
    }
    if (until + 1 < n) {
      tree_t::node_t res = tree.query(i + 1, until + 1);
      result_i = min(result_i, max(abs(positions[i] - res.leftmost),
                                   abs(positions[i] - res.rightmost)));
    }
    result[i] = result_i;
    tree.update(i, result_i);
  }
  return result;
}

int get_result(const vector<int> &positions, const vector<int> &dp,
               int first_pos, int other_pos) {
  int best_result = INT_MAX;
  int current_result = abs(first_pos - other_pos);
  for (int i = 0; i < (int)dp.size(); ++i) {
    current_result = max(current_result, abs(positions[i] - other_pos));
    best_result = min(best_result, max(current_result, dp[i]));
  }
  return best_result;
}

int main() {
  int n, pos1, pos2;
  scanf("%d %d %d", &n, &pos1, &pos2);
  vector<int> positions(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &positions[i]);
  vector<int> dp = compute_dp(positions);
  int result = min(get_result(positions, dp, pos1, pos2),
                   get_result(positions, dp, pos2, pos1));
  printf("%d\n", result);
  return 0;
}