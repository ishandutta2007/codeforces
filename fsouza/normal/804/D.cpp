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

struct solver_t {
  int n;
  vector<vector<int>> adj;
  vector<int> root;
  vector<int> max_dist;
  vector<vector<int>> under_root;
  map<pair<int, int>, double> cache;

  struct group_t {
    int diameter;
    vector<int> dists;
    vector<int> acc_count;
    vector<lint> acc_sum;
    void init() {
      diameter = *max_element(dists.begin(), dists.end());
      acc_count.resize(size() + 1);
      acc_sum.resize(size() + 1);
      for (int d : dists) {
        ++acc_count[d + 1];
        acc_sum[d + 1] += d;
      }
      for (int d = 1; d <= size(); ++d) {
        acc_count[d] += acc_count[d - 1];
        acc_sum[d] += acc_sum[d - 1];
      }
    }
    int count_range(int a, int b) const {
      return acc_count[min(b, size())] - acc_count[a];
    }
    lint sum_range(int a, int b) const {
      return acc_sum[min(b, size())] - acc_sum[a];
    }
    int size() const {
      return dists.size();
    }
  };
  vector<group_t> groups;

  solver_t(int _n): n(_n), adj(n), root(n, -1), max_dist(n, 0), under_root(n), groups(n) {}
  void set_root(int v, int p, int r) {
    root[v] = r;
    under_root[r].push_back(v);
    for (int u : adj[v])
      if (u != p)
        set_root(u, v, r);
  }
  pair<int, int> furthest(int v, int p) {
    pair<int, int> result(v, 0);
    for (int u : adj[v])
      if (u != p) {
        pair<int, int> res = furthest(u, v);
        if (res.second + 1 > result.second)
          result = make_pair(res.first, res.second + 1);
      }
    return result;
  }
  void update_max_dist(int v, int p, int d) {
    max_dist[v] = max(max_dist[v], d);
    for (int u : adj[v])
      if (u != p)
        update_max_dist(u, v, d + 1);
  }
  void init() {
    for (int i = 0; i < n; ++i)
      if (root[i] == -1) {
        set_root(i, -1, i);
        int diam_a = furthest(i, -1).first;
        int diam_b = furthest(diam_a, -1).first;
        update_max_dist(diam_a, -1, 0);
        update_max_dist(diam_b, -1, 0);
        for (int v : under_root[i])
          groups[i].dists.push_back(max_dist[v]);
        groups[i].init();
      }
  }
  double query(int a, int b) {
    a = root[a], b = root[b];
    if (a == b) return -1.0;
    if (make_pair(groups[a].size(), a) > make_pair(groups[b].size(), b))
      swap(a, b);
    if (cache.find(make_pair(a, b)) != cache.end())
      return cache[make_pair(a, b)]; // This ensures time complexity.
    return cache[make_pair(a, b)] = group_query(groups[a], groups[b]);
  }
  double group_query(const group_t &a, const group_t &b) {
    assert(a.size() <= b.size());
    const int min_diameter = max(a.diameter, b.diameter);
    lint result = 0;
    for (int d : a.dists) {
      int higher_from = max(0, min_diameter - d);
      result += (lint)min_diameter * b.count_range(0, higher_from);
      result += (lint)(1 + d) * b.count_range(higher_from, b.size()) +
        b.sum_range(higher_from, b.size());
    }
    return result / ((ldouble)a.size() * b.size());
  }
};

int main() {
  int n, m, nq;
  scanf("%d %d %d", &n, &m, &nq);
  solver_t solver(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    solver.adj[a].push_back(b);
    solver.adj[b].push_back(a);
  }
  solver.init();
  for (int q = 0; q < nq; ++q) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    double result = solver.query(a, b);
    if (result == -1.0) printf("-1\n");
    else printf("%.10f\n", result);
  }
  return 0;
}