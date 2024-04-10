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
#include <map>

const int64_t inf = 1LL << 59;

struct Solution {

  int n;
  int64_t l;
  std::vector<int> weights;
  std::vector<std::string> lines;

  size_t matSize;
  using matrix = std::vector<std::vector<int64_t>>;
  matrix step;

  std::map<std::string, int> suffixes;

  void buildMatrix() {
    suffixes[""] = 0;
    for (std::string line : lines) {
      for (size_t i = 1; i <= line.length(); i++) {
        suffixes[line.substr(0, i)] = 0;
      }
    }
    for (auto& entry : suffixes) {
      const std::string& key = entry.first;
      for (size_t i = 0; i < lines.size(); i++) {
        std::string& line = lines[i];
        if (key.length() >= line.length() && key.substr(key.length() - line.length()) == line) {
          entry.second += weights[i];
        }
      }
    }
    matSize = suffixes.size();
    step.assign(matSize, std::vector<int64_t>(matSize, -inf));
    int count = 0;
    for (auto& entry : suffixes) {
      for (char c = 'a'; c <= 'z'; c++) {
        std::string t = entry.first + c;
        while (suffixes.count(t) == 0) {
          t = t.substr(1);
        }
        int next = (int)std::distance(suffixes.begin(), suffixes.find(t));
        step[count][next] = std::max(step[count][next], int64_t(suffixes[t]));
      }
      count++;
    }
  }

  matrix multMatrix(const matrix& a, const matrix& b) {
    matrix res(matSize, std::vector<int64_t>(matSize, -inf));
    for (size_t i = 0; i < matSize; i++) {
      for (size_t j = 0; j < matSize; j++) {
        int64_t ans = -inf;
        for (size_t k= 0; k < matSize; k++) {
          ans = std::max(ans, a[i][k] + b[k][j]);
        }
        res[i][j] = ans;
      }
    }
    return res;
  }

  matrix pow(int64_t l) {
    matrix res(matSize, std::vector<int64_t>(matSize, -inf));
    for (size_t i = 0; i < matSize; i++) {
      res[i][i] = 0;
    }
    while (l > 0) {
      if (l % 2 != 0) {
        res = multMatrix(res, step);
      }
      step = multMatrix(step, step);
      l /= 2;
    }
    return res;
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n >> l;
    weights.resize(n);
    for (int i = 0; i < n; i++) {
      in >> weights[i];
    }
    lines.resize(n);
    for (int i = 0; i < n; i++) {
      in >> lines[i];
    }
    buildMatrix();
    matrix res = pow(l);
    int64_t ans = 0;
    for (size_t i = 0; i < matSize; i++) {
      ans = std::max(ans, res[0][i]);
    }
    out << ans << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}