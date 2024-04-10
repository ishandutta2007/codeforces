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

void run(std::istream& in, std::ostream& out) {
  int n, m, k;
  in >> n >> m >> k;
  if (k >= m) {
    out << 1 << std::endl;
    return;
  }
  if (k + n - m < 0) {
    out << 0 << std::endl;
    return;
  }
  std::vector<double> logF(n + m + 1);
  for (size_t i = 1; i < logF.size(); i++) {
    logF[i] = logF[i - 1] + log(i);
  }
  double logBin = logF[n + m] - logF[n] - logF[m];
  double p = 1.0;
  for (int s = 0; s + k + 1 <= m && s <= n; s++) {
    double logP = logF[2 * s + k + 1] - logF[s] - logF[s + k + 1] + log(k + 1) - log(2 * s + k + 1);
    logP += logF[n + m - 2 * s - k - 1] - logF[n - s] - logF[m - s - k - 1];
    p -= exp(logP - logBin);
  }
  out.precision(10);
  out << p << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}