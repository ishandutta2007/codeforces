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
#include <map>


const int p = 1000000007;

int pow(int a, int n) {
  int res = 1;
  while (n > 0) {
    if (n % 2 != 0) {
      res = (int64_t(res) * a) % p;
    }
    n /= 2;
    a = (int64_t(a) * a) % p;
  }
  return res;
}

void run(std::istream &in, std::ostream &out) {
  int m;
  in >> m;
  std::map<int, int> primes;
  for (int i = 0; i < m; i++) {
    int p;
    in >> p;
    primes[p] = primes[p] + 1;
  }
  int64_t mult = 1;
  bool div = false;
  for (std::pair<const int, int>& entry : primes) {
    if (!div && entry.second % 2 != 0) {
      div = true;
      mult = (mult * ((entry.second + 1) / 2)) % (p - 1);
    } else {
      mult = (mult * (entry.second + 1)) % (p - 1);
    }
  }
  int64_t res = 1;
  for (std::pair<const int, int>& entry : primes) {
    int curP = entry.first;
    int deg = entry.second;
    if (!div) {
      deg /= 2;
    }
    deg = (deg * mult) % (p - 1);
    res = (res * pow(curP, deg)) % p;
  }
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}