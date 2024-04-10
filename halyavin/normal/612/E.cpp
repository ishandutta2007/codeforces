#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

std::vector<int> findCycle(const std::vector<int>& p, std::vector<bool>& flags, int start) {
  std::vector<int> res = {start};
  flags[start] = true;
  int cur = p[start];
  while (cur != start) {
    flags[cur] = true;
    res.push_back(cur);
    cur = p[cur];
  }
  return res;
}

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<int> p(n);
  for (int i = 0; i < n; i++) {
    in >> p[i];
    p[i]--;
  }
  std::vector<std::vector<int>> cycles(n / 2 + 1);
  std::vector<bool> flags(n);
  std::vector<int> q(n);
  for (int i = 0; i < n; i++) {
    if (!flags[i]) {
      std::vector<int> cycle = findCycle(p, flags, i);
      if (cycle.size() % 2 != 0) {
        size_t size = cycle.size();
        size_t shift = (cycle.size()  + 1) / 2;
        for (size_t j = 0; j < cycle.size(); j++) {
          q[cycle[j]] = cycle[(j + shift) % size];
        }
      } else {
        size_t size = cycle.size() / 2;
        if (cycles[size].empty()) {
          cycles[size] = std::move(cycle);
        } else {
          std::vector<int>& other = cycles[size];
          for (size_t j = 0; j < cycle.size(); j++) {
            q[other[j]] = cycle[j];
            q[cycle[j]] = other[(j + 1) % cycle.size()];
          }
          cycles[size].clear();
        }
      }
    }
  }
  for (size_t i = 0; i < cycles.size(); i++) {
    if (!cycles[i].empty()) {
      out << "-1" << std::endl;
      return;
    }
  }
  for (int i = 0; i < n; i++) {
    out << (q[i] + 1) << " ";
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}