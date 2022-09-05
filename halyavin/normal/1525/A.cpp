#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

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
    int t;
    in >> t;
    for (int i = 0; i < t; i++) {
        int k;
        in >> k;
        out << 100 / (gcd(k, 100)) << "\n";
    }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}