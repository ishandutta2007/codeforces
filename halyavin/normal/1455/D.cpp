#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
    int t;
    in >> t;
    for (int test = 0; test < t; test++) {
        int n, x;
        in >> n >> x;
        std::vector<int> as(n);
        for (int i = 0; i < n; i++) {
            in >> as[i];
        }
        std::vector<bool> sorted(n);
        sorted[n - 1] = true;
        for (int i = n - 2; i >= 0; i--) {
            if (as[i] <= as[i + 1]) {
                sorted[i] = sorted[i + 1];
            } else {
                sorted[i] = false;
            }
        }
        bool good = true;
        int op = 0;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            if (as[i] <= x) {
                if (as[i] < prev) {
                    good = false;
                    break;
                }
            } else {
                if (sorted[i]) {
                    break;
                }
                std::swap(x, as[i]);
                op++;
            }
            prev = as[i];
        }
        if (!good) {
            out << -1 << "\n";
        } else {
            out << op << "\n";
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}