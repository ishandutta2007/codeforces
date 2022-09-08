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

int table[10] = {6, 2, 5, 5,4, 5, 6, 3, 7, 6};
int sum = 0;

int getInd(int x) {
  int res = 0;
  while (x != 0) {
    res += table[x % 10];
    x /= 10;
  }
  return res;
}

void run(std::istream &in, std::ostream &out) {
  int a, b;
  in >> a >> b;
  sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += table[i];
  }
  int64_t res = 0;
  for (int i = a; i <= b; ) {
    if (i % 10 == 0 && i + 10 <= b) {
      res += (getInd(i) - table[0]) * 10 + sum;
      i += 10;
    } else {
      res += getInd(i);
      i++;
    }
  }
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}