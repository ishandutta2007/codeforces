#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

struct Solution {
    int n, x;
    std::vector<int> as;
    std::vector<std::vector<int>> inv;
    std::vector<int> left;
    std::vector<int> right;

    void run(std::istream &in, std::ostream &out) {
        in >> n >> x;
        as.resize(n);
        for (int i = 0; i < n; i++) {
            in >> as[i];
        }
        inv.assign(x + 1, std::vector<int>());
        for (int i = 0; i < n; i++) {
            inv[as[i]].push_back(i);
        }
        left.resize(x + 2);
        int prev = -1;
        left[0] = -1;
        for (int i = 1; i <= x; i++) {
            if (!inv[i].empty()) {
                if (inv[i].front() < prev) {
                    prev = n;
                } else {
                    prev = inv[i].back();
                }
            }
            left[i] = prev;
        }
        left[x + 1] = n;
        right.resize(x + 2);
        prev = n;
        right[x + 1] = n;
        for (int i = x; i >= 1; i--) {
            if (!inv[i].empty()) {
                if (inv[i].back() > prev) {
                    prev = -1;
                } else {
                    prev = inv[i].front();
                }
            }
            right[i] = prev;
        }
        right[0] = -1;
        /*for (int i = 0; i <= x + 1; i++) {
            std::cerr << left[i] << " ";
        }
        std::cerr << "\n";
        for (int i = 0; i <= x + 1; i++) {
            std::cerr << right[i] << " ";
        }
        std::cerr << "\n";*/
        int64_t ans = 0;
        int r = 1;
        for (int l = 1; l <= x; l++) {
            if (left[l - 1] == n) {
                break;
            }
            r = std::max(r, l);
            while (r <= x && right[r + 1] <= left[l - 1]) r++;
            //std::cerr << l << " " << r << " " << x - r + 1 << "\n";
            ans += x - r + 1;
        }
        out << ans << "\n";
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}