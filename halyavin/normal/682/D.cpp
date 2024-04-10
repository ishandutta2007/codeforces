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

std::vector<int> getSelfZ(const std::string& view) {
  size_t n = view.length();
  std::vector<int> selfZ(n);
  selfZ[0] = n;
  size_t right_bound = 1;
  size_t offset = 0;
  for (size_t i = 1; i < n; i++) {
    if (i >= right_bound || selfZ[i - offset] + i >= right_bound) {
      size_t start = std::max(i, right_bound);
      for (; start < n && view[start] == view[start - i]; start++) {
      }
      selfZ[i] = start - i;
      right_bound = start;
      offset = i;
    } else {
      selfZ[i] = selfZ[i - offset];
    }
  }
  return selfZ;
}

std::vector<int> getCommonZ(const std::string& view,
                            const std::string& pattern,
                            const std::vector<int>& patternZ) {
  size_t n = view.size();
  size_t m = pattern.size();
  size_t right_bound = 0;
  size_t offset = 0;
  std::vector<int> commonZ(view.length());
  for (size_t i = 0; i < commonZ.size(); i++) {
    if (i >= right_bound || patternZ[i - offset] + i >= right_bound) {
      size_t start = std::max(i, right_bound);
      for (; start < std::min(n, m + i) && view[start] == pattern[start - i]; start++) {
      }
      commonZ[i] = start - i;
      right_bound = start;
      offset = i;
    } else {
      commonZ[i] = patternZ[i - offset];
    }
  }
  return commonZ;
}

void run(std::istream &in, std::ostream &out) {
  std::string s;
  std::string t;
  int n, m, k;
  in >> n >> m >> k;
  in >> s >> t;
  std::vector<std::vector<int>> maxLen(n, std::vector<int>(m));
  std::string rt = t;
  std::reverse(rt.begin(), rt.end());
  for (int i = 0; i < n; i++) {
    std::string rs = s.substr(0, i + 1);
    std::reverse(rs.begin(), rs.end());
    std::vector<int> rsz = getSelfZ(rs);
    std::vector<int> rtz = getCommonZ(rt, rs, rsz);
    for (int j = 0; j < m; j++) {
      maxLen[i][j] = rtz[m - 1 - j];
    }
  }
  std::vector<std::vector<std::vector<int>>> dyn1(k, std::vector<std::vector<int>>(n, std::vector<int>(m)));
  std::vector<std::vector<std::vector<int>>> dyn2(k, std::vector<std::vector<int>>(n, std::vector<int>(m)));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int res = maxLen[i][j];
      if (i > 0) {
        res = std::max(res, dyn1[0][i - 1][j]);
      }
      if (j > 0) {
        res = std::max(res, dyn1[0][i][j-1]);
      }
      dyn1[0][i][j] = res;
    }
  }
  for (int p = 1; p < k; p++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (maxLen[i][j] == 0 || i == 0 || j == 0) {
          dyn2[p - 1][i][j] = dyn1[p - 1][i][j];
        } else {
          dyn2[p - 1][i][j] = std::max(dyn1[p - 1][i][j], dyn2[p - 1][i - 1][j - 1] + 1);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int res = dyn2[p - 1][i][j];
        if (i > 0) {
          res = std::max(res, dyn1[p][i - 1][j]);
        }
        if (j > 0) {
          res = std::max(res, dyn1[p][i][j - 1]);
        }
        dyn1[p][i][j] = res;
      }
    }
  }
  out << dyn1[k - 1][n - 1][m - 1] << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}