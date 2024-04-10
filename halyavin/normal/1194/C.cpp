#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <array>

void run(std::istream &in, std::ostream &out) {
  int T;
  in >> T;
  for (int test = 0; test < T; test++) {
    std::string s, t, p;
    in >> s >> t >> p;
    std::array<int, 26> statS={}, statT={}, statP={};
    for (char c : s) {
      statS[c - 'a']++;
    }
    for (char c : t) {
      statT[c - 'a']++;
    }
    for (char c : p) {
      statP[c - 'a']++;
    }
    bool good = true;
    for (int i = 0; i < 26; i++) {
      if (statS[i] + statP[i] < statT[i]) {
        good = false;
        break;
      }
    }
    if (!good) {
      out << "NO\n";
      continue;
    }
    size_t pos = 0;
    for (size_t i = 0; i < t.length() && pos < s.length(); i++) {
      if (s[pos] == t[i]) {
        pos++;
      }
    }
    if (pos == s.length()) {
      out << "YES\n";
    } else {
      out << "NO\n";
    }
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}