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
#include <array>

const int levels = 17;
const int bands = 30;
const int64_t inf = int64_t(1) << 60;
struct Solution {
  int n;
  std::vector<int> cs;
  std::vector<int> csBands;

  std::array<std::vector<int64_t>, bands> sums;
  std::array<std::vector<int>, bands> counts;
  std::array<std::array<std::vector<int64_t>, levels>, bands> minSum;


  void build() {
    for (int i = 0; i < bands; i++) {
      sums[i].resize(n + 1);
      counts[i].resize(n + 1);
      for (int j = 0; j < levels; j++) {
        minSum[i][j].resize(n);
      }
    }
    csBands.resize(n);
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < bands; k++) {
        if (cs[i] < (1 << (k + 1))) {
          csBands[i] = k;
          break;
        }
      }
    }
    for (int band = 0; band < bands; band++) {
      int64_t sum = 0;
      for (int i = 0; i < n; i++) {
        sums[band][i] = sum;
        if (csBands[i] <= band) {
          sum += cs[i];
        }
      }
      sums[band][n] = sum;
      int count = 0;
      for (int i = 0; i < n; i++) {
        counts[band][i] = count;
        if (csBands[i] <= band) {
          count++;
        }
      }
      counts[band][n] = count;
    }
    for (int band = 0; band < bands; band++) {
      for (int i = 0; i < n; i++) {
        if (csBands[i] == band) {
          minSum[band][0][i] = cs[i] + ((band == 0) ? 0 : sums[band - 1][i + 1]);
        } else {
          minSum[band][0][i] = inf;
        }
      }
      for (int level = 1; level < levels; level++) {
        int shift = 1 << (level - 1);
        int shift2 = 1 << level;
        for (int i = 0; i + shift2 <= n; i++) {
          minSum[band][level][i] = std::min(minSum[band][level - 1][i], minSum[band][level - 1][i + shift]);
        }
      }
    }
  }

  int query(int x) {
    int res = 0;
    int pos = 0;
    for (int band = bands - 1; band > 0 && x > 0 && pos < n; band--) {
      if (x < (1 << band)) continue;
      int level = levels - 1;
      std::vector<int64_t>& curSums = sums[band - 1];
      std::vector<int>& curCounts = counts[band - 1];
      while (level >= 0) {
        int nextPos = pos + (1 << level);
        if (nextPos > n) {
          level--;
          continue;
        }
        int64_t minS = minSum[band][level][pos];
        if (minS <= x + curSums[pos]) {
          level--;
          continue;
        }
        int64_t sumSmall = curSums[nextPos] - curSums[pos];
        if (sumSmall > x) {
          level--;
          continue;
        }
        res += curCounts[nextPos] - curCounts[pos];
        x -= sumSmall;
        pos = nextPos;
        if (x < (1 << band)) {
          break;
        }
        if (level != levels - 1) {
          level--;
        }
      }
      if (x > 0 && pos < n) {
        if (cs[pos] <= x) {
          x -= cs[pos];
          res++;
          pos++;
        }
      }
    }
    if (x > 0) {
      int level = levels - 1;
      while (level >= 0) {
        if (pos + (1 << level) > n) {
          level--;
          continue;
        }
        int diff = sums[0][pos + (1 << level)] - sums[0][pos];
        if (diff > 0) {
          res++;
          break;
        }
        pos += 1 << level;
      }
    }
    return res;
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n;
    std::vector<std::pair<int, int>> tshirts(n);
    for (int i = 0; i < n; i++) {
      in >> tshirts[i].second >> tshirts[i].first;
      tshirts[i].first = -tshirts[i].first;
    }
    std::sort(tshirts.begin(), tshirts.end());
    cs.resize(n);
    for (int i = 0; i < n; i++) {
      cs[i] = tshirts[i].second;
    }
    build();
    int k;
    in >> k;
    for (int i = 0; i < k; i++) {
      int x;
      in >> x;
      int ans = query(x);
      out << ans << " ";
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