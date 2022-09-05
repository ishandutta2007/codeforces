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

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::string s, t;
    in >> s >> t;
    std::array<int, 26> stat1 = {};
    std::array<int, 26> stat2 = {};
    for (int i = 0; i < n; i++) {
        stat1[s[i] - 'a']++;
        stat2[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (stat1[i] != stat2[i]) {
            out << "-1\n";
            return;
        }
    }
    std::vector<int> ans;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = i; j < n; j++) {
            if (s[j] == t[i]) break;
        }
        while (j > i) {
            ans.push_back(j - 1);
            std::swap(s[j - 1], s[j]);
            j--;
        }
    }
    out << ans.size() << "\n";
    for (int move : ans) {
        out << (move + 1) << " ";
    }
    out << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}