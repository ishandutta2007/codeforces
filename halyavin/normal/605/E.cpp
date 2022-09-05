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
  std::vector<std::vector<long double>> p(n, std::vector<long double>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      in >> x;
      p[i][j] = x * 0.01;
    }
  }
  if (n == 1) {
    out << "0" << std::endl;
    return;
  }
  std::vector<long double> ans(n, 0);
  std::vector<long double> sum(n - 1, 1);
  std::vector<long double> prob(n - 1, 0);
  std::vector<bool> flags(n - 1, true);
  for (int i = 0; i < n - 1; i++) {
    prob[i] = 1 - p[i][n - 1];
  }
  for (int i = 0; i < n - 1; i++) {
    long double min = 1e+100;
    int idx = -1;
    for (int j = 0; j < n - 1; j++) {
      if (flags[j] && prob[j] < 0.995 && sum[j] / (1 - prob[j]) < min) {
        min = sum[j] / (1 - prob[j]);
        idx = j;
      }
    }
    if (idx < 0) break;
    flags[idx] = false;
    ans[idx] = min;
    for (int j = 0; j < n - 1; j++) {
      if (flags[j]) {
        sum[j] += prob[j] * p[j][idx] * min;
        prob[j] *= 1 - p[j][idx];
      }
    }
  }
  out.precision(20);
  out << ans[0] << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}