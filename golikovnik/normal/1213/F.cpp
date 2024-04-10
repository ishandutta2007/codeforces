#include <bits/stdc++.h>

int main() {
  std::size_t n, k;
  std::cin >> n >> k;
  std::vector<std::size_t> p(n), q(n);
  for (auto& x : p) {
    std::cin >> x;
    --x;
  }
  for (auto& x : q) {
    std::cin >> x;
    --x;
  }
  std::vector<std::vector<std::size_t>> graph(n), rgraph(n);
  for (std::size_t i = 0; i != n - 1; ++i) {
    graph[p[i]].push_back(p[i + 1]);
    graph[q[i]].push_back(q[i + 1]);
    rgraph[p[i + 1]].push_back(p[i]);
    rgraph[q[i + 1]].push_back(q[i]);
  }
  std::vector<bool> used(n);
  std::vector<std::size_t> ts;
  std::function<void(std::size_t)> dfs = [&graph, &dfs, &used, &ts](auto v) {
    if (used[v]) {
      return;
    }
    used[v] = true;
    for (auto u : graph[v]) {
      dfs(u);
    }
    ts.push_back(v);
  };
  for (std::size_t i = 0; i != n; ++i) {
    dfs(i);
  }
  std::reverse(ts.begin(), ts.end());
  std::fill(used.begin(), used.end(), false);
  std::vector<std::vector<std::size_t>> components;
  std::vector<std::size_t> comp_id(n);
  std::function<void(std::size_t)> dfs2 = [&components, &used, &rgraph,
                                           &dfs2, &comp_id]
          (auto v) {
    used[v] = true;
    components.back().push_back(v);
    comp_id[v] = components.size() - 1;
    for (auto u : rgraph[v]) {
      if (used[u]) {
        continue;
      }
      dfs2(u);
    }
  };
  for (auto v : ts) {
    if (!used[v]) {
      components.emplace_back();
      dfs2(v);
    }
  }
  auto ncomps = components.size();
  if (ncomps < k) {
    std::cout << "NO\n";
    return 0;
  }
  std::cout << "YES\n";
  std::vector<std::vector<std::size_t>> comp_graph(ncomps);
  for (std::size_t v = 0; v != n; ++v) {
    for (auto u : graph[v]) {
      comp_graph[comp_id[v]].push_back(comp_id[u]);
    }
  }
  std::fill(used.begin(), used.end(), false);
  ts.clear();
  std::function<void(std::size_t)> dfs3 = [&comp_graph, &ts, &used, &dfs3](
          auto v) {
    if (used[v]) {
      return;
    }
    used[v] = true;
    for (auto u : comp_graph[v]) {
      dfs3(u);
    }
    ts.push_back(v);
  };
  for (std::size_t i = 0; i != ncomps; ++i) {
    dfs3(i);
  }
  std::reverse(ts.begin(), ts.end());
  std::string answer(n, '?');
  for (std::size_t i = 0; i != ncomps; ++i) {
    auto ch = static_cast<char>('a' + std::min<std::size_t>(i, 25));
    for (auto j : components[ts[i]]) {
      answer[j] = ch;
    }
  }
  std::cout << answer << '\n';
  return 0;
}