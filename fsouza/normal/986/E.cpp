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

const int mod = 1e9 + 7, max_value = 1e7;

int modpow(int x, int y, int m) {
  int ret = 1 % m, x2p = x;
  while (y > 0) {
    if (y % 2) ret = (lint)ret * x2p % m;
    y /= 2;
    x2p = (lint)x2p * x2p % m;
  }
  return ret;
}

int inv(int a, int p) { return modpow(a, p - 2, p); }

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b%a, a);
}

vector<int> min_divisor;
void prepare_sieve(int limit) {
  min_divisor.resize(limit + 1, -1);
  for (int i = 2; i <= limit; ++i) min_divisor[i] = i;
  for (int i = 2; i <= limit; ++i)
    if (min_divisor[i] == i)
      for (int j = 2 * i; j <= limit; j += i)
        if (min_divisor[j] == j)
          min_divisor[j] = i;
}
template<typename Func>
void for_each_prime_power(int value, Func func) {
  assert(value >= 1);
  while (value > 1) {
    int p = min_divisor[value];
    int exp = 0;
    do {
      value /= p;
      ++exp;
    } while (value % p == 0);
    func(p, exp);
  }
}

struct query2_t {
  int value, *result;
};

struct query1_t {
  int a, b, value, lca;
  int res_a, res_b, res_lca;
  int result;
  query1_t() {}
  query1_t(int _a, int _b, int _value): a(_a), b(_b), value(_value) {}
};

struct solver_t {
  int n, lgn;
  vector<vector<int>> adj;
  vector<int> values;
  vector<int> depth;
  vector<vector<int>> ancestor;
  vector<query1_t> queries1;
  vector<vector<query2_t>> queries2;
  solver_t(int _n)
      : n(_n)
      , lgn(__lg(n))
      , adj(n)
      , values(n)
      , depth(n)
      , ancestor(lgn + 1, vector<int>(n))
      , queries2(n) {}
  void dfs(int v, int p, int d) {
    depth[v] = d;
    ancestor[0][v] = p;
    for (int l = 1; l <= lgn; ++l)
      ancestor[l][v] = (d >= (1<<l) ? ancestor[l - 1][ancestor[l - 1][v]] : -1);

    for (int u : adj[v])
      if (u != p)
        dfs(u, v, d + 1);
  }
  int climb(int v, int dist) {
    for (int l = 0; l <= lgn; ++l)
      if (dist & (1<<l))
        v = ancestor[l][v];
    return v;
  }
  int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    a = climb(a, depth[a] - depth[b]);
    if (a == b) return a;
    for (int l = lgn; l >= 0; --l)
      if (ancestor[l][a] != ancestor[l][b])
        a = ancestor[l][a], b = ancestor[l][b];
    return ancestor[0][a];
  }
  map<int, vector<int>> p_exp_count;
  void dfs2(int v, int parent) {
    for_each_prime_power(values[v], [&](int p, int exp) {
        vector<int> &exp_count = p_exp_count[p];
        if ((int)exp_count.size() < exp + 1)
          exp_count.resize(exp + 1);
        for (int i = 1; i <= exp; ++i)
          exp_count[i] += 1;
      });

    for (query2_t &q : queries2[v]) {
      *q.result = 1;
      for_each_prime_power(q.value, [&](int p, int exp) {
          auto exp_count_it = p_exp_count.find(p);
          if (exp_count_it == p_exp_count.end()) return;
          vector<int> &exp_count = exp_count_it->second;

          int res_p_exp = 0;
          for (int i = 1; i <= exp && i < (int)exp_count.size(); ++i)
            res_p_exp += exp_count[i];
          *q.result = (lint)*q.result * modpow(p, res_p_exp, mod) % mod;
        });
    }

    for (int u : adj[v])
      if (u != parent)
        dfs2(u, v);

    for_each_prime_power(values[v], [&](int p, int exp) {
        vector<int> &exp_count = p_exp_count[p];
        for (int i = 1; i <= exp; ++i)
          exp_count[i] -= 1;
      });
  }
  void solve() {
    dfs(0, -1, 0);

    for (query1_t &q : queries1) {
      q.lca = lca(q.a, q.b);
      queries2[q.a].push_back({q.value, &q.res_a});
      queries2[q.b].push_back({q.value, &q.res_b});
      queries2[q.lca].push_back({q.value, &q.res_lca});
    }

    dfs2(0, -1);

    for (query1_t &q : queries1) {
      int inv_res_lca = inv(q.res_lca, mod);
      q.result = (lint)q.res_a * q.res_b % mod * inv_res_lca % mod *
                 inv_res_lca % mod * gcd(q.value, values[q.lca]) % mod;
    }
  }
};

int main() {
  prepare_sieve(max_value);

  int n;
  scanf("%d", &n);
  solver_t solver(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    solver.adj[a].push_back(b);
    solver.adj[b].push_back(a);
  }
  for (int i = 0; i < n; ++i)
    scanf("%d", &solver.values[i]);
  int nq;
  scanf("%d", &nq);
  vector<query1_t> &queries = solver.queries1;
  queries.resize(nq);
  for (int q = 0; q < nq; ++q) {
    int a, b, value;
    scanf("%d %d %d", &a, &b, &value), --a, --b;
    queries[q] = {a, b, value};
  }
  solver.solve();
  for (int q = 0; q < nq; ++q) {
    printf("%d\n", queries[q].result);
  }
  return 0;
}