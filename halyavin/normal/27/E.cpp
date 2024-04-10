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
#include <cmath>

const int nprimes = 10;
const int primes[nprimes] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
void run(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  std::vector<std::vector<double>> opt(nprimes, std::vector<double>(n + 1, 1e+100));
  std::vector<std::vector<int>> degree(nprimes, std::vector<int>(n + 1));
  {
    double p = log(primes[0]);
    for (int i = 0; i <= n; i++) {
      opt[0][i] = p * (i - 1);
      degree[0][i] = i;
    }
  }
  for (int i = 1; i < nprimes; i++) {
    double p = log(primes[i]);
    for (int j = 1; j <= n; j++) {
      for (int k = j; k <= n; k += j) {
        double cur = p * (j - 1) + opt[i - 1] [k / j];
        if (cur < opt[i][k]) {
          opt[i][k] = cur;
          degree[i][k] = j;
        }
      }
    }
  }
  int64_t res = 1;
  for (int i = nprimes - 1; i >= 0; i--) {
    int d = degree[i][n];
    for (int j = 0; j < d - 1; j++) {
      res *= primes[i];
    }
    n /= d;
  }
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}