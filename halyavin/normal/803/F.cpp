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

const int max = 1000000;

const int mod = 1000000007;

int add32(int x, int y) {
  int res = x + y;
  if (res >= mod) res -= mod;
  return res;
}

int sub32(int x, int y) {
  int res = x - y;
  if (res < 0) res += mod;
  return res;
}

void run(std::istream& in, std::ostream& out) {
  std::vector<bool> sieve(max + 1, true);
  std::vector<int> sign(max + 1, 1);
  for (int j = 2; j <= max; j++) {
    if (sieve[j]) {
      sign[j] = -sign[j];
      for (int k = 2 * j; k <= max; k += j) {
        sieve[k] = false;
        sign[k] = -sign[k];
        if ((k / j) % j == 0) {
          sign[k] = 0;
        }
      }
    }
  }
  int n;
  in >> n;
  std::vector<int> stat(max + 1);
  for (int i = 0; i < n; i++) {
    int a;
    in >> a;
    stat[a]++;
  }
  std::vector<int> pow2(max + 1);
  pow2[0] = 1;
  for (int i = 1; i <= max; i++) {
    pow2[i] = add32(pow2[i - 1], pow2[i - 1]);
  }
  int zero = 2;
  int res = pow2[n];
  for (int i = 2; i <= max; i++) {
    if (sign[i] != 0) {
      int value = 0;
      for (int j = i; j <= max; j += i) {
        value += stat[j];
      }
      if (sign[i] > 0) {
        zero++;
        res = add32(res, pow2[value]);
      } else {
        zero--;
        res = sub32(res, pow2[value]);
      }
    }
  }
  if (zero > 1) {
    res = sub32(res, zero - 1);
  } else {
    res = add32(res, 1 - zero);
  }
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}