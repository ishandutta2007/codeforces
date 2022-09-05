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

void precalc(std::vector<int>& primes, std::vector<int>& fPrime) {
  std::fill(fPrime.begin(), fPrime.end(), 1);
  for (size_t i = 2; i * i < fPrime.size(); i++) {
    if (fPrime[i] != 1) continue;
    for (size_t j = i * i; j < fPrime.size(); j+= i) {
      fPrime[j] = i;
    }
  }
  for (size_t i = 2; i < fPrime.size(); i++) {
    if (fPrime[i] == 1) {
      fPrime[i] = i;
      primes.push_back(i);
    }
  }
}

const int maxStrength = 100000;

void run(std::istream &in, std::ostream &out) {
  std::vector<int> primes;
  std::vector<int> firstPrime(maxStrength + 1);
  precalc(primes, firstPrime);
  int n;
  in >> n;
  std::vector<int> stat(maxStrength + 1);
  std::vector<int> strength(n);
  for (int i = 0; i < n;i++) {
    in >> strength[i];
    stat[strength[i]]++;
  }
  std::vector<int> maxStat(maxStrength + 1);
  for (int i = 2; i <= maxStrength; i++) {
    int j = i;
    while (j != 1) {
      int p = firstPrime[j];
      maxStat[p]+= stat[i];
      while (j % p == 0) j /= p;
    }
  }
  int maxInd = 1;
  int maxValue = 1;
  for (int i = 2; i <= maxStrength; i++) {
    if (maxStat[i] > maxValue) {
      maxValue = maxStat[i];
      maxInd = i;
    }
  }
  out << maxValue << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}