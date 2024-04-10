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

const int p = 1000000007;

int mul32(int x, int y) {
  return int(int64_t(x) * y % p);
}

int pow32(int a, int64_t n) {
  int res = 1;
  while (n > 0) {
    if (n & 1) {
      res = (int64_t(res) * a) % p;
    }
    n >>= 1;
    a = (int64_t(a) * a) % p;
  }
  return res;
}

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<int64_t> as;
  for (int i = 0; i < n; i++) {
    int64_t a;
    in >> a;
    if (a > 1) {
      as.push_back(a);
    }
  }
  if (as.empty()) {
    out << "0/1" << std::endl;
    return;
  }
  int multOdd = true;
  for (int64_t a : as) {
    if (a % 2 == 0) {
      multOdd = false;
    }
  }
  int c = multOdd ? -1 : 1;
  int pow2 = 2;
  for (int64_t a : as) {
    pow2 = pow32(pow2, a);
  }
  if (pow2 % 2 == 0) {
    pow2 /= 2;
  } else {
    pow2 = (pow2 + p) / 2;
  }
  int q = pow2;
  pow2 = (pow2 + p + c) % p;
  if (pow2 % 3 == 0) {
    pow2 /= 3;
  } else if (pow2 % 3 == 1) {
    pow2 = (uint32_t(pow2) + uint32_t(p)) / 3;
  } else {
    pow2 = (uint32_t(pow2) + uint32_t(p) + uint32_t(p)) / 3;
  }
  out << pow2 << "/" << q << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}