#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
    int n;
    int64_t m;
    in >> n >> m;
    int64_t sum = 0;
    int64_t cur = 0;
    for (int i = 0; i < n; i++) {
        int64_t a;
        in >> a;
        sum += a;
        int64_t page = sum / m;
        out << (page - cur) << " ";
        cur = page;
    }
    out << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}