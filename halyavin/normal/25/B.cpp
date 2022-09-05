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

void run(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  std::string s;
  in >> s;
  int dig2 = 0;
  for (; (n - 2 * dig2) % 3 != 0; dig2++) { }
  int dig3 = (n - 2 * dig2) / 3;
  std::string answer;
  for (int i = 0; i < dig2; i++) {
    answer.append(s.substr(2 * i, 2));
    answer.append(1, '-');
  }
  int pos = 2 * dig2;
  for (int i = 0; i < dig3; i++) {
    answer.append(s.substr(3 * i + pos, 3));
    answer.append(1, '-');
  }
  answer.resize(answer.length() - 1);
  out << answer << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}