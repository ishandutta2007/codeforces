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

const uint32_t mod = 1000000007;

struct mult {
  int deg2;
  int deg3;
  int zero;
  mult() : deg2(0), deg3(0), zero(0) {
  }

  uint32_t get() {
    if (zero > 0) return 0;
    uint32_t res = 1;
    for (int i = 0; i < deg2; i++) {
      res = (res * 2) % mod;
    }
    for (int i = 0; i < deg3; i++) {
      res = (res * 3) % mod;
    }
    return res;
  }

  void multiply(int x) {
    if (x == 0) {
      zero++;
      return;
    }
    if (x == 1) {
      return;
    }
    if (x == 2) {
      deg2++;
      return;
    }
    if (x == 3) {
      deg3++;
    }
  }

  void divide(int x) {
    if (x == 0) {
      zero--;
      return;
    }
    if (x == 1) {
      return;
    }
    if (x == 2) {
      deg2--;
      return;
    }
    if (x == 3) {
      deg3--;
      return;
    }
  }

  int compare(mult& other) {
    if (zero > 0) {
      return other.zero > 0 ? 0 : -1;
    }
    if (other.zero > 0) return 1;
    if (deg2 == other.deg2 && deg3 == other.deg3) return 0;
    return deg2 * log(2) + deg3 * log(3) > other.deg2 * log(2) + other.deg3 * log(3) ? 1 : -1;
  }

  mult add(mult other) {
    mult res;
    res.zero = zero + other.zero;
    res.deg2 = deg2 + other.deg2;
    res.deg3 = deg3 + other.deg3;
    return res;
  }

  mult sub(mult other) {
    mult res;
    res.zero = zero - other.zero;
    res.deg2 = deg2 - other.deg2;
    res.deg3 = deg3 - other.deg3;
    return res;
  }
};

mult vertCross(int n, std::vector<std::vector<int>>& matrix) {
  std::vector<std::vector<std::array<int, 4>>> zeroDist(n, std::vector<std::array<int, 4>>(n));
  for (int i = 0; i < n; i++) {
    zeroDist[i][0][0] = matrix[i][0] == 0 ? 0 : 1;
    for (int j = 1; j < n; j++) {
      if (matrix[i][j] == 0) {
        zeroDist[i][j][0] = 0;
      } else {
        zeroDist[i][j][0] = zeroDist[i][j - 1][0] + 1;
      }
    }
    zeroDist[i][n - 1][2] = matrix[i][n - 1] == 0 ? 0 : 1;
    for (int j = n - 2; j >= 0; j--) {
      if (matrix[i][j] == 0) {
        zeroDist[i][j][2] = 0;
      } else {
        zeroDist[i][j][2] = zeroDist[i][j + 1][2] + 1;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    zeroDist[0][i][1] = matrix[0][i] == 0 ? 0 : 1;
    for (int j = 1; j < n; j++) {
      if (matrix[j][i] == 0) {
        zeroDist[j][i][1] = 0;
      } else {
        zeroDist[j][i][1] = zeroDist[j - 1][i][1] + 1;
      }
    }
    zeroDist[n - 1][i][3] = matrix[n - 1][i] == 0 ? 0 : 1;
    for (int j = n - 2; j >= 0; j--) {
      if (matrix[j][i] == 0) {
        zeroDist[j][i][3] == 0;
      } else {
        zeroDist[j][i][3] = zeroDist[j + 1][i][3] + 1;
      }
    }
  }

  std::vector<std::vector<mult>> vert(n, std::vector<mult>(n + 1));
  std::vector<std::vector<mult>> hor(n, std::vector<mult>(n + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vert[i][j + 1] = vert[i][j];
      vert[i][j + 1].multiply(matrix[i][j]);
      hor[i][j + 1] = hor[i][j];
      hor[i][j + 1].multiply(matrix[j][i]);
    }
  }
  mult opt;
  opt.zero = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int d = std::min({zeroDist[i][j][0], zeroDist[i][j][1], zeroDist[i][j][2], zeroDist[i][j][3]});
      if (d != 0) {
        d--;
        mult res = vert[i][j + d + 1].sub(vert[i][j - d]);
        res = res.add(hor[j][i + d + 1].sub(hor[j][i - d]));
        res.divide(matrix[i][j]);
        if (opt.compare(res) < 0) {
          opt = res;
        }
      }
    }
  }
  return opt;
}

const int dx[4] = {1, -1, 1, -1};
const int dy[4] = {1, -1, -1, 1};

mult diagCross(int n, std::vector<std::vector<int>>& matrix) {
  mult opt;
  opt.zero = 1;
  std::vector<std::vector<std::array<int, 4>>> zeroDist(n, std::vector<std::array<int, 4>>(n));
  for (int dir = 0; dir < 4; dir++) {
    int ddx = dx[dir];
    int ddy = dy[dir];
    if (ddx > 0) {
      for (int iy = 0; iy < n; iy++) {
        int y = iy;
        int x = 0;
        zeroDist[x][y][dir] = matrix[x][y] == 0 ? 0 : 1;
        for (; x < n;) {
          x += ddx;
          y += ddy;
          if (y < 0 || y >= n) break;
          if (matrix[x][y] == 0) {
            zeroDist[x][y][dir] = 0;
          } else {
            zeroDist[x][y][dir] = zeroDist[x - ddx][y - ddy][dir] + 1;
          }
        }
      }
    } else {
      for (int iy = 0; iy < n; iy++) {
        int y = iy;
        int x = n - 1;
        zeroDist[x][y][dir] = matrix[x][y] == 0 ? 0 : 1;
        for (; x >= 0;) {
          x += ddx;
          y += ddy;
          if (y < 0 || y >= n) break;
          if (matrix[x][y] == 0) {
            zeroDist[x][y][dir] = 0;
          } else {
            zeroDist[x][y][dir] = zeroDist[x - ddx][y - ddy][dir] + 1;
          }
        }
      }
    }
    if (ddy > 0) {
      for (int ix = 0; ix < n; ix++) {
        int x = ix;
        int y = 0;
        zeroDist[x][y][dir] = matrix[x][y] == 0 ? 0 : 1;
        for (; y < n;) {
          x += ddx;
          y += ddy;
          if (x < 0 || x >= n) break;
          if (matrix[x][y] == 0) {
            zeroDist[x][y][dir] = 0;
          } else {
            zeroDist[x][y][dir] = zeroDist[x - ddx][y - ddy][dir] + 1;
          }
        }
      }
    } else {
      for (int ix = 0; ix < n; ix++) {
        int x = ix;
        int y = n - 1;
        zeroDist[x][y][dir] = matrix[x][y] == 0 ? 0 : 1;
        for (; y >= 0;) {
          x += ddx;
          y += ddy;
          if (x < 0 || x >= n) break;
          if (matrix[x][y] == 0) {
            zeroDist[x][y][dir] = 0;
          } else {
            zeroDist[x][y][dir] = zeroDist[x - ddx][y - ddy][dir] + 1;
          }
        }
      }
    }
  }
  std::vector<std::vector<mult>> diag1(2 * n - 1, std::vector<mult>(n + 1));
  for (int u = 0; u < 2 * n - 1; u++) {
    for (int x = 0; x < n; x++) {
      int y = u - x;
      diag1[u][x + 1] = diag1[u][x];
      if (y >= 0 && y < n) {
        diag1[u][x + 1].multiply(matrix[x][y]);
      }
    }
  }
  std::vector<std::vector<mult>> diag2(2 * n - 1, std::vector<mult>(n + 1));
  for (int u = 0; u < 2 * n - 1; u++) {
    for (int x = 0; x < n; x++) {
      int y = x + (n - 1) - u;
      diag2[u][x + 1] = diag2[u][x];
      if (y >= 0 && y < n) {
        diag2[u][x + 1].multiply(matrix[x][y]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int d = std::min({zeroDist[i][j][0], zeroDist[i][j][1], zeroDist[i][j][2], zeroDist[i][j][3]});
      if (d != 0) {
        d--;
        mult res = diag1[i + j][i + d + 1].sub(diag1[i+j][i - d]);
        res = res.add(diag2[i - j + (n - 1)][i + d + 1].sub(diag2[i - j + (n - 1)][i - d]));
        res.divide(matrix[i][j]);
        if (opt.compare(res) < 0) {
          opt = res;
        }
      }
    }
  }
  return opt;
}

void run(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
  for (int i = 0; i < n; i++) {
    std::string s;
    in >> s;
    for (int j = 0; j < n; j++) {
      matrix[i][j] = s[j] - '0';
    }
  }
  mult opt = vertCross(n, matrix);
  mult opt2 = diagCross(n, matrix);
  if (opt.compare(opt2) < 0) {
    opt = opt2;
  }


//  std::vector<mult> diag1(2 * n - 1);
//  std::vector<mult> diag2(2 * n - 1);
//  for (int i = 0; i < 2 * n - 1; i++) {
//    for (int j = 0; j < n; j++) {
//      int k = i - j;
//      if (k >= 0 && k < n) {
//        diag1[i].multiply(matrix[j][k]);
//      }
//      k = j + n - 1 - i;
//      if (k >= 0 && k < n) {
//        diag2[i].multiply(matrix[j][k]);
//      }
//    }
//  }
//  for (int i = 0; i < n; i++) {
//    for (int j = 0; j < n; j++) {
//      int d1 = i + j;
//      int d2 = i - j + n - 1;
//      mult x = diag1[d1].multiply(diag2[d2]);
//      x.divide(matrix[i][j]);
//      if (opt.compare(x) < 0) {
//        opt = x;
//      }
//    }
//}
  out << opt.get() << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}