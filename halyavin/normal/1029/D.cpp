#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

struct Solution {
    int n, k;
    std::vector<std::vector<int>> as;
    std::vector<int> pows;

    int64_t calcPair(int ind1, int ind2) {
        std::vector<int> left;
        left.reserve(as[ind1].size());
        for (int v : as[ind1]) {
            left.push_back((int64_t(k - v) * pows[ind2 + 1]) % k);
        }
        std::sort(left.begin(), left.end());
        int64_t result = 0;
        size_t i1 = 0;
        size_t j1 = 0;
        std::vector<int>& right = as[ind2];
        while (i1 < left.size() && j1 < right.size()) {
            if (left[i1] < right[j1]) {
                i1++;
                continue;
            }
            if (left[i1] > right[j1]) {
                j1++;
                continue;
            }
            size_t i2 = i1;
            while (i2 < left.size() && left[i2] == left[i1]) i2++;
            size_t j2 = j1;
            while (j2 < right.size() && right[j2] == right[j1]) j2++;
            result += (i2 - i1) * int64_t(j2 - j1);
            i1 = i2;
            j1 = j2;
        }
        if (ind1 == ind2) {
            for (int v : right) {
                if ((v + int64_t(v) * pows[ind2 + 1]) % k == 0) {
                    result--;
                }
            }
        }
        return result;
    }

    void run(std::istream& in, std::ostream& out) {
        in >> n >> k;
        as.assign(10, std::vector<int>());
        pows.resize(11);
        pows[0] = 1;
        for (int i = 1; i <= 10; i++) {
            pows[i] = (pows[i - 1] * int64_t(10)) % k;
        }
        for (int i = 0; i < n; i++) {
            int a;
            in >> a;
            int aa = a % k;
            int len = 1;
            while (a >= 10) {
                a /= 10;
                len++;
            }
            as[len - 1].push_back(aa);
        }
        for (size_t i = 0; i < as.size(); i++) {
            std::sort(as[i].begin(), as[i].end());
        }
        int64_t ans = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                ans += calcPair(i, j);
            }
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