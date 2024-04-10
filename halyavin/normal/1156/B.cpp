#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <array>

void appendPair(std::string& s, const std::pair<int, int>& p) {
  s.append(p.second, 'a' + p.first);
}

void run(std::istream &in, std::ostream &out) {
  int T;
  in >> T;
  for (int test = 0; test < T; test++) {
    std::string s;
    in >> s;
    std::array<int, 26> stats = {};
    for (char c : s) {
      stats[c - 'a']++;
    }
    std::vector<std::pair<int, int>> stats2;
    for (int i = 0; i < 26; i++) {
      if (stats[i] != 0) {
        stats2.emplace_back(i, stats[i]);
      }
    }
    if (stats2.size() == 1) {
      out << s << "\n";
      continue;
    }
    if (stats2.size() == 2) {
      if (stats2[1].first == stats2[0].first + 1) {
        out << "No answer\n";
      } else {
        std::string ans;
        appendPair(ans, stats2[0]);
        appendPair(ans, stats2[1]);
        out << ans << "\n";
      }
      continue;
    }
    if (stats2.size() == 3) {
      if (stats2[2].first == stats2[0].first + 2) {
        out << "No answer\n";
      } else if (stats2[1].first != stats2[0].first + 1) {
        std::string ans;
        appendPair(ans, stats2[1]);
        appendPair(ans, stats2[0]);
        appendPair(ans, stats2[2]);
        out << ans << "\n";
      } else {
        std::string ans;
        appendPair(ans, stats2[1]);
        appendPair(ans, stats2[2]);
        appendPair(ans, stats2[0]);
        out << ans << "\n";
      }
      continue;
    }
    if (stats2.size() % 2 == 0) {
      std::string ans;
      for (int i = stats2.size() - 2; i >= 0; i -= 2) {
        appendPair(ans, stats2[i]);
      }
      for (int i = stats2.size() - 1; i >= 0; i -= 2) {
        appendPair(ans, stats2[i]);
      }
      out << ans << "\n";
    } else {
      std::string ans;
      for (int i = stats2.size() - 1; i >= 0; i -= 2) {
        appendPair(ans, stats2[i]);
      }
      for (int i = stats2.size() - 2; i >= 0; i -= 2) {
        appendPair(ans, stats2[i]);
      }
      out << ans << "\n";
    }
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}