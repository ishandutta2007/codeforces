#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream& in, std::ostream& out) {
    int t;
    in >> t;
    for (int test = 0; test < t; test++) {
        int n;
        in >> n;
        std::vector<int> as(n);
        for (int i = 0; i < n; i++) {
            in >> as[i];
        }
        if (std::is_sorted(as.begin(), as.end())) {
            out << 0 << "\n";
            continue;
        }
        if (as.front() == 1 || as.back() == n) {
            out << 1 << "\n";
            continue;
        }
        if (as.front() == n && as.back() == 1) {
            out << 3 << "\n";
            continue;
        }
        out << 2 << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}