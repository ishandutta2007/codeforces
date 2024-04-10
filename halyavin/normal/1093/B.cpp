#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
  int t;
  in >> t;
  for (int test = 0; test < t; test++) {
    std::string s;
    in >> s;
    bool bad = true;
    for (size_t i = 1; i < s.length(); i++) {
      if (s[i] != s[0]) {
        bad = false;
      }
    }
    if (bad) {
      out << "-1\n";
    } else {
      std::sort(s.begin(), s.end());
      out << s << "\n";
    }
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}