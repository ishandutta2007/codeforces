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
  for (int i =0; i < n ;i++) {
    in >> as[i];
  }
  std::vector<int64_t> sum(n + 1);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + as[i - 1];
  }
  std::vector<int64_t> optValue(n + 1);
  std::vector<int> optMiddle(n + 1);
  for (int i = 0; i <= n; i++) {
    int64_t& opt = optValue[i];
    int& optInd = optMiddle[i];
    opt = -(1LL << 60);
    for (int j = 0; j <= i; j++) {
      int64_t res = sum[j] - sum[i] + sum[j] - sum[0];
      if (res > opt) {
        opt = res;
        optInd = j;
      }
    }
  }

  std::vector<int64_t> optValue2(n + 1);
  std::vector<int> optMiddle2(n + 1);
  for (int i = 0; i <= n; i++) {
    int64_t& opt = optValue2[i];
    int& optInd = optMiddle2[i];
    opt = -(1LL << 60);
    for (int j = i ; j <= n; j++) {
      int64_t res = sum[j] - sum[i] + sum[j] - sum[n];
      if (res > opt) {
        opt = res;
        optInd = j;
      }
    }
  }

  int64_t maxSum = -(1LL << 60);
  int maxInd = 0;
  for (int i = 0; i <= n; i++) {
    int64_t res = optValue[i] + optValue2[i];
    if (res > maxSum) {
      maxSum = res;
      maxInd = i;
    }
  }
  std::cout << optMiddle[maxInd] << " " << maxInd << " " << optMiddle2[maxInd] << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}