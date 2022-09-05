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

std::pair<int, int> parse(char c) {
  switch (c) {
    case '<':
      return {1, 0};
    case '>':
      return {-1, 0};
    case '[':
      return {1, 1};
    case ']':
      return {-1, 1};
    case '(':
      return {1, 2};
    case ')':
      return {-1, 2};
    case '{':
      return {1, 3};
    case '}':
      return {-1, 3};
  }
};

void run(std::istream &in, std::ostream &out) {
  std::string s;
  in >> s;
  std::vector<int> stack;
  int ans = 0;
  for (size_t i = 0; i < s.length(); i++) {
    std::pair<int, int> sym = parse(s[i]);
    if (sym.first == 1) {
      stack.push_back(sym.second);
    } else {
      if (stack.size() == 0) {
        out << "Impossible" << std::endl;
        return;
      }
      if (stack.back() != sym.second) {
        ans++;
      }
      stack.resize(stack.size() - 1);
    }
  }
  if (stack.size() != 0) {
    out << "Impossible" << std::endl;
    return;
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}