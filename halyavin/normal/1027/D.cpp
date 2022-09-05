#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::vector<int> perm(n);
    std::vector<int> originalPerm;
    std::vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        in >> cost[i];
    }
    for (int i = 0; i < n; i++) {
        in >> perm[i];
        perm[i]--;
    }
    originalPerm = perm;
    for (int iter = 0; iter < 20; iter++) {
        std::vector<int> perm2(n);
        for (int i = 0; i < n; i++) {
            perm2[i] = perm[perm[i]];
        }
        perm = perm2;
    }
    std::vector<bool> possible(n);
    for (int i =0 ; i < n; i++) {
        possible[perm[i]] = true;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!possible[i]) continue;
        int j = i;
        int value = cost[i];
        do {
            value = std::min(cost[j], value);
            possible[j] = false;
            j = originalPerm[j];
        } while (j != i);
        ans += value;
    }
    out << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}