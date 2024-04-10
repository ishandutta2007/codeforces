#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
    int n, m;
    in >> n >> m;
    std::vector<uint32_t> as(n);
    std::vector<uint32_t> bs(m);
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    for (int i = 0; i < m; i++) {
        in >> bs[i];
    }
    uint32_t xorA = 0;
    for (int i = 0; i < n; i++) {
        xorA ^= as[i];
    }
    uint32_t xorB = 0;
    for (int i = 0; i < m; i++) {
        xorB ^= bs[i];
    }
    if (xorA != xorB) {
        out << "NO\n";
        return;
    }
    out << "YES\n";
    out << (xorB ^ bs[0] ^ as[0]) << " ";
    for (int i = 1; i < m; i++) {
        out << bs[i] << " ";
    }
    out << "\n";
    for (int i = 1; i < n; i++) {
        out << as[i] << " ";
        for (int j = 1; j < m; j++) {
            out << 0 << " ";
        }
        out << "\n";
    }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}