#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::vector<int64_t> bs(n / 2);
    std::vector<int64_t> as(n);
    for (int i = 0; i < n / 2; i++) {
        in >> bs[i];
    }
    int64_t left = 0;
    int64_t right = bs[0];
    for (int i = 0; i < n / 2; i++) {
        if (left + right > bs[i]) {
            right = bs[i] - left;
        } else {
            left = bs[i] - right;
        }
        as[i] = left;
        as[n - i - 1] = right;
    }
    for (int i = 0; i < n; i++) {
        out << as[i] << " ";
    }
    out << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}