#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
    int n, k;
    in >> n >> k;
    std::string t;
    in >> t;
    int len = n - 1;
    for (;len > 0; len--) {
        if (t.substr(0, len) == t.substr(n - len)) {
            break;
        }
    }
    std::string u = t.substr(len);
    for (int i = 0; i < k - 1; i++) {
        t.append(u);
    }
    out << t << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}