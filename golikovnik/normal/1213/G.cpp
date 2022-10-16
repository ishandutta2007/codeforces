#include <bits/stdc++.h>

int main() {
  std::size_t n, m;
  std::cin >> n >> m;
  struct edge {
    std::size_t from, to;
    unsigned weight;
  };
  std::vector<edge> edges(n - 1);
  for (auto& [from, to, weight] : edges) {
    std::cin >> from >> to >> weight;
    --from;
    --to;
  }
  std::sort(edges.begin(), edges.end(), [](edge const& a, edge const& b) {
    return a.weight < b.weight;
  });
  std::vector<unsigned> q(m);
  for (auto& x : q) {
    std::cin >> x;
  }
  std::vector<std::size_t> order_q(m);
  std::iota(order_q.begin(), order_q.end(), 0u);
  std::sort(order_q.begin(), order_q.end(), [&q](auto i, auto j) {
    return q[i] < q[j];
  });
  std::vector<std::size_t> p(n), sz(n);
  std::iota(p.begin(), p.end(), 0u);
  std::fill(sz.begin(), sz.end(), 1u);
  std::function<std::size_t(std::size_t)> get = [&p, &get](std::size_t u) {
    return p[u] == u ? u : p[u] = get(p[u]);
  };
  auto binom = [](std::size_t x) {
    return static_cast<std::uint64_t>(x) * (x - 1) / 2;
  };
  std::uint64_t answer = 0;
  std::size_t i = 0;
  auto add_edge = [&p, &sz, &answer, &get, &binom](edge const& e) {
    auto[from, to, w] = e;
    auto p_from = get(from);
    auto p_to = get(to);
    if (p_from == p_to) {
      return;
    }
    answer -= binom(sz[p_from]);
    answer -= binom(sz[p_to]);
    p[p_from] = p_to;
    sz[p_to] += sz[p_from];
    answer += binom(sz[p_to]);
  };
  std::vector<std::uint64_t> q_ans(m);
  for (std::size_t j = 0; j != m; ++j) {
    while (i != n - 1 && edges[i].weight <= q[order_q[j]]) {
      add_edge(edges[i]);
      ++i;
    }
    q_ans[order_q[j]] = answer;
  }
  for (auto x : q_ans) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
  return 0;
}