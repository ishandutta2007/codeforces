#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdint>

void run(std::istream &in, std::ostream &out) {
    int64_t n;
    in >> n;
    int64_t even = 1;
    int64_t odd = 1 + (n * int64_t(n) + 1) / 2;
    int q;
    in >> q;
    for (int test = 0; test < q; test++) {
        int64_t x, y;
        in >> x >> y;
        x--;y--;
        int64_t res = 0;
        if ((x + y) % 2 == 0) {
            res = even;
            res += (x / 2) * int64_t(n);
            if (x % 2 != 0) {
                res += (n + 1) / 2;
            }
            res += y / 2;

        } else {
            res = odd;
            res += (x / 2) * int64_t(n);
            if (x % 2 != 0) {
                res += n / 2;
            }
            res += y / 2;
        }
        out << res << "\n";
    }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}