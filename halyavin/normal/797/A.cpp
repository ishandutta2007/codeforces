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
  int n, k;
  in >> n >> k;
  std::vector<int> primeDivisors;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      primeDivisors.push_back(i);
      n /= i;
    }
  }
  if (n > 1) primeDivisors.push_back(n);
  if (primeDivisors.size() < k) {
    out << -1 << std::endl;
    return;
  }
  for (int i = 0; i < k - 1; i++) {
    out << primeDivisors[i] << " ";
  }
  int last = 1;
  for (int i = k - 1 ; i < primeDivisors.size(); i++) {
    last *= primeDivisors[i];
  }
  out << last << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}