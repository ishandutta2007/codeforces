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


struct Solution {
  const int STEPS = 20;
  int p;
  int eps;
  std::vector<int> epsPow;
  std::vector<int> epsInvPow;
  std::vector<int> inv;

  int mult(int x, int y) {
    return (int64_t(x) * y) % p;
  }

  void init() {
    for (p = (1 << STEPS) + 1; ; p += 1 << STEPS) {
      bool good = true;
      for (int j = 2; j * j < p; j++) {
        if (p % j == 0) {
          good = false;
          break;
        }
      }
      if (good) break;
    }
    for (eps = 2; ; eps++) {
      bool good = true;
      int cur = eps;
      for (int j = 0; j < STEPS; j++) {
        if (cur == 1) {
          good = false;
        }
        cur = mult(cur, cur);
      }
      if (good && cur == 1) break;
    }
    epsPow.resize(1 << STEPS);
    epsInvPow.resize(1 << STEPS);
    int cur = 1;
    for (size_t i = 0; i < epsPow.size(); i++) {
      epsPow[i] = cur;
      cur = mult(cur, eps);
    }
    epsInvPow[0] = 1;
    for (size_t i = 1; i < epsInvPow.size(); i++) {
      epsInvPow[i] = epsPow[epsPow.size() - i];
    }
    inv.resize(1 << STEPS);
    cur = 0;
    for (size_t i = 0; i < inv.size(); i++) {
      inv[i] = cur;
      size_t mask = 1 << (STEPS - 1);
      while ((cur & mask) != 0) {
        cur ^= mask;
        mask >>= 1;
      }
      cur ^= mask;
    }
  }

  void furier(std::vector<int>& input, std::vector<int>& epsPow, std::vector<int>& output, int order) {
    int n = 1 << order;
    int invShift = STEPS - order;
    for (int i = 0; i < n; i++) {
      output[i] = input[inv[i] >> invShift];
    }
    for (int block = 0; block < order; block++) {
      int step = 1 << block;
      int step2 = 1 << (block + 1);
      int shiftEps = STEPS - block - 1;
      for (int start = 0; start < n; start += step2) {
        for (int i = 0; i < step; i++) {
          int x0 = output[start + i];
          int x1 = output[start + step + i];
          output[start + i] = (x0 + mult(x1, epsPow[i << shiftEps])) % p;
          output[start + step + i] = (x0 + mult(x1, epsPow[(i + step) << shiftEps])) % p;
        }
      }
    }
  }

  void flatten(std::vector<int>& input) {
    for (size_t i = 0; i < input.size(); i++) {
      input[i] = std::min(1, input[i]);
    }
  }

  void multiply(std::vector<int>& input1, std::vector<int>& input2, std::vector<int>& output) {
    size_t i1, i2;
    for (i1 = input1.size(); i1-- > 0;) {
      if (input1[i1] != 0) break;
    }
    for (i2 = input2.size(); i2-- > 0;) {
      if (input2[i2] != 0) break;
    }
    int sum = i1 + i2;
    int order = 0;
    while ((1 << order) <= sum) order++;
    input1.resize(1 << order);
    input2.resize(1 << order);
    output.resize(1 << order);
    std::vector<int> out1(input1.size());
    std::vector<int> out2(input2.size());
    furier(input1, epsPow, out1, order);
    furier(input2, epsPow, out2, order);
    for (size_t i = 0; i < out1.size(); i++) {
      out1[i] = mult(out1[i], out2[i]);
    }
    furier(out1, epsInvPow, output, order);
    flatten(output);
  }

  void run(std::istream& in, std::ostream& out) {
    init();
    std::vector<int> x(1001);
    std::vector<int> px;
    std::vector<int> cur(1);
    int n, k;
    in >> n >> k;
    for (int i = 0; i < n; i++) {
      int a;
      in >> a;
      x[a] = 1;
    }
    px = x;
    cur[0] = 1;
    while (k > 0) {
      if (k % 2 != 0) {
        multiply(cur, px, cur);
      }
      multiply(px, px, px);
      k /= 2;
    }
    for (size_t i = 0; i < cur.size() ; i++) {
      if (cur[i] != 0) {
        out << i << " ";
      }
    }
    out << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}