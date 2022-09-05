#include <iostream>
#include <vector>

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  int mult2 = 0;
  while (n % 4 == 0) {
    n /= 2;
    mult2++;
  }
  std::vector<std::vector<int>> matrix;
  matrix.resize(n);
  for (int i = 0; i < n; i++) {
    matrix[i].resize(n);
  }
  for (int i = 0; i < n / 2; i++) {
    matrix[i][i + n / 2] = i + 1;
    matrix[i + n / 2][i] = i + 1;
    for (int j = 1; j < n / 2; j++) {
      matrix[(i - j + n) % n][i + j] = i + 1;
      matrix[i + j][(i - j + n) % n] = i + 1;
    }
  }
  int num = n / 2 + 1;
  for (int i = 1; i < n / 2; i += 2) {
    int cycles = gcd(i, n);
    int len = n / cycles;
    for (int j = 0; j < cycles; j++) {
      for (int k = 0; k < len; k += 2) {
        matrix[(j + k * i) % n][(j + (k + 1) * i) % n] = num;
        matrix[(j + (k + 1) * i) % n][(j + k * i) % n] = num;
        matrix[(j + (k + 1) * i) % n][(j + (k + 2) * i) % n] = num + 1;
        matrix[(j + (k + 2) * i) % n][(j + (k + 1) * i) % n] = num + 1;
      }
    }
    num += 2;
  }
  for (int mult = 0; mult < mult2; mult++) {
    std::vector<std::vector<int>> next_matrix;
    next_matrix.resize(matrix.size() * 2);
    for (int i = 0; i < next_matrix.size(); i++) {
      next_matrix[i].resize(matrix.size() * 2);
    }
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix.size(); j++) {
        next_matrix[2 * i][2 * j] = matrix[i][j] * 2;
        next_matrix[2 * i + 1][2 * j + 1] = matrix[i][j] * 2;
        next_matrix[2 * i][2 * j + 1] = matrix[i][j] * 2 + 1;
        next_matrix[2 * i + 1][2 * j] = matrix[i][j] * 2 + 1;
      }
    }
    matrix = next_matrix;
  }
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      out << matrix[i][j] << " ";
    }
    out << std::endl;
  }
}

int main() {
  run(std::cin, std::cout);
  return 0;
}