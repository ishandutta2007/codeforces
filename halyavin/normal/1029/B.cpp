#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void run(std::istream& in, std::ostream& out) {
    int n;
    in >> n;
    std::vector<int> as(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    size_t ans = 0;
    as.push_back(2000000001);
    size_t i1 = 0;
    for (size_t j1 = 1; j1 < as.size(); j1++) {
        if (as[j1] > 2 * as[j1 - 1]) {
            ans = std::max(ans, j1-i1);
            i1 = j1;
        }
    }
    out << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}