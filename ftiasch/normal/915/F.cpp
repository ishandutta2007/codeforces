#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1'000'000;

long long binom(int n) { return 1LL * n * (n - 1) / 2; }

int main() {
  int n;
  scanf("%d", &n);
  std::vector<std::pair<int, int>> order(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &order[i].first);
    order[i].second = i;
  }
  std::vector<std::vector<int>> tree(n);
  for (int i = 0, a, b; i < n - 1; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  std::sort(order.begin(), order.end());
  std::vector<int> parent(n), size(n);
  std::function<int(int)> find = [&](int u) -> int {
    if (parent[u] != u) {
      parent[u] = find(parent[u]);
    }
    return parent[u];
  };
  std::vector<bool> visited(n);
  long long result = 0;
  for (int _ = 0; _ < 2; ++_) {
    std::iota(parent.begin(), parent.end(), 0);
    std::fill(size.begin(), size.end(), 1);
    std::fill(visited.begin(), visited.end(), false);
    for (auto [_a, u] : order) {
      int a = _ ? -_a : _a;
      long long ways = 0;
      for (int v : tree[u]) {
        if (visited[v]) {
          int vv = find(v);
          ways -= binom(size[vv]);
          size[u] += size[vv];
          parent[vv] = u;
        }
      }
      ways += binom(size[u]);
      result += a * ways;
      visited[u] = true;
    }
    std::reverse(order.begin(), order.end());
  }
  printf("%lld\n", result);
}