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

const int mod = 1000000007;

void run(std::istream& in, std::ostream& out) {
  std::vector<std::array<int, 20>> rs(1000001);
  rs[0][0] = 1;
  for (size_t i = 1; i < rs[0].size(); i++) {
    rs[0][i] = 2;
  }
  for (size_t r = 1; r < rs.size(); r++) {
    int cur = 0;
    for (size_t i = 0; i < rs[r].size(); i++) {
      cur += rs[r - 1][i];
      if (cur >= mod) cur -= mod;
      rs[r][i] = cur;
    }
  }
  std::vector<int> nextPrime(1000001);
  for (size_t i = 2; i * i < nextPrime.size(); i++) {
    if (nextPrime[i] != 0) continue;
    for (size_t j = i * i; j < nextPrime.size(); j += i) {
      nextPrime[j] = i;
    }
  }
  for (size_t i = 2; i < nextPrime.size(); i++) {
    if (nextPrime[i] == 0) {
      nextPrime[i] = i;
    }
  }
  int q;
  in >> q;
  for (int query = 0; query < q; query++) {
    int r, n;
    in >> r >> n;
    int result = 1;
    while (n > 1) {
      int p = nextPrime[n];
      int a = 0;
      while (n % p == 0) {
        n /= p;
        a++;
      }
      result = (int64_t(result) * rs[r][a]) % mod;
    }
    out << result << "\n";
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}