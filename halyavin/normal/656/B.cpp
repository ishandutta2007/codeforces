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

int gcd(int x, int y) {
  return y == 0 ? x : gcd(y, x % y);
}


void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<int> m(n);
  std::vector<int> r(n);
  for (int i = 0; i < n; i++) {
    in >> m[i];
  }
  for (int i = 0; i < n; i++) {
    in >> r[i];
  }
  double ans = 0;
  std::vector<int> tmpM(1 << n);
  std::vector<int> tmpR(1 << n);
  tmpM[0] = 1;
  for (int mask = 1; mask < (1 << n); mask++) {
    int c = 0;
    int last = 0;
    for (int i = 0; i < n; i++) {
      if ((mask & (1 << i)) != 0) {
        c ^= 1;
        last = i;
      }
    }
    int prevMask = mask - (1 << last);
    int prevM = tmpM[prevMask];
    int prevR = tmpR[prevMask];
    if (prevR == -1) {
      tmpR[mask] = -1;
      continue;
    }
    int d = m[last] / gcd(m[last], prevM);
    int newM = prevM * d;
    for (int i = 0; i < d; i++) {
      if (prevR % m[last] == r[last]) break;
      prevR += prevM;
    }
    if (prevR >= newM) {
      prevR = -1;
    }
    tmpM[mask] = newM;
    tmpR[mask] = prevR;
    if (prevR >= 0) {
      if (c == 0) {
        ans -= 1.0 / newM;
      } else {
        ans += 1.0 / newM;
      }
    }
  }
  out.precision(6);
  out << ans << std::endl;

}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}