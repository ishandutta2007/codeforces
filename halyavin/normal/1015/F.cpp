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

const int mod = 1'000'000'007;

int add32(int x, int y) {
  int res = x + y;
  if (res >= mod) res -= mod;
  return res;
}

void addRef(int& x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}

struct Solution {
    std::vector<std::vector<std::vector<int>>> l1, l2;
    int n;
    std::string s;
    int sl;
    std::vector<int> backFunc;

    void fillBack() {
        backFunc.resize(s.size());
        for (int i = 0; i < s.size(); i++) {
            char other = '(' ^ ')' ^ s[i];
            std::string t = s.substr(0, i);
            t.push_back(other);
            t.erase(t.begin());
            while (s.compare(0, t.length(), t) != 0) {
                t.erase(t.begin());
            }
            backFunc[i] = t.length();
        }
    }

    void run(std::istream& in, std::ostream& out) {
        in >> n;
        in >> s;
        sl = s.length();
        fillBack();
        l1.resize(n + 1, std::vector<std::vector<int>>(sl + 1, std::vector<int>(sl + 1)));
        l2.resize(n + 1, std::vector<std::vector<int>>(sl + 1, std::vector<int>(sl + 1)));
        l1[0][0][0] = 1;
        for (int i = 1; i <= 2 * n; i++) {
            for (int j = 0; j <= std::min(n, i); j++) {
                if (((j ^ i) & 1) != 0) continue;
                for (int k = 0; k <= std::min(sl, i); k++) {
                    std::fill(l2[j][k].begin(), l2[j][k].begin() + k + 1, 0);
                }
            }
            for (int j = 0; j <= std::min(n, i - 1); j++) {
                if (((j ^ (i - 1)) & 1) != 0) continue;
                for (int k = 0; k <= std::min(sl - 1, i - 1); k++) {
                    for (int l = 0; l <= k; l++) {
                        int level = s[l] == '(' ? (j + 1) : (j - 1);
                        if (level >= 0 && level <= n) {
                            addRef(l2[level][std::max(k, l + 1)][l + 1], l1[j][k][l]);
                        }
                        level = s[l] == '(' ? (j - 1) : (j + 1);
                        if (level >= 0 && level <= n) {
                            addRef(l2[level][k][backFunc[l]], l1[j][k][l]);
                        }
                    }
                }
                if (i > sl) {
                    int k = sl;
                    for (int l = 0; l < k; l++) {
                        int level = s[l] == '(' ? (j + 1) : (j - 1);
                        if (level >= 0 && level <= n) {
                            addRef(l2[level][std::max(k, l + 1)][l + 1], l1[j][k][l]);
                        }
                        level = s[l] == '(' ? (j - 1) : (j + 1);
                        if (level >= 0 && level <= n) {
                            addRef(l2[level][k][backFunc[l]], l1[j][k][l]);
                        }
                    }
                    {
                        int level = j + 1;
                        if (level >= 0 && level <= n) {
                            addRef(l2[level][k][k], l1[j][k][k]);
                        }
                        level = j - 1;
                        if (level >= 0 && level <= n) {
                            addRef(l2[level][k][k], l1[j][k][k]);
                        }
                    }
                }
            }
            std::swap(l1, l2);
        }
        int ans = 0;
        for (int i = 0; i <= sl; i++) {
            addRef(ans, l1[0][sl][i]);
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