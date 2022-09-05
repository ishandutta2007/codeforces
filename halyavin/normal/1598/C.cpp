#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <numeric>

void run(std::istream& in, std::ostream& out) {
    int tests;
    in >> tests;
    for (int test = 0; test < tests; test++) {
        int n;
        in >> n;
        std::vector<int64_t> as(n);
        for (int i = 0; i < n; i++) {
            in >> as[i];
        }
        int64_t sum = std::accumulate(as.begin(), as.end(), int64_t(0));
        if ((2 * sum) % n != 0) {
            out << 0 << "\n";
            continue;
        }
        int64_t diff = (2 * sum) / n;
        std::sort(as.begin(), as.end());
        std::vector<std::pair<int64_t, int>> grouped;
        grouped.emplace_back(as[0], 1);
        for (int i = 1; i < n; i++) {
            if (as[i] == as[i - 1]) {
                grouped.back().second++;
            } else {
                grouped.emplace_back(as[i], 1);
            }
        }
        int left = 0;
        int right = grouped.size() - 1;
        int64_t answer = 0;
        while (left < right) {
            int64_t sum = grouped[left].first + grouped[right].first;
            if (sum > diff) {
                right--;
            } else if (sum < diff) {
                left++;
            } else {
                answer += grouped[left].second * (int64_t)grouped[right].second;
                left++;
                right--;
            }
        }
        if (left == right && grouped[left].first * 2 == diff) {
            answer += (grouped[left].second * int64_t(grouped[left].second - 1)) / 2;
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