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
  int sum = 0;
  for (int i = 0; i < n; i++) {
    in >> as[i];
    sum += as[i];
  }
  if (sum % 2 == 0) {
    for (int j = 2; j <= sum; j += 2) {
      if (sum % j != 0) continue;
      int d = sum / j;
      bool good = true;
      for (int k = 0; k < n; k++) {
        if ((as[k] % (2 * d)) != 0) {
          good = false;
          break;
        }
      }
      if (good) {
        out << 2 * d << std::endl;
        std::string s;
        for (int k = 0; k < n; k++) {
          s.append(std::string(as[k]/(2*d), 'a' + k));
        }
        std::string ss = s;
        std::reverse(ss.begin(), ss.end());
        s.append(ss);
        std::string res;
        for (int k = 0; k < d; k++) {
          res.append(s);
        }
        out << res << std::endl;
        return;
      }
    }
  } else {
    for (int j = 1; j <= sum; j += 2) {
      if (sum % j != 0) continue;
      int d = sum / j;
      int countOdd = 0;
      int oddIdx = 0;
      bool good = true;
      for (int k = 0; k < n; k++) {
        if ((as[k] % d) != 0) {
          good = false;
          break;
        }
        if (((as[k]/d) % 2) != 0) {
          countOdd++;
          oddIdx = k;
        }
      }
      if (!good) continue;
      if (countOdd != 1) continue;
      out << d << std::endl;
      std::string s;
      for (int k = 0; k < n; k++) {
        s.append(std::string(as[k]/d/2, 'a' + k));
      }
      std::string ss = s;
      std::reverse(ss.begin(), ss.end());
      s.append(ss);
      s.push_back((char)('a' + oddIdx));
      std::string res;
      for (int k = 0; k < d; k++) {
        res.append(s);
      }
      out << res << std::endl;
      return;
    }
  }
  out << 0 << std::endl;
  std::string s;
  for (int k = 0; k < n; k++) {
    s.append(std::string(as[k], 'a' + k));
  }
  out << s << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}