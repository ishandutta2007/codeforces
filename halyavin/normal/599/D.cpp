#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>

void run(std::istream &in, std::ostream &out) {
  int64_t x;
  in >> x;
  x *= 6;
  std::vector<std::pair<int64_t, int64_t>> solutions;
  for (int64_t n = 1; ; n++) {
    int64_t z = x / n / (n + 1);
    if (z < 2 * n + 1) {
      break;
    }
    if (x % (n * (n + 1)) != 0) {
      continue;
    }
    z -= 2 * n + 1;
    if (z % 3 != 0) {
      continue;
    }
    int64_t s = z / 3;
    solutions.emplace_back(n, n + s);
    if (s != 0) {
      solutions.emplace_back(n + s, n);
    }
  }
  std::sort(solutions.begin(), solutions.end());
  out << solutions.size() << std::endl;
  for (size_t i = 0; i < solutions.size(); i++) {
    out << solutions[i].first << " " << solutions[i].second << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}