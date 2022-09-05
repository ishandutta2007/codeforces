#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <map>

void run(std::istream &in, std::ostream &out) {
    int T;
    in >> T;
    for (int test = 0; test < T; test++) {
        int n;
        in >> n;
        std::vector<int> sticks(n);
        for (int i = 0; i < n; i++) {
            in >> sticks[i];
        }
        std::map<int, int> stickCounts;
        for (int i = 0; i < n; i++) {
            stickCounts[sticks[i]]++;
        }
        int good = -1;
        std::vector<int> lengths;
        for (const auto& entry : stickCounts) {
            if (entry.second >= 4) {
                good = entry.first;
            }
            if (entry.second >= 2) {
                lengths.push_back(entry.first);
            }
        }
        if (good > 0) {
            out << good << " " << good << " " << good << " " << good << "\n";
            continue;
        }
        int64_t optP = int64_t(1) << 30;
        int64_t optQ = 1;
        int optA = 0;
        int optB = 0;
        for (size_t i = 0; i + 1 < lengths.size(); i++) {
            int64_t p = int64_t(lengths[i] + lengths[i + 1]) * int64_t(lengths[i] + lengths[i + 1]);
            int64_t q = lengths[i] * lengths[i + 1];
            if (p * optQ < optP * q) {
                optP = p;
                optQ = q;
                optA = lengths[i];
                optB = lengths[i + 1];
            }
        }
        out << optA << " " << optA << " " << optB << " " << optB << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}