#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <cmath>

void run(std::istream& in, std::ostream& out) {
    int n;
    in >> n;
    std::vector<int> as(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    std::vector<int> ones;
    std::vector<int> zeros;
    for (int i = 0; i < n; i++) {
        if (as[i] == 1) {
            ones.push_back(i);
        } else {
            zeros.push_back(i);
        }
    }
    if (ones.empty()) {
        out << "0\n";
        return;
    }
    std::vector<std::vector<int>> dyn(ones.size(), std::vector<int>(zeros.size(), 1000000000));
    for (int i = 0; i < zeros.size(); i++) {
        dyn[0][i] = std::abs(ones[0] - zeros[i]);
    }
    for (int i = 1; i < ones.size(); i++) {
        int min_before = 1000000000;
        for (int j = i; j < zeros.size(); j++) {
            min_before = std::min(min_before, dyn[i - 1][j - 1]);
            dyn[i][j] = std::abs(ones[i] - zeros[j]) + min_before;
        }
    }
    out << *std::min_element(dyn.back().begin(), dyn.back().end()) << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}