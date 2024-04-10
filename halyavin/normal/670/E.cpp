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

void run(std::istream &in, std::ostream &out) {
  int n, m, p;
  in >> n >> m >> p;
  p--;
  std::string s;
  in >> s;
  std::vector<int> prev(n);
  std::iota(prev.begin(), prev.end(), -1);
  std::vector<int> next(n);
  std::iota(next.begin(), next.end(), 1);
  std::vector<int> other(n);
  std::vector<int> stack;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      stack.push_back(i);
    } else {
      other[i] = stack.back();
      other[stack.back()] = i;
      stack.pop_back();
    }
  }
  std::string commands;
  in >> commands;
  for (size_t i = 0; i < commands.length(); i++) {
    switch (commands[i]) {
      case 'L':
        p = prev[p];
        break;
      case 'R':
        p = next[p];
        break;
      case 'D':
      {
        int otherp = other[p];
        if (otherp < p) {
          std::swap(p, otherp);
        }
        if (prev[p] >= 0) {
          next[prev[p]] = next[otherp];
        }
        if (next[otherp] < n) {
          prev[next[otherp]] = prev[p];
        }
        if (next[otherp] < n) {
          p = next[otherp];
        } else {
          p = prev[p];
        }
      }
    }
  }
  while (prev[p] >= 0) {
    p = prev[p];
  }
  std::string result(1, s[p]);
  while (next[p] < n) {
    p = next[p];
    result.append(1, s[p]);
  }
  out << result << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}