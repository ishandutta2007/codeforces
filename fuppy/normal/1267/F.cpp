#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>

using usize = std::size_t;
using u64 = std::uint_fast64_t;
using u32 = std::uint_fast32_t;
using i32 = std::int_fast32_t;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  usize n, m;
  std::cin >> n >> m;
  usize ka, kb;
  std::cin >> ka >> kb;
  std::vector<usize> a(ka), b(kb);
  for (auto &e : a) {
    std::cin >> e;
  }
  std::reverse(a.begin(), a.end());
  for (auto &e : b) {
    std::cin >> e;
  }
  std::reverse(b.begin(), b.end());
  std::priority_queue<usize, std::vector<usize>, std::greater<usize>> leaf;
  std::vector<usize> deg(n + m + 1, 0);
  for (const auto e : a) {
    deg[e] += 1;
  }
  for (const auto e : b) {
    deg[e] += 1;
  }
  for (usize i = 1; i <= n + m; i += 1) {
    if (deg[i] == 0) {
      leaf.push(i);
    }
  }
  std::vector<std::pair<usize, usize>> edge;
  std::vector<usize> rem_a, rem_b;
  while (!leaf.empty()) {
    const usize v = leaf.top();
    leaf.pop();
    if (v <= n) {
      if (b.empty()) {
        rem_a.push_back(v);
        continue;
      }
      const usize u = b.back();
      edge.emplace_back(v, u);
      b.pop_back();
      deg[u] -= 1;
      if (deg[u] == 0) {
        leaf.push(u);
      }
    } else {
      if (a.empty()) {
        rem_b.push_back(v);
        continue;
      }
      const usize u = a.back();
      edge.emplace_back(v, u);
      a.pop_back();
      deg[u] -= 1;
      if (deg[u] == 0) {
        leaf.push(u);
      }
    }
  }
  if (!a.empty() || !b.empty()) {
    std::cout << "No\n";
    return 0;
  }
  if (rem_a.empty() != rem_b.empty()) {
    std::cout << "No\n";
    return 0;
  }
  if (!rem_a.empty()) {
    const usize va = rem_a.back();
    rem_a.pop_back();
    const usize vb = rem_b.back();
    rem_b.pop_back();
    edge.emplace_back(va, vb);
    for (const auto e : rem_a) {
      edge.emplace_back(vb, e);
    }
    for (const auto e : rem_b) {
      edge.emplace_back(va, e);
    }
  }
  std::cout << "Yes\n";
  for (const auto &e : edge) {
    std::cout << e.first << ' ' << e.second << '\n';
  }
  return 0;
}