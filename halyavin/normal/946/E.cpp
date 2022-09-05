#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <array>

void run(std::istream& in, std::ostream& out) {
    int t;
    in >> t;
    for (int test = 0; test < t; test++) {
        std::string s;
        in >> s;
        std::vector<int> digits(s.length());
        for (size_t i = 0; i < s.length(); i++) {
            digits[i] = s[i] - '0';
        }
        std::reverse(digits.begin(), digits.end());
        for (size_t i = 0; i < digits.size(); i++) {
            if (digits[i] > 0) {
                digits[i]--;
                break;
            }
            digits[i] = 9;
        }
        if (digits.back() == 0) {
            digits.resize(digits.size() - 1);
        }
        if (digits.size() % 2 == 1) {
            out << std::string(digits.size() - 1, '9') << "\n";
            continue;
        }
        if (std::accumulate(digits.begin(), digits.end(), 0) == 1) {
            out << std::string(digits.size() - 2, '9') << "\n";
            continue;
        }
        std::array<int, 10> stats = {};
        for (int d : digits) {
            stats[d]++;
        }
        bool even = true;
        for (int st : stats) {
            if (st % 2) {
                even = false;
            }
        }
        int pos = digits.size();
        int posD = 10;
        if (even) {
            pos = 0;
            posD = digits[0];
        } else {
            std::array<int, 10> oddDigits = {};
            for (size_t cur = digits.size(); cur-- > 0;) {
                stats[digits[cur]]--;
                for (int d = digits[cur] - 1; d >= 0; d--) {
                    oddDigits[d] = oddDigits[d] ^ 1;
                    int count = std::accumulate(oddDigits.begin(), oddDigits.end(), 0);
                    if (count <= cur) {
                        pos = cur;
                        posD = d;
                        oddDigits[d] = oddDigits[d] ^ 1;
                        break;
                    }
                    oddDigits[d] = oddDigits[d] ^ 1;
                }
                oddDigits[digits[cur]] = oddDigits[digits[cur]] ^ 1;
            }
        }
        digits[pos] = posD;
        std::array<int, 10> oddDigits = {};
        for (size_t i = pos; i < digits.size(); i++) {
            oddDigits[digits[i]] = oddDigits[digits[i]] ^ 1;
        }
        int idx = 0;
        for (int i = 0; i < 10; i++) {
            if (oddDigits[i]) {
                digits[idx] = i;
                idx++;
            }
        }
        std::fill(digits.begin() + idx, digits.begin() + pos, 9);
        std::string ans(digits.size(), '0');
        for (size_t i = 0; i < digits.size(); i++) {
            ans[i] = (char)('0' + digits[i]);
        }
        std::reverse(ans.begin(), ans.end());
        out << ans << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}