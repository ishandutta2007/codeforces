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

void run(std::istream& in, std::ostream& out) {
  int n, k;
  in >> n >> k;
  std::string s;
  in >> s;
  std::vector<std::vector<int>> dyn(n + 1, std::vector<int>(2 * k + 1, -100));
  dyn[0][k] = 0;
  for (int i = 1; i <= n; i++) {
    std::vector<int>& prev = dyn[i - 1];
    std::vector<int>& cur = dyn[i];
    if (s[i - 1] == '?') {
      if (prev[1] != -100) {
        cur[0] = -1;
      }
      if (prev[2 * k - 1] != -100) {
        cur[2 * k] = 1;
      }
      for (int j = 1; j < 2 * k; j++) {
        if (j > 1 && prev[j - 1] != -100) {
          cur[j] = 1;
          continue;
        }
        if (j < 2 * k - 1 && prev[j + 1] != -100) {
          cur[j] = -1;
          continue;
        }
        if (prev[j] != -100) {
          cur[j] = 0;
          continue;
        }
      }
    } else {
      int diff = 0;
      if (s[i - 1] == 'W') {
        diff = 1;
      } else if (s[i - 1] == 'L') {
        diff = -1;
      }
      for (int j = 1 + diff; j <= 2 * k - 1 + diff; j++) {
        if (prev[j - diff] != -100) {
          cur[j] = diff;
        }
      }
    }
  }
  int last = -1;
  if (dyn[n][2 * k] != -100) {
     last = 2 * k;
  } else if (dyn[n][0] != -100) {
     last = 0;
  }
  if (last < 0) {
    out << "NO" << std::endl;
    return;
  }
  std::string res(n, ' ');
  for (int i = n - 1; i >= 0; i--) {
    int sym = dyn[i + 1][last];
    last -=  sym;
    if (sym == -1) {
      res[i] = 'L';
    } else if (sym == 0) {
      res[i] = 'D';
    } else {
      res[i] = 'W';
    }
  }
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}