#include <algorithm>
#include <iostream>
#include <map>
#include <tuple>
#include <utility>
#include <vector>

struct UndoableUnionFind {
  UndoableUnionFind(const int n) : data(n, -1) {}

  int root(const int ver) const {
    return data[ver] < 0 ? ver : root(data[ver]);
  }

  bool unite(int u, int v) {
    u = root(u);
    history.emplace_back(u, data[u]);
    v = root(v);
    history.emplace_back(v, data[v]);
    if (u == v) return false;
    if (data[u] > data[v]) {
      std::swap(u, v);
    }
    data[u] += data[v];
    data[v] = u;
    return true;
  }

  bool is_same(const int u, const int v) const {
    return root(u) == root(v);
  }

  int size(const int ver) const {
    return -data[root(ver)];
  }

  void undo() {
    for (int i = 0; i < 2; ++i) {
      data[history.back().first] = history.back().second;
      history.pop_back();
    }
  }

  void snapshot() {
    history.clear();
  }

  void rollback() {
    while (!history.empty()) {
      undo();
    }
  }

private:
  std::vector<int> data;
  std::vector<std::pair<int, int>> history;
};

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> c[i];
    --c[i];
  }
  UndoableUnionFind union_find(n * 2);
  std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> edge;
  while (m--) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    if (c[a] == c[b]) {
      union_find.unite(a, b + n);
      union_find.unite(b, a + n);
    } else {
      if (c[a] > c[b]) {
        std::swap(a, b);
      }
      edge[{c[a], c[b]}].emplace_back(a, b);
    }
  }
  std::vector<int> is_bad(k, false);
  for (int i = 0; i < n; ++i) {
    if (union_find.is_same(i, i + n)) {
      is_bad[c[i]] = true;
    }
  }
  const int good_group_num = std::count(is_bad.begin(), is_bad.end(), false);
  long long ans = static_cast<long long>(good_group_num) * (good_group_num - 1) / 2;
  union_find.snapshot();
  for (const std::pair<std::pair<int, int>, std::vector<std::pair<int, int>>> &p : edge) {
    if (is_bad[p.first.first] || is_bad[p.first.second]) continue;
    bool is_bad = false;
    for (const std::pair<int, int> &e : p.second) {
      int a, b;
      std::tie(a, b) = e;
      union_find.unite(a, b + n);
      union_find.unite(b, a + n);
      is_bad |= union_find.is_same(a, a + n) || union_find.is_same(b, b + n);
    }
    union_find.rollback();
    ans -= is_bad;
  }
  std::cout << ans << '\n';
  return 0;
}