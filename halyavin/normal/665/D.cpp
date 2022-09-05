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

std::vector<bool> sieve() {
  std::vector<bool> primes(2000001, true);
  primes[1] = false;
  for (int i = 2; i * i <= 2000000; i++) {
    if (!primes[i]) {
      continue;
    }
    for (int j = i * i; j <= 2000000; j += i) {
      primes[j] = false;
    }
  }
  return primes;
}

void run(std::istream& in, std::ostream& out) {
  std::vector<bool> primes = sieve();
  int n;
  in >> n;
  std::vector<int> as(n);
  for (int i = 0; i < n; i++) {
    in >> as[i];
  }
  int ones = std::count(as.begin(), as.end(), 1);
  if (ones >= 2) {
    for (int i = 0; i < n; i++) {
      if (as[i] > 1 && primes[as[i]+1]) {
        out << ones + 1 << std::endl;
        for (int j = 0; j < ones; j++) {
          out << 1 << " ";
        }
        out << as[i] << std::endl;
        return;
      }
    }
    out << ones << std::endl;
    for (int j = 0; j < ones; j++) {
      out << 1 << " ";
    }
    out << std::endl;
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (primes[as[i] + as[j]]) {
        out << 2 << std::endl;
        out << as[i] << " " << as[j] << std::endl;
        return;
      }
    }
  }
  out << 1 << std::endl;
  out << as[0] << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}