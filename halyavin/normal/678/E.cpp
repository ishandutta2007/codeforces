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

void run(std::istream &in, std::ostream &out) {
  out.precision(12);
  int n;
  in >> n;
  if (n == 1) {
    out << 1.0 << std::endl;
    return;
  }
  std::vector<std::vector<double>> table(n, std::vector<double>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      in >> table[i][j];
    }
  }
  if (n == 2) {
    out << table[0][1] << std::endl;
    return;
  }
  std::vector<std::vector<double>> prob(n - 1, std::vector<double>(1 << (n - 1)));
  for (int i = 0; i < n - 1; i++) {
    prob[i][0] = table[0][i + 1];
  }
  for (int mask = 1; mask < 1 << (n - 1); mask++) {
    for (int last = 0; last < n - 1; last++) {
      if ((mask & (1 << last)) != 0) {
        continue;
      }
      double best = 0;
      for (int choice = 0; choice < n - 1; choice++) {
        if ((mask & (1 << choice)) == 0) {
          continue;
        }
        double p = table[last + 1][choice + 1];
        double q = 1- p;
        double cur = p * (prob[last][mask - (1 << choice)]) + q * (prob[choice][mask - (1 << choice)]);
        best = std::max(best, cur);
      }
      prob[last][mask] = best;
    }
  }
  double best = 0;
  for (int start1 = 0; start1 < n - 1; start1++) {
    for (int start2 = start1 + 1; start2 < n - 1; start2++) {
      int mask = (1 << (n - 1)) - 1 - (1 << start1) - (1 << start2);
      double p = table[start1 + 1][start2 + 1];
      double q = 1- p;
      double cur = p * prob[start1][mask] + q * prob[start2][mask];
      best = std::max(best, cur);
    }
  }
  out << best << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}