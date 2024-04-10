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
    std::map<int, std::vector<int>> statIdx;
    for (int i = 0; i < n; i++) {
        int x;
        in >> x;
        statIdx[x].push_back(i);
    }
    int diff = 0;
    int diff2 = 0;
    for (const auto& entry : statIdx) {
        if (entry.second.size() == 2) {
            continue;
        }
        if (entry.second.size() == 1) {
            diff++;
        } else {
            diff2++;
        }
    }
    if (diff % 2 > diff2) {
        out << "NO\n";
        return;
    }
    diff2 = diff % 2;
    out << "YES\n";
    std::vector<bool> answer(n);
    for (const auto& entry : statIdx) {
        if (entry.second.size() == 2) {
            continue;
        }
        if (entry.second.size() == 1) {
            if (diff % 2 == 0) {
                answer[entry.second[0]] = true;
            }
            diff--;
        } else {
            if (diff2 != 0) {
                answer[entry.second[0]] = true;
                diff2--;
            }
        }

    }
    for (int i = 0; i < n; i++) {
        if (answer[i]) {
            out << "A";
        } else {
            out << "B";
        }
    }
    out << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}