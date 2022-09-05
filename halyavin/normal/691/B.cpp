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

std::pair<char, char> map[] =
    {{'A', 'A'}, {'b', 'd'}, {'d', 'b'}, {'H', 'H'}, {'I', 'I'}, {'M', 'M'}, {'O', 'O'}, {'o', 'o'}, {'p', 'q'},
     {'q', 'p'},
     {'T', 'T'}, {'U', 'U'}, {'V', 'V'}, {'v', 'v'},
     {'W', 'W'}, {'w', 'w'}, {'X', 'X'}, {'x', 'x'}, {'Y', 'Y'}};

bool check(char a, char b) {
  for (std::pair<char, char> p : map) {
    if (p.first == a && p.second == b) {
      return true;
    }
  }
  return false;
}

void run(std::istream& in, std::ostream& out) {
  std::string s;
  in >> s;
  for (int i = 0, j = (int)s.length() - 1; i <= j; i++, j--) {
    if (!check(s[i], s[j])) {
      out << "NIE" << std::endl;
      return;
    }
  }
  out << "TAK" << std::endl;
}


int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}