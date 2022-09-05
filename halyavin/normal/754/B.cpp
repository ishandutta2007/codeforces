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
  std::array<std::array<int, 4>, 4> field = {};
  for (int i = 0; i < 4; i++) {
    std::string s;
    in >> s;
    for (int j = 0; j < 4; j++) {
      if (s[j] == 'x') {
        field[i][j] = 1;
      }
      if (s[j] == 'o') {
        field[i][j] = -1;
      }
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      int xs = 0;
      int dots = 0;
      for (int k = 0; k < 3; k++) {
        if (field[i][j + k] == 1) xs++;
        if (field[i][j + k] == 0) dots++;
      }
      if (xs == 2 && dots == 1) {
        out << "YES" << std::endl;
        return;
      }
      xs = 0;
      dots = 0;
      for (int k = 0; k < 3; k++) {
        if (field[j + k][i] == 1) xs++;
        if (field[j + k][i] == 0) dots++;
      }
      if (xs == 2 && dots == 1) {
        out << "YES" << std::endl;
        return;
      }
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      int xs = 0;
      int dots = 0;
      for (int k = 0; k < 3; k++) {
        if (field[i + k][j + k] == 1) xs++;
        if (field[i + k][j + k] == 0) dots++;
      }
      if (xs == 2 && dots == 1) {
        out << "YES" << std::endl;
        return;
      }
      xs = 0;
      dots = 0;
      for (int k = 0; k < 3; k++) {
        if (field[i + k][3 - j - k] == 1) xs++;
        if (field[i + k][3 - j - k] == 0) dots++;
      }
      if (xs == 2 && dots == 1) {
        out << "YES" << std::endl;
        return;
      }
    }
  }
  out << "NO" << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}