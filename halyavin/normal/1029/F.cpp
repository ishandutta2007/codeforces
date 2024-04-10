#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

std::vector<int64_t> divisors(int64_t x) {
    std::vector<int64_t> res;
    std::vector<int64_t> res1;
    for (int i = 1; i * int64_t(i) <= x; i++) {
        if (x % i == 0) {
            res.push_back(i);
            int64_t d = x / i;
            if (d != i) {
                res1.push_back(d);
            }
        }
    }
    if (!res1.empty()) {
        std::reverse(res1.begin(), res1.end());
        res.insert(res.end(), res1.begin(), res1.end());
    }
    return res;
}

int64_t getAns(const std::vector<int64_t>& divA, const std::vector<int64_t>& divAB, int64_t a, int64_t b) {
    int64_t ans = a + b + 1;
    for (int64_t d1 : divAB) {
        int64_t d2 = (a + b) / d1;
        auto it = std::upper_bound(divA.begin(), divA.end(), d1);
        int64_t d3 = *(--it);
        int64_t d4 = a / d3;
        if (d4 <= d2) {
            ans = std::min(ans, d1 + d2);
        }
    }
    return ans;
}

void run(std::istream& in, std::ostream& out) {
    int64_t a, b;
    in >> a >> b;
    std::vector<int64_t> divA, divB, divAB;
    divA = divisors(a);
    divB = divisors(b);
    divAB = divisors(a + b);
    int64_t ans = std::min(getAns(divA, divAB, a, b), getAns(divB, divAB, b, a));
    out << 2 * ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}