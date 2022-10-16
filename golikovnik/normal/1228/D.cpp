#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  std::cin >> n >> m;

  std::vector<int> p(n);
  std::iota(p.begin(), p.end(), 0);
  std::function<int(int)> get = [&](int v) {
    return p[v] == v ? v : p[v] = get(p[v]);
  };
  auto merge = [&](int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v) {
      return false;
    }
    p[u] = v;
    return true;
  };
  int k = n;
  std::vector<std::set<int>> graph(n);
  std::vector<std::pair<int, int>> e(m);
  for (int i = 0; i != m; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u, --v;
    if (merge(u, v)) {
      --k;
    }
    graph[u].insert(v);
    graph[v].insert(u);
    e[i] = {u, v};
  }
  if (k != 1) {
    std::cout << "-1\n";
    return 0;
  }
  std::vector<int> mark(n, -1);
  std::vector<std::uint64_t> cnt(3);
  int color = 0;
  for (int i = 0; i != n; ++i) {
    if (mark[i] < 0) {
      if (color == 3) {
        std::cout << "-1\n";
        return 0;
      }
      for (int v = 0; v != n; ++v) {
        if (graph[i].count(v)) {
          continue;
        }
        if (mark[v] >= 0) {
          std::cout << "-1\n";
          return 0;
        }
        mark[v] = color;
        ++cnt[color];
      }
      ++color;
    }
  }
  if (color != 3) {
    std::cout << "-1\n";
    return 0;
  }
  std::uint64_t desired = cnt[0] * cnt[1] + cnt[0] * cnt[2] + cnt[1] * cnt[2];
  if (desired != m) {
    std::cout << "-1\n";
    return 0;
  }
  for (auto [u, v] : e) {
    if (mark[u] == mark[v]) {
      std::cout << "-1\n";
      return 0;
    }
  }
  for (auto c : mark) {
    std::cout << c + 1 << ' ';
  }
  std::cout << '\n';
  return 0;
}