#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

template <typename CommutativeSemigroup, typename E, typename F, typename G>
std::vector<CommutativeSemigroup> rerooting_dp(
    const std::vector<std::vector<int>>& graph,
    const std::vector<CommutativeSemigroup>& def,
    const E merge, const F f, const G g) {
  const int n = graph.size();
  if (n == 0) return {};
  if (n == 1) return def;
  std::vector<std::vector<CommutativeSemigroup>> children(n);
  const std::function<CommutativeSemigroup(const int, const int)> dfs1 =
      [&graph, &def, merge, f, g, &children, &dfs1](
          const int par, const int ver) -> CommutativeSemigroup {
        children[ver].reserve(graph[ver].size());
        CommutativeSemigroup dp = def[ver];
        for (const int e : graph[ver]) {
          if (e == par) {
            children[ver].emplace_back();
          } else {
            children[ver].emplace_back(f(dfs1(ver, e), ver, e));
            dp = merge(dp, children[ver].back());
          }
        }
        return g(dp, ver);
      };
  dfs1(-1, 0);
  std::vector<CommutativeSemigroup> dp = def;
  const std::function<void(const int, const int,
                           const CommutativeSemigroup&)> dfs2 =
      [&graph, &def, merge, f, g, &children, &dp, &dfs2](
          const int par, const int ver, const CommutativeSemigroup& m) -> void {
        const int c = graph[ver].size();
        for (int i = 0; i < c; ++i) {
          if (graph[ver][i] == par) {
            children[ver][i] = f(m, ver, graph[ver][i]);
            break;
          }
        }
        std::vector<CommutativeSemigroup> left{def[ver]}, right;
        left.reserve(c);
        for (int i = 0; i < c - 1; ++i) {
          left.emplace_back(merge(left[i], children[ver][i]));
        }
        dp[ver] = g(merge(left.back(), children[ver].back()), ver);
        if (c >= 2) {
          right.reserve(c - 1);
          right.emplace_back(children[ver].back());
          for (int i = c - 2; i > 0; --i) {
            right.emplace_back(merge(children[ver][i], right[c - 2 - i]));
          }
          std::reverse(right.begin(), right.end());
        }
        for (int i = 0; i < c; ++i) {
          if (graph[ver][i] != par) {
            dfs2(ver, graph[ver][i],
                 g(i + 1 == c ? left[i] : merge(left[i], right[i]), ver));
          }
        }
      };
  dfs2(-1, 0, CommutativeSemigroup());
  return dp;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    if (a[i] == 0) a[i] = -1;
  }
  std::vector<std::vector<int>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  const std::vector<int> ans = rerooting_dp(
      graph, a,
      [](const int x, const int y) -> int { return x + y; },
      [](const int x, const int src, const int dst) -> int {
        return std::max(x, 0);
      },
      [](const int x, const int ver) -> int { return x; });
  for (int i = 0; i < n; ++i) {
    std::cout << ans[i] << " \n"[i + 1 == n];
  }
  return 0;
}