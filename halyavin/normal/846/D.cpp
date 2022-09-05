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
struct Pixel {
  int x, y, t;
  Pixel() : x(0), y(0), t(0) {}
  Pixel(int x, int y, int t) : x(x),  y(y), t(t) {}
};

struct Solution {
  int n, m, k;
  std::vector<Pixel> pixels;
  std::vector<std::vector<int>> field;
  std::vector<std::vector<int>> field2;
  bool check(int t) {
    for (int i = 0; i < n; i++) {
      std::fill(field[i].begin(), field[i].end(), 0);
    }
    for (auto& pixel : pixels) {
      if (pixel.t <= t) {
        field[pixel.x][pixel.y] = 1;
      }
    }
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = 0; j < k; j++) {
        sum += field[i][j];
      }
      field2[i][0] = sum;
      for (int j = 1; j <= m - k; j++) {
        sum += field[i][j + k - 1] - field[i][j - 1];
        field2[i][j] = sum;
      }
    }
    std::swap(field, field2);
    for (int i = 0; i <= m - k; i++) {
      int sum = 0;
      for (int j = 0; j < k; j++) {
        sum += field[j][i];
      }
      field2[0][i] = sum;
      for (int j = 1; j <= n - k; j++) {
        sum += field[j + k - 1][i] - field[j - 1][i];
        field2[j][i] = sum;
      }
    }
    for (int i = 0; i <= n - k; i++) {
      for (int j = 0; j <= m - k; j++) {
        if (field2[i][j] == k * k) {
          return true;
        }
      }
    }
    return false;
  }
  void run(std::istream& in, std::ostream& out) {
    in >> n >> m >> k;
    int q;
    in >> q;
    pixels.resize(q);
    for (int i = 0; i < q; i++) {
      in >> pixels[i].x >> pixels[i].y >> pixels[i].t;
      pixels[i].x--;
      pixels[i].y--;
    }
    field.assign(n, std::vector<int>(m));
    field2.assign(n, std::vector<int>(m));
    int left = -1;
    int right = 1000000001;
    while (right - left > 1) {
      int middle = (right + left) / 2;
      if (check(middle)) {
        right = middle;
      } else {
        left = middle;
      }
    }
    if (right > 1000000000) {
      std::cout << -1 << std::endl;
    } else {
      std::cout << right << std::endl;
    }
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}