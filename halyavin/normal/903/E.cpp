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

struct Solution {
    int k, n;
    std::vector<std::string> as;
    std::vector<int> diff(const std::string& a, const std::string& b) {
        std::vector<int> res;
        res.reserve(4);
        for (size_t i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                res.push_back(i);
            }
        }
        return res;
    }

    bool check(const std::string& s) {
        bool zero = false;
        for (int i = 0; i < k; i++) {
            auto res = diff(s, as[i]);
            if (res.size() != 2 && res.size() != 0) {
                return false;
            }
            if (res.size() == 0) zero = true;
        }
        if (!zero) {
            return true;
        }
        std::array<int, 26> stat = {};
        for (size_t i = 0; i < s.length(); i++) {
            stat[s[i] - 'a']++;
        }
        for (int count : stat) {
            if (count > 1) {
                return true;
            }
        }
        return false;
    }

    void run(std::istream& in, std::ostream& out) {
        in >> k >> n;
        as.resize(k);
        for (int i = 0; i < k; i++) {
            in >> as[i];
        }
        if (k == 1) {
            std::swap(as[0][0], as[0][1]);
            out << as[0] << "\n";
            return;
        }

        std::vector<std::vector<int>> diff0(k);
        std::vector<std::array<int, 26>> stats(k);
        for (int i = 1; i < k; i++) {
            diff0[i] = diff(as[0], as[i]);
            if (diff0[i].size() > 4) {
                out << "-1\n";
                return;
            }
        }
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                stats[i][as[i][j] - 'a']++;
            }
        }
        for (int i = 1; i < k; i++) {
            if (stats[i] != stats[0]) {
                out << "-1\n";
                return;
            }
        }
        if (check(as[0])) {
            out << as[0] << "\n";
            return;
        }
        std::string t = as[0];
        std::swap(t[0], t[1]);
        if (check(t)) {
            out << t << "\n";
            return;
        }
        for (auto& diff : diff0) {
            if (diff.size() == 1) {
                out << "-1\n";
                return;
            }
            if (diff.size() >= 3) {
                std::string t = as[0];
                for (size_t i = 0; i < diff.size(); i++) {
                    for (size_t j = i + 1; j < diff.size(); j++) {
                        std::swap(t[diff[i]], t[diff[j]]);
                        if (check(t)) {
                            out << t << "\n";
                            return;
                        }
                        std::swap(t[diff[i]], t[diff[j]]);
                    }
                }
                out << "-1\n";
                return;
            }
        }
        int idx2;
        for (idx2 = 0; idx2 < k; idx2++) {
            if (diff0[idx2].size() == 2) {
                break;
            }
        }
        if (idx2 == k) {
            out << "-1\n";
            return;
        }
        int saveIdx2 = idx2;
        std::vector<int> t1 = diff0[idx2];
        for (int p1 : t1) {
            for (idx2 = saveIdx2; idx2 < k; idx2++) {
                if (diff0[idx2].size() != 2) continue;
                if (diff0[idx2][0] == p1 || diff0[idx2][1] == p1) continue;
                for (int p2 : diff0[idx2]) {
                    std::string t = as[0];
                    std::swap(t[p1], t[p2]);
                    if (check(t)) {
                        out << t << "\n";
                        return;
                    }
                }
                break;
            }
        }
        out << "-1\n";
    }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}