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

struct pair_t {
  int a, b;
  bool operator==(const pair_t &o) const {
    return a == o.a && b == o.b;
  }
};

pair_t combine(const pair_t &lhs, const pair_t &rhs) {
  return {min(lhs.a, rhs.a), max(lhs.b, rhs.b)};
}

template<typename T>
struct rmq_t {
  vector<vector<T>> table;
  rmq_t() {}
  rmq_t(const vector<T> &values) {
    table.push_back(values);
    for (int l = 1; l <= (int)__lg(values.size()); ++l) {
      table.push_back(vector<T>(values.size() - (1<<l) + 1));
      for (int i = 0; i+(1<<l) <= (int)values.size(); ++i)
	table[l][i] = combine(table[l-1][i], table[l-1][i+(1<<(l-1))]);
    }
  }
  T query(int a, int b) {
    int size = b-a+1, l = __lg(size);
    return combine(table[l][a], table[l][b-(1<<l)+1]);
  }
};

struct segtree_t {
  struct node_t {
    lint active_sum = 0LL, result_sum = 0LL, lazy = 0LL;
    node_t() {}
    node_t(const node_t &a, const node_t &b) {
      active_sum = a.active_sum + b.active_sum;
      result_sum = a.result_sum + b.result_sum;
      lazy = 0LL;
    }
  };
  int n;
  vector<node_t> tree;
  segtree_t(int _n): n(_n), tree(4 * n) {}
  void activate(int pos, lint delta) { activate(pos, delta, 0, 0, n - 1); }
  void activate(int pos, lint delta, int v, int l, int r) {
    propag(v, l, r);
    if (l == r) tree[v].active_sum += delta;
    else {
      int m = l+(r-l)/2;
      if (pos <= m) {
        activate(pos, delta, 2*v+1, l, m);
        propag(2*v+2, m+1, r);
      } else {
        activate(pos, delta, 2*v+2, m+1, r);
        propag(2*v+1, l, m);
      }
      tree[v] = node_t(tree[2 * v + 1], tree[2 * v + 2]);
    }
  }
  void apply(int a, int b, lint times) { apply(a, b, times, 0, 0, n - 1); }
  void apply(int a, int b, lint times, int v, int l, int r) {
    propag(v, l, r);
    if (a > r || b < l) {
    } else if (a <= l && r <= b) {
      tree[v].lazy += times;
      propag(v, l, r);
    } else {
      int m = l+(r-l)/2;
      apply(a, b, times, 2*v+1, l, m);
      apply(a, b, times, 2*v+2, m+1, r);
      tree[v] = node_t(tree[2 * v + 1], tree[2 * v + 2]);
    }
  }
  lint query(int a, int b) { return query(a, b, 0, 0, n - 1); }
  lint query(int a, int b, int v, int l, int r) {
    propag(v, l, r);
    if (a > r || b < l) return 0LL;
    else if (a <= l && r <= b) return tree[v].result_sum;
    else {
      int m = l+(r-l)/2;
      return query(a, b, 2*v+1, l, m) + query(a, b, 2*v+2, m+1, r);
    }
  }
  void propag(int v, int l, int r) {
    if (tree[v].lazy == 0) return;
    tree[v].result_sum += tree[v].lazy * tree[v].active_sum;
    if (l != r) {
      tree[2 * v + 1].lazy += tree[v].lazy;
      tree[2 * v + 2].lazy += tree[v].lazy;
    }
    tree[v].lazy = 0LL;
  }
};

struct solver_t {
  struct node_t {
    struct query_t {
      int a, b;
      lint *output;
    };
    vector<query_t> queries;
    vector<lint*> full_queries;
    lint solve(int l, int r, lint full_result, rmq_t<pair_t> &adj2pos) {
      int range_size = r - l + 1;
      if (range_size == 1) {
        full_result += 1;
        for (lint *output : full_queries) *output += full_result;
        return full_result;
      }
      const int m = l+(r-l)/2;
      vector<pair<int, int>> prefixes;
      for (int i = l; i <= m; ++i) {
        pair_t expand = adj2pos.query(i, m);
        if (expand.a == i) {
          int size = m - i + 1;
          int need = expand.b - (m + 1) + 1;
          prefixes.emplace_back(need, size);
        }
      }
      sort(prefixes.begin(), prefixes.end(), greater<pair<int, int>>());
      sort(queries.begin(), queries.end(),
           [](const query_t &lhs, const query_t &rhs) {
             return lhs.b > rhs.b;
           });
      segtree_t seg((range_size + 1) / 2 + 1);
      for (int i = m + 1; i <= r; ++i) {
        pair_t expand = adj2pos.query(m, i - 1);
        int size = i - (m + 1) + 1;
        while (!prefixes.empty() && prefixes.back().first <= size) {
          seg.activate(prefixes.back().second, +1);
          prefixes.pop_back();
        }
        if (expand.b == i) {
          int need = m - expand.a + 1;
          seg.apply(need, seg.n - 1, +1);
        }
        while (!queries.empty() && queries.back().b == i) {
          int max_size = m - queries.back().a + 1;
          *queries.back().output += seg.query(1, max_size);
          queries.pop_back();
        }
      }
      full_result += seg.query(1, seg.n - 1);
      for (lint *output : full_queries) *output += full_result;
      return full_result;
    }
  };
  vector<int> perm;
  int n;
  vector<node_t> tree;
  rmq_t<pair_t> rmq_adj2pos;
  solver_t(vector<int> &_perm): perm(_perm), n(perm.size()), tree(4 * n) {}
  void add_query(int a, int b, lint *output) {
    add_query(a, b, output, 0, 0, n - 1);
  }
  void add_query(int a, int b, lint *output, int v, int l, int r) {
    if (a > r || b < l) {
    } else if (a <= l && r <= b) {
      tree[v].full_queries.push_back(output);
    } else {
      int m = l+(r-l)/2;
      if (a <= m && b > m)
        tree[v].queries.push_back({max(a, l), min(b, r), output});
      add_query(a, b, output, 2*v+1, l, m);
      add_query(a, b, output, 2*v+2, m+1, r);
    }
  }
  lint solve_queries(int v, int l, int r) {
    lint full_result = 0LL;
    if (l != r) {
      int m = l + (r - l) / 2;
      full_result += solve_queries(2 * v + 1, l, m);
      full_result += solve_queries(2 * v + 2, m + 1, r);
    }
    return tree[v].solve(l, r, full_result, rmq_adj2pos);
  }
  void solve() {
    vector<pair_t> value2pos(n);
    for (int i = 0; i < n; ++i)
      value2pos[perm[i]] = {i, i};
    rmq_t<pair_t> rmq_value2pos(value2pos);

    vector<pair_t> adj2pos(n - 1);
    for (int i = 0; i + 1 < n; ++i) {
      adj2pos[i] = rmq_value2pos.query(min(perm[i], perm[i + 1]),
                                       max(perm[i], perm[i + 1]));
    }
    rmq_adj2pos = rmq_t<pair_t>(adj2pos);
    bool repeat;
    do {
      vector<pair_t> new_adj2pos(n - 1);
      for (int i = 0; i + 1 < n; ++i)
        new_adj2pos[i] = rmq_adj2pos.query(adj2pos[i].a, adj2pos[i].b - 1);
      repeat = false;
      if (new_adj2pos != adj2pos) {
        repeat = true;
        adj2pos = new_adj2pos;
        rmq_adj2pos = rmq_t<pair_t>(adj2pos);
      }
    } while (repeat);
    solve_queries(0, 0, n - 1);
  }
};

int main() {
  int n;
  scanf("%d", &n);
  vector<int> perm(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &perm[i]), --perm[i];
  solver_t solver(perm);
  int nq;
  scanf("%d", &nq);
  vector<lint> result(nq);
  for (int q = 0; q < nq; ++q) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    solver.add_query(a, b, &result[q]);
  }
  solver.solve();
  for (int q = 0; q < nq; ++q) {
    printf("%lld\n", result[q]);
  }
  return 0;
}