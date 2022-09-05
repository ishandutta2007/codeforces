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

int primes[4] = {2,3,5,7};
int primes2[11] = {11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

bool request(int div, std::istream& in, std::ostream& out) {
  out << div << std::endl;
  out.flush();
  std::string s;
  in >> s;
  return s == "yes";
}

void run(std::istream &in, std::ostream &out) {
  int div = 0;
  int p = 0;
  for (int i = 0; i < 4; i++) {
    if (request(primes[i], in, out)) {
      div++;
      p = primes[i];
    }
  }
  if (div == 0) {
    out << "prime" << std::endl;
    return;
  }
  if (div >= 2) {
    out << "composite" << std::endl;
    return;
  }
  if (request(p * p, in, out)) {
    out << "composite" << std::endl;
    return;
  }
  for (int i = 0; i < 11; i++) {
    if (request(primes2[i], in, out)) {
      out << "composite" << std::endl;
      return;
    }
  }
  out << "prime" << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}