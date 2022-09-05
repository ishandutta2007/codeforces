#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

template<class T>
T gcd(T x, T y) {
    while (y != T()) {
        T t = y;
        y = x % y;
        x = t;
    }
    return x;
}

void run(std::istream &in, std::ostream &out) {
    int n, m;
    in >> n >> m;
    std::vector<int64_t> xs(n);
    std::vector<int64_t> ps(m);
    for (int i = 0; i < n; i++) {
        in >> xs[i];
    }
    for (int j = 0; j < m; j++) {
        in >> ps[j];
    }
    int64_t g = xs[1] - xs[0];
    for (int i = 2; i < n; i++) {
        g = gcd(g, xs[i] - xs[i - 1]);
    }
    for (int j = 0; j < m; j++) {
        if (g % ps[j] == 0) {
            out << "YES\n";
            out << xs[0] << " " << (j + 1) << "\n";
            return;
        }
    }
    out << "NO\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}