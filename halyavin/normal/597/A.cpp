#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>

int64_t mathDiv(int64_t x, int64_t k) {
  if (x >= 0) {
    return x / k;
  }
  int64_t res = x / k;
  if (x % k != 0) {
    res--;
  }
  return res;
}

void run(std::istream &in, std::ostream &out) {
  int64_t k, a, b;
  in >> k >> a >> b;
  out << (mathDiv(b, k) - mathDiv(a-1, k)) << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}