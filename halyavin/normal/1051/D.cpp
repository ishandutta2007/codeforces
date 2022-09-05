#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <array>

const int mod = 998244353;

int add32(int x, int y) {
  int res = x + y;
  if (res >= mod) res -= mod;
  return res;
}

std::array<std::array<int, 4>, 4> table = {{{{0, 1, 1, 1}}, {{0, 0, 2, 0}}, {{0, 2, 0, 0}}, {{1, 1, 1, 0}}}};

void run(std::istream &in, std::ostream &out) {
    int n, k;
    in >> n >> k;
    std::vector<std::vector<std::array<int, 4>>> dyn(n, std::vector<std::array<int, 4>>(2 * n + 1));
    dyn[0][1][0] = 1;
    dyn[0][1][3] = 1;
    dyn[0][2][1] = 1;
    dyn[0][2][2] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= 2 * i; j++) {
            auto& v = dyn[i - 1][j];
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 4; l++) {
                    dyn[i][j + table[k][l]][l] = add32(dyn[i][j + table[k][l]][l], v[k]);
                }
            }
        }
    }
    int final = 0;
    for (int i = 0; i < 4; i++) {
        final = add32(final, dyn[n - 1][k][i]);
    }
    out << final << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}