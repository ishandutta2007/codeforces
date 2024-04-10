#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

void run(std::istream &in, std::ostream &out) {
  int d1, d2, d3;
  in >> d1 >> d2 >> d3;
  out << std::min(d1 + d2 + std::min(d1 + d2, d3), (std::min(d1, d2) + d3) * 2) << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}