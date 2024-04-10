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

void run(std::istream &in, std::ostream &out) {
  int n, k, x;
  in >> n >> k >> x;
  std::vector<int> stat(1024);
  std::vector<int> stat2(1024);
  for (int i = 0; i < n; i++) {
    int a;
    in >> a;
    stat[a]++;
  }
  for (int i = 0; i < k; i++) {
    int mode = 1;
    std::fill(stat2.begin(), stat2.end(), 0);
    for (size_t j = 0; j < stat.size(); j++) {
      int changed = (stat[j] + mode) / 2;
      int stayed = stat[j] - changed;
      mode = (mode + stat[j]) % 2;
      stat2[j] += stayed;
      stat2[j ^ x] += changed;
    }
    std::swap(stat, stat2);
  }
  int minV = 0;
  int maxV = 1023;
  while (stat[minV] == 0) minV++;
  while (stat[maxV] == 0) maxV--;
  out << maxV << " " << minV << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}