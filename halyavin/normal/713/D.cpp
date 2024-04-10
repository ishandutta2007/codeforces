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

struct Solution {
  static const int STEPS = 10;
  int n, m;
  std::vector<std::vector<std::array<std::array<int16_t, STEPS>, STEPS>>> squareMax;
  std::vector<std::vector<int8_t>> data;
  std::vector<std::vector<int16_t>> distX;
  std::vector<std::vector<int16_t>> distY;
  std::vector<std::vector<int16_t>> squareSizes;
  std::vector<int> pow2;
  void calcSquareSizes() {
    distX.assign(n, std::vector<int16_t>(m));
    distY.assign(n, std::vector<int16_t>(m));
    squareSizes.assign(n, std::vector<int16_t>(m));
    for (int j = 0; j < m; j++) {
      int last = 0;
      for (int i = 0; i < n; i++) {
        if (data[i][j] == 0) {
          for (int k = last; k < i; k++) {
            distX[k][j] = i - k;
          }
          last = i + 1;
        }
      }
      for (int k = last; k < n; k++) {
        distX[k][j] = n - k;
      }
    }
    for (int i = 0; i < n; i++) {
      int last = 0;
      for (int j = 0; j < m; j++) {
        if (data[i][j] == 0) {
          for (int k = last; k < j; k++) {
            distY[i][k] = j - k;
          }
          last = j + 1;
        }
      }
      for (int k = last; k < m; k++) {
        distY[i][k] = m - k;
      }
    }
    for (int i = 0; i < n; i++) {
      int cur = 0;
      for (int j = 0; j < m; j++) {
        if (data[i][j] == 0) {
          cur = 0;
          squareSizes[i][j] = 0;
          continue;
        }
        cur = std::max(cur - 1, 0);
        while (i + cur + 1 <= n && j + cur + 1 <= m && distX[i][j + cur] >= cur + 1 && distY[i + cur][j] >= cur + 1) {
          cur++;
        }
        squareSizes[i][j] = cur;
      }
    }
  }

  void buildSquareMax() {
    squareMax.assign(n, std::vector<std::array<std::array<int16_t, STEPS>, STEPS>>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        squareMax[i][j][0][0] = squareSizes[i][j];
      }
    }
    for (int stepX = 0; stepX < STEPS; stepX++) {
      if (stepX > 0) {
        int shiftX = 1 << (stepX - 1);
        for (int i = 0; i + shiftX < n; i++) {
          for (int j = 0; j < m; j++) {
            squareMax[i][j][stepX][0] = std::max(squareMax[i][j][stepX - 1][0],
                                                 squareMax[i + shiftX][j][stepX - 1][0]);
          }
        }
      }
      for (int stepY = 1; stepY < STEPS; stepY++) {
        int shiftY = 1 << (stepY - 1);
        for (int i = 0; i < n; i++) {
          for (int j = 0; j + shiftY < m; j++) {
            squareMax[i][j][stepX][stepY] = std::max(squareMax[i][j][stepX][stepY - 1],
                                                     squareMax[i][j + shiftY][stepX][stepY - 1]);
          }
        }
      }
    }
  }

  void buildPow2() {
    pow2.resize(std::max(n, m) + 1);
    int step = 0;
    for (size_t i = 1; i < pow2.size(); i++) {
      if ((1 << (step + 1)) <= i) step++;
      pow2[i] = step;
    }
  }

  int find(int x1, int y1, int x2, int y2) {
    int left = 0;
    int right = std::min(x2 - x1, y2 - y1) + 1;
    while (right - left > 1) {
      int middle = (left + right) / 2;
      int l1 = x2 - x1 - middle + 1;
      int l2 = y2 - y1 - middle + 1;
      int p1 = pow2[l1];
      int p2 = pow2[l2];
      int shiftX = l1 - (1 << p1);
      int shiftY = l2 - (1 << p2);
      int maxSquare = std::max({squareMax[x1][y1][p1][p2], squareMax[x1 + shiftX][y1][p1][p2],
                                squareMax[x1][y1 + shiftY][p1][p2], squareMax[x1 + shiftX][y1 + shiftY][p1][p2]});
      if (maxSquare >= middle) {
        left = middle;
      } else {
        right = middle;
      }
    }
    return left;
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n >> m;
    data.assign(n, std::vector<int8_t>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int res;
        in >> res;
        data[i][j] = res;
      }
    }
    calcSquareSizes();
    buildSquareMax();
    buildPow2();
    int t;
    in >> t;
    for (int i = 0; i < t; i++) {
      int x1, y1, x2, y2;
      in >> x1 >> y1 >> x2 >> y2;
      x1--;y1--;
      out << find(x1, y1, x2, y2) << "\n";
    }
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}