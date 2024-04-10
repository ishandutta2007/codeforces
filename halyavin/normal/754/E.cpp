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
#include <complex>
#include <cmath>

constexpr double pi = 3.14159265358979323;

struct Solution {
  int n, m;
  std::vector<std::vector<std::complex<double>>> matrix1;
  std::vector<std::vector<std::complex<double>>> matrix2;

  void furier(std::vector<std::vector<std::complex<double>>>& matrix, bool rev) {
    std::vector<std::complex<double>> v1(n);
    std::vector<std::complex<double>> v2(m);
    for (int i = 0; i < n; i++) {
      double angle = 2 * pi * i / n;
      if (rev) angle = -angle;
      v1[i].real(cos(angle));
      v1[i].imag(sin(angle));
    }
    for (int i = 0; i < m; i++) {
      double angle = 2 * pi * i / m;
      if (rev) angle = -angle;
      v2[i].real(cos(angle));
      v2[i].imag(sin(angle));
    }
    std::vector<std::complex<double>> tmp(std::max(n, m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        tmp[j] = 0;
        for (int k = 0; k < m; k++) {
          tmp[j] += matrix[i][k] * v2[(j * k) % m];
        }
      }
      for (int j = 0; j < m; j++) {
        matrix[i][j] = tmp[j];
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        tmp[j] = 0;
        for (int k = 0; k < n; k++) {
          tmp[j] += matrix[k][i] * v1[(j * k) % n];
        }
      }
      for (int j = 0; j < n; j++) {
        matrix[j][i] = tmp[j];
      }
    }
  }

  bool isBig(std::complex<double> v) {
    return std::abs(v.real()) > 1e-3 || std::abs(v.imag()) > 1e-3;
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n >> m;
    matrix1.clear();
    matrix1.resize(n);
    for (int i = 0; i < n; i++) {
      matrix1[i].resize(m);
    }
    for (int i = 0; i < n; i++) {
      std::string s;
      in >> s;
      for (int j = 0; j < m; j++) {
        double angle = 2 * pi * (s[j] - 'a') / 26.0;
        matrix1[i][j].real(cos(angle));
        matrix1[i][j].imag(sin(angle));
      }
    }
    matrix2.clear();
    matrix2.resize(n);
    for (int i = 0; i < n; i++) {
      matrix2[i].resize(m);
    }
    int r, c;
    in >> r >> c;
    int count = 0;
    bool good = true;
    for (int i = 0; i < r; i++) {
      std::string s;
      in >> s;
      for (int j = 0; j < c; j++) {
        if (s[j] != '?') {
          int pix = (n - (i % n)) % n;
          int pjx = (m - (j % m)) % m;
          count++;
          double angle = 2 * pi * -(s[j] - 'a') / 26.0;
          std::complex<double> v(cos(angle), sin(angle));
          if (isBig(matrix2[pix][pjx])) {
            count--;
            if (isBig(matrix2[pix][pjx] - v)) {
              good = false;
              continue;
            }
          }
          matrix2[pix][pjx] = v;
        }
      }
    }
    furier(matrix1, false);
    furier(matrix2, false);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        matrix1[i][j] *= matrix2[i][j];
      }
    }
    furier(matrix1, true);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix1[i][j].real() / (n * m) > count - 1e-3 && good) {
          out << "1";
        } else {
          out << "0";
        }
      }
      out << std::endl;
    }
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}