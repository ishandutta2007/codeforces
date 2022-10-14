#line 1 "linear_basis.h"
#include <cstring>

struct LinearBasis {
  static const int B = 30;

  LinearBasis() { memset(basis, -1, sizeof(basis)); }

  void add(int v) {
    v = ask(v);
    if (v) {
      int pivot = 31 - __builtin_clz(v);
      for (int i = 0; i < B; ++i) {
        if (~basis[i] && (basis[i] >> pivot & 1)) {
          basis[i] ^= v;
        }
      }
      basis[pivot] = v;
    }
  }

  int ask(int v) const {
    for (int i = B; i--;) {
      if ((v >> i & 1) && ~basis[i]) {
        v ^= basis[i];
      }
    }
    return v;
  }

  int basis[B];
};
#line 2 "sol.cpp"
// #include "debug.h"

#include <bits/stdc++.h>

using Edge = std::pair<int, int>;
using Edge3 = std::tuple<int, int, int>;

const int N = 200'000;

std::vector<std::tuple<int, int, int, int, int>> ranges;
std::vector<std::pair<int, int>> queries;

std::vector<Edge3> events[N << 1];

int get_id(int l, int r) { return (l + r) | (l != r); }

void insert(int l, int r, int a, int b, const Edge3 &e) {
  if (b < l || r < a) {
    return;
  }
  if (a <= l && r <= b) {
    events[get_id(l, r)].push_back(e);
  } else {
    int m = (l + r) >> 1;
    insert(l, m, a, b, e);
    insert(m + 1, r, a, b, e);
  }
}

int size[N], parent[N], delta[N];
std::vector<std::pair<int, int>> history;

std::pair<int, int> root(int u) {
  int sum = 0;
  while (u != parent[u]) {
    sum ^= delta[u];
    u = parent[u];
  }
  return {u, sum};
}

std::pair<bool, int> merge(int a, int b, int c) {
  auto [x, xsum] = root(a);
  auto [y, ysum] = root(b);
  if (x == y) {
    return {false, xsum ^ ysum ^ c};
  }
  if (size[x] < size[y]) {
    std::swap(x, y);
  }
  size[x] += size[y];
  parent[y] = x;
  delta[y] = xsum ^ ysum ^ c;
  history.emplace_back(x, y);
  return {true, 0};
}

// std::ostream& operator<<(std::ostream& out, const LinearBasis& basis) {
//     return out << std::vector<int>(basis.basis, basis.basis + B);
// }

int result[N];

void solve(int l, int r, LinearBasis basis) {
  int checkpoint = history.size();
  for (auto [a, b, c] : events[get_id(l, r)]) {
    auto [merged, v] = merge(a, b, c);
    // std::cout << "merge " << KV(l) << KV(r) << KV(a) << KV(b) << KV(c) <<
    // KV(merged) << KV(v) << std::endl;
    if (!merged) {
      basis.add(v);
    }
  }
  if (l == r) {
    auto [a, b] = queries[l];
    int v = root(a).second ^ root(b).second;
    // std::cout << KV(l) << KV(v) << KV(basis) << std::endl;
    result[l] = basis.ask(v);
  } else {
    int m = (l + r) >> 1;
    solve(l, m, basis);
    solve(m + 1, r, basis);
  }
  while (history.size() > checkpoint) {
    auto [x, y] = history.back();
    history.pop_back();
    size[x] -= size[y];
    parent[y] = y;
    delta[y] = 0;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  {
    int m;
    scanf("%d", &m);
    std::map<Edge, std::pair<int, int>> edge_map;
    for (int i = 0, a, b, c; i < m; ++i) {
      scanf("%d%d%d", &a, &b, &c);
      edge_map[{a - 1, b - 1}] = {c, 0};
    }
    int q;
    scanf("%d", &q);
    while (q--) {
      int op, x, y;
      scanf("%d%d%d", &op, &x, &y);
      x--;
      y--;
      if (op == 1) {
        int z;
        scanf("%d", &z);
        edge_map[{x, y}] = {z, queries.size()};
      } else if (op == 2) {
        auto iterator = edge_map.find({x, y});
        auto [z, begin] = iterator->second;
        if (begin < queries.size()) {
          ranges.emplace_back(x, y, z, begin, queries.size() - 1);
        }
        edge_map.erase(iterator);
      } else {
        queries.emplace_back(x, y);
      }
    }
    for (auto iterator : edge_map) {
      auto [x, y] = iterator.first;
      auto [z, begin] = iterator.second;
      if (begin < queries.size()) {
        ranges.emplace_back(x, y, z, begin, queries.size() - 1);
      }
    }
  }
  //   std::cout << KV(ranges) << std::endl;
  int q = queries.size();
  for (auto [x, y, z, begin, end] : ranges) {
    insert(0, q - 1, begin, end, Edge3{x, y, z});
  }
  std::fill(size, size + n, 1);
  std::iota(parent, parent + n, 0);
  solve(0, q - 1, LinearBasis{});
  for (int i = 0; i < q; ++i) {
    printf("%d\n", result[i]);
  }
}