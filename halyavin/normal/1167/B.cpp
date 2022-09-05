#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <array>
#include <numeric>

std::array<int, 6> nums = {{4, 8, 15, 16, 23, 42}};

void run(std::istream &in, std::ostream &out) {
    std::array<int, 4> prods;
    for (int i = 0; i < prods.size(); i++) {
        out << "? " << (i + 1) << " " << (i + 2) << "\n";
        out.flush();
        in >> prods[i];
    }
    for (int i = 0; i < 720; i++) {
        std::vector<int> perm(6);
        std::iota(perm.begin(), perm.end(), 0);
        int ci = i;
        for (int j = 2; j <= 6; j++) {
            int other = ci % j;
            ci /= j;
            if (other != j - 1) {
                std::swap(perm[other], perm[j - 1]);
            }
        }
        bool good = true;
        for (int j = 0; j < 4; j++) {
            if (prods[j] != nums[perm[j]] * nums[perm[j + 1]]) {
                good = false;
            }
        }
        if (good) {
            out << "!";
            for (int j = 0; j < 6; j++) {
                out << " " << nums[perm[j]];
            }
            out << "\n";
            out.flush();
            return;
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}