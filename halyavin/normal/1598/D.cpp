#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream& in, std::ostream& out) {
    int tests;
    in >> tests;
    for (int test = 0; test < tests; test++) {
        int n;
        in >> n;
        std::vector<int> statsV(n);
        std::vector<int> statsH(n);
        std::vector<std::pair<int, int>> points(n);
        for (int i = 0; i < n; i++) {
            in >> points[i].first >> points[i].second;
            points[i].first--;
            points[i].second--;
            statsV[points[i].first]++;
            statsH[points[i].second]++;
        }
        int64_t answer = int64_t(n) * int64_t(n - 1) * int64_t(n - 2) / 6;
        for (const auto& point : points) {
            answer -= int64_t(statsV[point.first] - 1) * int64_t(statsH[point.second] - 1);
        }
        out << answer << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}