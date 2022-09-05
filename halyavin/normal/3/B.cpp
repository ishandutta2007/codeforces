#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

void run2(std::istream &in, std::ostream &out) {
    int n, volume;
    in >> n >> volume;
    std::vector<std::pair<int, int>> type1;
    std::vector<std::pair<int, int>> type2;
    for (int i = 0; i < n; i++) {
        int type, size;
        in >> type >> size;
        if (type == 1) {
            type1.emplace_back(size, i + 1);
        } else {
            type2.emplace_back(size, i + 1);
        }
    }
    std::sort(type1.begin(), type1.end(), std::greater<std::pair<int, int>>());
    std::sort(type2.begin(), type2.end(), std::greater<std::pair<int, int>>());
    std::vector<int> type1Sizes{0};
    std::vector<int> type2Sizes{0};
    std::transform(type1.begin(), type1.end(), std::back_inserter(type1Sizes),
            [](const std::pair<int, int> &boat) {
                return boat.first;
            });
    std::transform(type2.begin(), type2.end(), std::back_inserter(type2Sizes),
            [](const std::pair<int, int> &boat) {
                return boat.first;
            });
    std::partial_sum(type1Sizes.begin(), type1Sizes.end(), type1Sizes.begin());
    std::partial_sum(type2Sizes.begin(), type2Sizes.end(), type2Sizes.begin());
    int max = -1;
    int opt1 = 0;
    int opt2 = 0;
    for (int i2 = 0; i2 <= (int) type2.size() && 2 * i2 <= volume; i2++) {
        int i1 = std::min(volume - 2 * i2, (int) type1.size());
        int sum = type1Sizes[i1] + type2Sizes[i2];
        if (sum > max) {
            max = sum;
            opt1 = i1;
            opt2 = i2;
        }
    }
    out << max << std::endl;
    for (int i = 0; i < opt1; i++) {
        out << type1[i].second << std::endl;
    }
    for (int i = 0; i < opt2; i++) {
        out << type2[i].second << std::endl;
    }
}

int main() {
    run2(std::cin, std::cout);
    return 0;
}