#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <cstdlib>
#include <cmath>

void run(std::istream& in, std::ostream& out) {
    int q;
    in >> q;
    for (int test = 0; test < q; test++) {
        int64_t n, m, k;
        in >> n >> m >> k;
        if (k < std::max(std::abs(n), std::abs(m))) {
            out << -1 << "\n";
            continue;
        }
        int64_t n1 = n & 1;
        int64_t m1 = m & 1;
        int64_t k1 = k & 1;
        if (n1 == k1 && m1 == k1) {
            out << k << "\n";
        } else if (n1 != k1 && m1 != k1){
            out << k - 2 << "\n";
        } else {
            out << k - 1 << "\n";
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}