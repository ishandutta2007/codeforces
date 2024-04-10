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
  return int(int64_t(x) * y % p);
}

int add32(int x, int y) {
  int res = x + y;
  if (res >= p) res -= p;
  return res;
}

using matrix = std::vector<std::vector<int>>;

void multMatrix(matrix& a1, matrix& a2, matrix& a3) {
  size_t n = a1.size();
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      int ans = 0;
      for (size_t k = 0; k < n; k++) {
        ans = add32(ans, mul32(a1[i][k], a2[k][j]));
      }
      a3[i][j] = ans;
    }
  }
}

void identityMatrix(matrix& a1, size_t n) {
  a1.assign(n, std::vector<int>(n));
  for (size_t i = 0; i < n; i++) {
    a1[i][i] = 1;
  }
}

matrix pow(matrix trans, int64_t k) {
  size_t n = trans.size();
  matrix res;
  identityMatrix(res, n);
  matrix res2 = res;
  matrix cur = trans;
  matrix cur2 = cur;
  while (k > 0) {
    if ((k & 1) != 0) {
      multMatrix(res, cur, res2);
      res.swap(res2);
    }
    multMatrix(cur, cur, cur2);
    cur.swap(cur2);
    k /= 2;
  }
  return res;
}

void run(std::istream &in, std::ostream &out) {
  size_t n;
  int64_t k;
  in >> n >> k;
  std::vector<int64_t> as(n);
  for (size_t i = 0; i < n; i++) {
    in >> as[i];
  }
  matrix trans;
  identityMatrix(trans, n);
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      if (__builtin_popcountll(as[i] ^ as[j]) % 3 == 0) {
        trans[i][j] = 1;
      }
    }
  }
  matrix total = pow(trans, k - 1);
  int res = 0;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      res = add32(res, total[i][j]);
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