#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
    int64_t n, m, a, b;
    in >> n >> m >> a >> b;
    if (n % m == 0) {
        out << 0 << "\n";
        return;
    }
    int64_t r = n % m;
    out << std::min(r * b, (m - r) * a) << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}