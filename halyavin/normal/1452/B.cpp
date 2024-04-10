#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
    int t;
    in >> t;
    for (int test = 0; test < t; test++) {
        int n;
        in >> n;
        std::vector<int> as(n);
        for (int i = 0; i < n; i++) {
            in >> as[i];
        }
        int64_t sum = std::accumulate(as.begin(), as.end(), int64_t(0));
        int64_t maxValue = *std::max_element(as.begin(), as.end());
        if (sum >= (n - 1) * maxValue) {
            int rest = static_cast<int>(sum % (n - 1));
            if (rest != 0) {
                rest = (n - 1) - rest;
            }
            out << rest << "\n";
        } else {
            out << (n - 1) * maxValue - sum << "\n";
        }
    }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}