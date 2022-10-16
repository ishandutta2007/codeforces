#include <bits/stdc++.h>

int main() {
  unsigned n, m;
  std::cin >> n >> m;
  unsigned const MAX = 9;
  unsigned constexpr KINDS = 1u << MAX;
  std::vector<unsigned> like(KINDS);
  auto read_mask = []() {
    unsigned k;
    std::cin >> k;
    unsigned mask = 0;
    while (k--) {
      unsigned x;
      std::cin >> x;
      --x;
      mask |= (1u << x);
    }
    return mask;
  };
  for (std::size_t i = 0; i != n; ++i) {
    auto mask = read_mask();
    for (unsigned m = 0; m != KINDS; ++m) {
      if ((m & mask) == mask) {
        ++like[m];
      }
    }
  }
  std::vector<std::vector<std::pair<std::uint32_t, std::size_t>>> pizzas(KINDS);
  for (std::size_t i = 0; i != m; ++i) {
    std::uint32_t cost;
    std::cin >> cost;
    auto mask = read_mask();
    pizzas[mask].emplace_back(cost, i);
  }
  for (unsigned i = 0; i != KINDS; ++i) {
    std::sort(pizzas[i].begin(), pizzas[i].end());
  }
  std::tuple<std::size_t, std::uint32_t, std::size_t, std::size_t> answer{
    0, std::numeric_limits<std::uint32_t>::max(), 0, 0};
  for (unsigned first = 0; first != KINDS; ++first) {
    for (unsigned second = first; second != KINDS; ++second) {
      if (pizzas[first].empty() || pizzas[second].empty()) {
        continue;
      }
      if (first == second && pizzas[first].size() == 1) {
        continue;
      }
      auto[p_f, i_f] = pizzas[first][0];
      auto[p_s, i_s] = pizzas[second][first == second];
      auto match = like[first | second];
      auto cost = p_f + p_s;
      auto[match_ans, cost_ans, _, __] = answer;
      if (match > match_ans || match == match_ans && cost < cost_ans) {
        answer = std::make_tuple(match, cost, i_f, i_s);
      }
    }
  }
  std::cout << std::get<2>(answer) + 1 << ' ' << std::get<3>(answer) + 1 << '\n';
  return 0;
}