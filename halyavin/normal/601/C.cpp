#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
  int n, m;
  in >> n >> m;
  std::vector<int> x(n);
  for (int i = 0; i < n; i++) {
    in >> x[i];
    x[i]--;
  }
  std::vector<double> dyn[2];
  dyn[0].resize((m - 1) * n + 1);
  dyn[1].resize((m - 1) * n + 1);
  dyn[0][0] = m - 1;
  int cur = 0;
  int next = 1;
  for (int it = 0; it < n; it++) {
    double sum = 0;
    for (size_t i = 0; i < dyn[cur].size(); i++) {
      sum += dyn[cur][i];
      if (i >= m) {
        sum -= dyn[cur][i - m];
      }
      double res = i >= x[it] ? sum - dyn[cur][i-x[it]] : sum;
      dyn[next][i] = res / (m - 1);
    }
    std::swap(cur, next);
  }
  int score = std::accumulate(x.begin(), x.end(), 0);
  double res = 0;
  for (int i = 0; i < score; i++) {
    res += dyn[cur][i];
  }
  out.precision(12);
  out << std::fixed;
  out << (res + 1) << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}