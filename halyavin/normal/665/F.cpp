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

const int pred = 100000000;

void sieve(std::vector<int>& res, std::vector<bool>& primes) {
  primes.assign(pred + 1, true);
  res.resize(0);
  primes[1] = false;
  for (int i = 2; i * i <= pred; i++) {
    if (!primes[i]) {
      continue;
    }
    for (int j = i * i; j <= pred; j += i) {
      primes[j] = false;
    }
  }
  for (int i = 2; i < primes.size(); i++) {
    if (primes[i]) {
      res.push_back(i);
    }
  }
}
struct Solution {
  std::vector<int> pi;
  std::vector<int> ps;

  int64_t calcPhi(int64_t n, int k) {
    if (k == 0) {
      return (n + 1) / 2;
    }
    if (n <= int64_t(ps[k]) * int64_t(ps[k])) {
      return calcPi(n) - k;
    }
    return calcPhi(n, k - 1) - calcPhi(n / ps[k], k - 1);
  }

  int64_t calcP2(int64_t n, int k) {
    int64_t res = 0;
    for (int s = k + 1; int64_t(ps[s]) * int64_t(ps[s]) <= n; s++) {
      res += calcPi(n / ps[s]) - s;
    }
    return res;
  }

  int64_t calcPi(int64_t n) {
    if (n < pi.size()) {
      return pi[n];
    }
    int k = 0;
    while (int64_t(ps[k]) * int64_t(ps[k]) * int64_t(ps[k]) <= n) {
      k++;
    }
    return calcPhi(n, k) + k - calcP2(n, k);
  }

  int64_t calcPi2(int64_t n) {
    int k = 0;
    while (int64_t(ps[k]) * int64_t(ps[k]) * int64_t(ps[k]) <= n) {
      k++;
    }
    return calcPhi(n, k) + k - calcP2(n, k);
  }


  void run(std::istream& in, std::ostream& out) {
    int64_t n;
    in >> n;
    std::vector<bool> flags;
    sieve(ps, flags);
    int64_t res = 0;
    for (int i = 0; i < ps.size(); i++) {
      if (int64_t(ps[i]) * int64_t(ps[i]) * int64_t(ps[i]) <= n) {
        res++;
      } else {
        break;
      }
    }
    pi.assign(pred + 1, 0);
    int t = 0;
    for (int i = 2; i <= pred; i++) {
      t += (flags[i] ? 1 : 0);
      pi[i] = t;
    }
//    for (int i = 2; i < n; i++) {
//      std::cerr << i << std::endl;
//      if (calcPi(i) != calcPi2(i)) {
//        out << i << " " << calcPi(i) << " " << calcPi2(i) << std::endl;
//        out << calcPi2(i) << std::endl;
//        break;
//      }
//    }
    for (int i = 0; int64_t(ps[i]) * int64_t(ps[i]) < n; i++) {
      res += calcPi(n / ps[i]) - i - 1;
    }
    out << res << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}