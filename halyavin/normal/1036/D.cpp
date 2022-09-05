#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <set>

void run(std::istream& in, std::ostream& out) {
    std::set<int64_t> as;
    int n;
    in >> n;
    int64_t sum = 0;
    for (int i = 0; i < n; i++) {
        int64_t x;
        in >> x;
        sum += x;
        as.insert(sum);
    }
    int m;
    in >> m;
    int common = 0;
    int64_t sum2 = 0;
    for (int i = 0; i < m; i++) {
        int64_t x;
        in >> x;
        sum2 += x;
        if (as.find(sum2) != as.end()) {
            common++;
        }
    }
    if (sum != sum2) {
        out << -1 << "\n";
    } else {
        out << common << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}