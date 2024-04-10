#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

template <typename CostType>
struct Edge {
  int src, dst;
  CostType cost;
  explicit Edge(const int src, const int dst, const CostType cost = 0)
      : src(src), dst(dst), cost(cost) {}
  inline bool operator<(const Edge& x) const {
    if (cost != x.cost) return cost < x.cost;
    return src != x.src ? src < x.src : dst < x.dst;
  }
  inline bool operator<=(const Edge& x) const { return !(x < *this); }
  inline bool operator>(const Edge& x) const { return x < *this; }
  inline bool operator>=(const Edge& x) const { return !(*this < x); }
};

template <typename CostType, typename CommutativeSemigroup,
          typename E, typename F, typename G>
std::vector<CommutativeSemigroup> rerooting_dp(
    const std::vector<std::vector<Edge<CostType>>>& graph,
    const std::vector<CommutativeSemigroup>& def,
    const E merge, const F f, const G g) {
  const int n = graph.size();
  if (n == 0) return {};
  if (n == 1) return {g(def[0], 0)};
  std::vector<std::vector<CommutativeSemigroup>> children(n);
  const std::function<CommutativeSemigroup(const int, const int)> dfs1 =
      [&graph, &def, merge, f, g, &children, &dfs1](
          const int par, const int ver) -> CommutativeSemigroup {
        children[ver].reserve(graph[ver].size());
        CommutativeSemigroup dp = def[ver];
        for (const Edge<CostType>& e : graph[ver]) {
          if (e.dst == par) {
            children[ver].emplace_back();
          } else {
            children[ver].emplace_back(f(dfs1(ver, e.dst), e));
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
          if (graph[ver][i].dst == par) {
            children[ver][i] = f(m, graph[ver][i]);
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
          if (graph[ver][i].dst != par) {
            dfs2(ver, graph[ver][i].dst,
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
  std::vector<int> w(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> w[i];
  }
  std::vector<std::vector<Edge<int>>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, c;
    std::cin >> u >> v >> c;
    --u; --v;
    graph[u].emplace_back(u, v, c);
    graph[v].emplace_back(v, u, c);
  }
  const std::vector<long long> ans = rerooting_dp(
      graph, std::vector<long long>(n, 0),
      [](const long long x, const long long y) -> long long {
        return std::max(x, y);
      },
      [](const long long x, const Edge<int>& e) -> long long {
        return std::max(x - e.cost, 0LL);
      },
      [&w](const long long x, const int ver) -> long long {
        return x + w[ver];
      });
  std::cout << *std::max_element(ans.begin(), ans.end()) << '\n';
  return 0;
}