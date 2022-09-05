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
  int h, w;
  in >> h >> w;
  std::vector<std::string> input(h);
  for (int i = 0; i < h; i++) {
    in >> input[i];
  }
  std::vector<std::vector<int>> table(h + 1, std::vector<int>(w + 1));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (input[i][j] == '#') {
        table[i][j] = 1;
      }
    }
  }
  std::vector<std::vector<int>> sumTable(h + 1, std::vector<int>(w + 1));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (table[i][j] == 0 && table[i][j+1] == 0) {
        sumTable[i][j]++;
      }
      if (table[i][j] == 0 && table[i + 1][j] == 0) {
        sumTable[i][j]++;
      }
    }
  }
  for (int i = 0; i <= h; i++) {
    int sum = 0;
    for (int j = 0; j < w; j++) {
      int nextSum = sum + sumTable[i][j];
      sumTable[i][j] = sum;
      sum = nextSum;
    }
    sumTable[i][w] = sum;
  }
  for (int j = 0; j <= w; j++) {
    int sum = 0;
    for (int i = 0; i < h; i++) {
      int nextSum = sum + sumTable[i][j];
      sumTable[i][j] = sum;
      sum = nextSum;
    }
    sumTable[h][j] = sum;
  }
  int q;
  in >> q;
  for (int i = 0; i < q; i++) {
    int r1, c1, r2, c2;
    in >> r1 >> c1 >> r2 >> c2;
    r1--;c1--;r2--;c2--;
    int ans = sumTable[r2 + 1][c2 + 1] + sumTable[r1][c1] - sumTable[r2 + 1][c1] - sumTable[r1][c2 + 1];
    for (int i = r1; i <= r2; i++) {
      if (table[i][c2] == 0 && table[i][c2 + 1] ==0) {
        ans--;
      }
    }
    for (int i = c1; i <= c2; i++) {
      if (table[r2][i] == 0 && table[r2 + 1][i] == 0) {
        ans--;
      }
    }
    out << ans << "\n";
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}