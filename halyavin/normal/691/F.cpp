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
  int n;
  in >> n;
  std::vector<int> as(n);
  for (int i = 0; i < n; i++) {
    in >> as[i];
  }
  int m;
  in >> m;
  std::vector<int> queries(m);
  for (int i = 0; i < m; i++) {
    in >> queries[i];
  }
  int maxQuery = *std::max_element(queries.begin(), queries.end());
  std::vector<int64_t> total(maxQuery + 1);
  std::vector<int> stat(maxQuery + 1);
  for (int i = 0; i < n; i++) {
    if (as[i] <= maxQuery) {
      stat[as[i]]++;
    }
  }
  for (int i = 1; i <= maxQuery; i++) {
    int cur = stat[i];
    int64_t ii = int64_t(i) * i;
    if (ii <= maxQuery) {
      total[ii] -= cur;
    }
    for (int j = i, k = 1; j <= maxQuery; j += i, k++) {
      total[j] += cur * int64_t(stat[k]);
    }
  }
  int64_t all = n * int64_t(n - 1);
  int64_t sum = 0;
  for (int i = 1; i <= maxQuery; i++) {
    int64_t nextSum = sum + total[i];
    total[i] = all - sum;
    sum = nextSum;
  }
  for (int i = 0; i < m; i++) {
    out << total[queries[i]] << "\n";
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}