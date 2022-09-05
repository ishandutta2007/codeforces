#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

std::pair<int, int> getMax2(const std::vector<int>& ls) {
    int max1 = ls[0];
    int max2 = ls[1];
    if (max1 < max2) {
        std::swap(max1, max2);
    }
    for (size_t i = 2; i < ls.size(); i++) {
        if (ls[i] > max1) {
            max2 = max1;
            max1 = ls[i];
        } else {
            max2 = std::max(max2, ls[i]);
        }
    }
    return {max1, max2};
}

void run(std::istream& in, std::ostream& out) {
    int n;
    in >> n;
    std::vector<int> ls(n);
    std::vector<int> rs(n);
    for (int i = 0; i < n; i++) {
        in >> ls[i] >> rs[i];
    }
    std::pair<int, int> lm = getMax2(ls);
    for (int i = 0; i < n; i++) {
        rs[i] = -rs[i];
    }
    std::pair<int, int> rm = getMax2(rs);
    rm.first = -rm.first;
    rm.second = -rm.second;
    for (int i = 0; i < n; i++) {
        rs[i] = -rs[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int left = (ls[i] == lm.first) ? lm.second : lm.first;
        int right = (rs[i] == rm.first) ? rm.second : rm.first;
        ans = std::max(ans, right - left);
    }
    out << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}