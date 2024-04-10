#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
    int n, m;
    in >> n >> m;
    int64_t sumx = 0;
    int64_t sumd = 0;
    int64_t sumd2 = 0;
    for (int i = 0; i < m; i++) {
        int x, d;
        in >> x >> d;
        sumx += x;
        if (d > 0) {
            sumd += d;
        } else {
            sumd2 += d;
        }
    }
    double c;
    if (n % 2 == 1) {
        int64_t k = n / 2;
        c = (k * (k + 1)) / (double) n;
    } else {
        c = n / 4.0;
    }
    out.precision(10);
    out << ((2 * sumx + sumd * (n - 1)) / 2.0  + sumd2 * c) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}