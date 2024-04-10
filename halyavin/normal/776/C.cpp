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
#include <cmath>

void run(std::istream &in, std::ostream &out) {
  int n, k;
  in >> n >> k;
  std::vector<int64_t> powers;
  if (std::abs(k) == 1) {
    powers.push_back(1);
    if (k != 1) {
      powers.push_back(-1);
    }
  } else {
    int64_t t = 1;
    while (std::abs(t) <= int64_t(n) * 1000000001) {
      powers.push_back(t);
      t *= k;
    }
  }
  std::map<int64_t, int> stat;
  int64_t sum = 0;
  for (int64_t v : powers) {
    stat[v]++;
  }
  int64_t answer = 0;
  for (int i = 0; i < n; i++) {
    int a;
    in >> a;
    sum += a;
    answer += stat[sum];
    for (int64_t v : powers) {
      stat[sum + v]++;
    }
  }
  out << answer << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}