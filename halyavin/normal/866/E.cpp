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
#include <map>
#include <unordered_map>

int hexDigit(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    return c - 'a' + 10;
}

char toHexDigit(int x) {
    if (x < 10) return '0' + x;
    return 'a' + (x - 10);
}

struct hash {
    uint32_t operator()(const std::pair<int, std::array<int8_t, 16>>& key) const {
        uint32_t res = key.first;
        for (int i = 0; i < 16; i++) {
            res = (res << 2) + (res >> 3) + key.second[i];
        }
        return res;
    }
};

struct Solution {
    int n;
    std::vector<std::vector<int>> answers1;
    int64_t opt;
    static constexpr int64_t INF = int64_t(1) << 62;

    std::unordered_map<std::pair<int, std::array<int8_t, 16>>, bool, hash> mem;

    bool rec2(int mask, const std::array<int8_t, 16>& next, int guide, const std::vector<int>& delta) {
        if (mask == 0) {
            for (int v : next) {
                if (v != 0) {
                    return false;
                }
            }
            return true;
        }
        std::pair<int, std::array<int8_t, 16>> key = {mask, next};
        auto it = mem.find(key);
        if (it != mem.end()) {
            return it->second;
        }
        if (guide >= 0 && next[guide] <= 0) {
            guide = -1;
        }
        if (guide == -1) {
            for (int i = 0; i < 16; i++) {
                if (next[i] > 0) {
                    guide = i;
                }
            }
        }
        bool res = false;
        if (guide == -1) {
            for (int i = 0; i < n && !res; i++) {
                if ((mask & (1 << i)) != 0) {
                    if (delta[i] >= 0) {
                        key.second[delta[i]]++;
                        key.second[0]--;
                        res |= rec2(mask - (1 << i), key.second, -1, delta);
                        key.second[delta[i]]--;
                        key.second[0]++;
                    } else {
                        key.second[0]++;
                        key.second[-delta[i]]--;
                        res |= rec2(mask - (1 << i), key.second, -1, delta);
                        key.second[0]--;
                        key.second[-delta[i]]++;
                    }
                }
            }
            return res;
        }
        for (int i = 0; i < n && !res; i++) {
            if ((mask & (1 << i)) != 0) {
                if (delta[i] >= 0 && delta[i] + guide < 16) {
                    key.second[delta[i] + guide]++;
                    key.second[guide]--;
                    res  |= rec2(mask - (1 << i), key.second, delta[i] + guide, delta);
                    key.second[guide]++;
                    key.second[delta[i] + guide]--;
                } else if (delta[i] < 0 && delta[i] + guide >= 0){
                    key.second[delta[i] + guide]++;
                    key.second[guide]--;
                    res |= rec2(mask - (1 << i), key.second, delta[i] + guide, delta);
                    key.second[guide]++;
                    key.second[delta[i] + guide]--;
                }
            }
        }
        mem.emplace(key, res);
        return res;
    }

    int64_t getDeltaAnswer(const std::vector<int>& delta) {
        mem.clear();
        std::vector<int> res(n);
        std::array<int8_t, 16> stat = {};
        for (int i = n - 1; i >= 0; i--) {
            int first, last;
            if (delta[i] >= 0) {
                first = 0;
                last = delta[i];
            } else {
                first = -delta[i];
                last = 0;
            }
            bool good = false;
            for (; first < 16 && last < 16; first++,last++) {
                std::array<int8_t, 16> next = stat;
                next[first]--;
                next[last]++;
                mem.clear();
                if (rec2((1 << i) - 1, next, -1, delta)) {
                    good = true;
                    break;
                }
            }
            if (!good) {
                return INF;
            }
            res[i] = first;
            stat[first]--;
            stat[last]++;
        }
        int64_t final = 0;
        for (size_t i = res.size(); i-- > 0;) {
            final = (final << 4) + res[i];
        }
        return final;
    }

    void rec1(int64_t diff, int pos, int sum, std::vector<int>& curAns) {
        if (pos == n) {
            if (sum == 0 && diff == 0) {
                answers1.push_back(curAns);
            }
            return;
        }
        int s = diff & 15;
        curAns[pos] = s;
        rec1(diff >> 4, pos + 1, sum + s, curAns);
        if (s != 0) {
            curAns[pos] = s - 16;
            rec1((diff >> 4) + 1, pos + 1, sum + s - 16, curAns);
        }
    }

    void run(std::istream& in, std::ostream& out) {
        std::string s;
        in >> s;
        n = s.length();
        int64_t diff = 0;
        for (size_t i = 0; i < s.length(); i++) {
            diff = (diff << 4) + hexDigit(s[i]);
        }
        if (diff % 15 != 0) {
            out << "NO" << std::endl;
            return;
        }
        answers1.clear();
        std::vector<int> ans(n);
        rec1(diff, 0, 0, ans);
        if (answers1.empty()) {
            out << "NO" << std::endl;
            return;
        }
        opt = INF;
        for (const auto& delta : answers1) {
            int64_t tmp = getDeltaAnswer(delta);
            opt = std::min(opt, tmp);
        }

        if (opt == INF) {
            out << "NO" << std::endl;
            return;
        }
        std::string optHex;
        for (int i = 0; i < n; i++) {
            optHex.push_back(toHexDigit(opt & 15));
            opt >>= 4;
        }
        std::reverse(optHex.begin(), optHex.end());
        out << optHex << std::endl;
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}