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

const int mod = 1000000007;

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
                            const std::vector<int>& patternZ,
                            size_t maxn) {
  size_t n = view.size();
  size_t m = pattern.size();
  size_t right_bound = 0;
  size_t offset = 0;
  std::vector<int> commonZ(maxn);
  for (size_t i = 0; i < maxn; i++) {
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

std::vector<int> getCommonZ(const std::string& view,
                            const std::string& pattern,
                            const std::vector<int>& patternZ) {
  return getCommonZ(view, pattern, patternZ, view.length());
}

void run(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  std::string s;
  in >> s;
  std::vector<std::vector<int>> comp(n);
  for (int i = 1; i < n; i++) {
    comp[i].resize(i + 1);
    std::string ss = s.substr(i);
    std::vector<int> ssZ = getSelfZ(ss);
    std::vector<int> startZ = getCommonZ(s.substr(0, i), ss, ssZ);
    for (int j = 1; j <= i; j++) {
      if (startZ[i - j] >= std::min(j, n - i)) {
        comp[i][j] = 0;
      } else {
        int z = startZ[i - j];
        if (s[i - j + z] < s[i + z]) {
          comp[i][j] = -1;
        } else {
          comp[i][j] = 1;
        }
      }
    }
  }
  std::vector<std::vector<int>> dyn(n);
  dyn[0].resize(n + 1);
  for (int i = 1; i <= n; i++) {
    dyn[0][i] = 1;
  }
  for (int pos = 1; pos < n; pos++) {
    dyn[pos].resize(n + 1 - pos);
    if (s[pos] == '0') {
      continue;
    }
    int sum = 0;
    for (int len = 1; len <= n - pos; len++) {
      int nextSum = sum;
      if (len <= pos) {
        nextSum += dyn[pos - len][len];
        if (nextSum >= mod) {
          nextSum -= mod;
        }
      }
      if (len <= pos && comp[pos][len] >= 0) {
        dyn[pos][len] = sum;
      } else {
        dyn[pos][len] = nextSum;
      }
      sum = nextSum;
    }
  }
  int ans = 0;
  for (int pos = 0; pos < n; pos++) {
    ans += dyn[pos][n - pos];
    if (ans >= mod) {
      ans -= mod;
    }
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}