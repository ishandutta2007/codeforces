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

const int p = 1000000007;

int mul32(int x, int y) {
  return (int64_t(x) * y) % p;
}

int getRes(int d, int m, std::string& x, std::vector<int>& rem, std::vector<std::vector<int>>& dyn) {
  int n = x.length();
  int res = 0;
  int sum = 0;
  bool bad = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < x[i] - '0'; j++) {
      if ((i % 2 != 0) ^ (j == d)) {
        continue;
      }
      res = (res + dyn[n - i - 1][(sum + j * rem[n - i - 1]) % m]) % p;
    }
    sum = (sum + (x[i] - '0') * rem[n - i - 1]) % m;
    if ((i % 2 != 0) ^ (x[i] - '0' == d)) {
      bad = true;
      break;
    }
  }
  if (!bad && sum == 0) {
    res = (res + 1) % p;
  }
  return res;
}

void run(std::istream& in, std::ostream& out) {
  int m, d;
  in >> m >> d;
  std::string a, b;
  in >> a >> b;
  int n = a.length();
  std::vector<int> rem(n);
  int c = 1;
  for (int i = 0; i < n; i++) {
    rem[i] = c;
    c = (c * 10) % m;
  }
  std::vector<std::vector<int>> dyn(n, std::vector<int>(m, 0));
  dyn[0][0] = 1;
  for (int i = 1; i < n; i++) {
    for (int dd = 0; dd < 10; dd++) {
      if (((n - i) % 2 != 0) ^ (dd == d)) continue;
      int diff = rem[i - 1] * dd;
      for (int j = 0; j < m; j++) {
        dyn[i][j] = (dyn[i][j] + dyn[i - 1][(j + diff) % m]) % p;
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == '0') {
      a[i] = '9';
    } else {
      a[i]--;
      break;
    }
  }
  int resB = getRes(d, m, b, rem, dyn);
  int resA = getRes(d, m, a, rem, dyn);
  int res = resB - resA;
  if (res < 0) res += p;
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}