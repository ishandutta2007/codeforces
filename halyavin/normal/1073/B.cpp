#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::vector<int> as(n);
    std::vector<int> invAs(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
        as[i]--;
        invAs[as[i]] = i;
    }
    int cur = -1;
    for (int i = 0; i < n; i++) {
        int b;
        in >> b;
        b--;
        if (invAs[b] > cur) {
            out << (invAs[b] - cur) << " ";
            cur = invAs[b];
        } else {
            out << "0 ";
        }
    }
    out << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}