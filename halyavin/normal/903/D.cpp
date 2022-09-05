#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <map>

void run(std::istream& in, std::ostream& out) {
    int n;
    in >> n;
    std::vector<int> as(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    std::map<int, int> counts;
    int64_t sum = 0;
    uint64_t pos = 0;
    uint64_t neg = 0;
    for (int i = n - 1; i >= 0; i--) {

        pos += sum;
        neg += int64_t(as[i]) * (n - i - 1);
        neg += counts[as[i] + 1];
        pos += counts[as[i] - 1];
        uint64_t d = std::min(pos, neg);
        pos -= d;
        neg -= d;
        counts[as[i]]++;
        sum += as[i];
    }
    if (pos >= neg) {
        out << pos - neg << "\n";
    } else {
        out << "-" << neg - pos << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}