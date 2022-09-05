#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  int64_t ans = 0;
  int64_t prev = 0;
  for (int i = 0; i < n; i++) {
    int64_t b;
    in >> b;
    ans += abs(b - prev);
    prev = b;
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}