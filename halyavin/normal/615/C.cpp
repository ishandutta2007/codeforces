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

void run(std::istream& in, std::ostream& out) {
  std::string s, ss;
  std::string t;
  in >> s >> t;
  ss = s;
  std::reverse(ss.begin(), ss.end());
  int n = t.length();
  const int inf = 100000;
  std::vector<int> dyn(n + 1, inf);
  std::vector<std::pair<int, int>> prev(n + 1);
  dyn[0] = 0;
  for (int i = 1; i <= n; i++) {
    std::string subT = t.substr(0, i);
    std::reverse(subT.begin(), subT.end());
    std::vector<int> subTZ = getSelfZ(subT);
    std::vector<int> zs = getCommonZ(s, subT, subTZ, s.length());
    std::vector<int> zss = getCommonZ(ss, subT, subTZ, ss.length());
    int maxi = -1, maxj = -1, maxv = 0;
    for (int j = 0; j < zs.size(); j++) {
      if (zs[j] > maxv) {
        maxv = zs[j];
        maxj = j;
        maxi = j + zs[j] - 1;
      }
    }
    for (int j = 0; j < zss.size(); j++) {
      if (zss[j] > maxv) {
        maxv = zss[j];
        maxj = zss.size() - j - 1;
        maxi = maxj - zss[j] + 1;
      }
    }
    for (int j = i - maxv; j < i; j++) {
      if (dyn[j] + 1 < dyn[i]) {
        int len = i - j;
        dyn[i] = dyn[j] + 1;
        if (maxi > maxj) {
          prev[i].first = maxj + len - 1;
          prev[i].second = maxj;
        } else {
          prev[i].first = maxj - len + 1;
          prev[i].second = maxj;
        }
      }
    }
  }
  if (dyn[n] == inf) {
    out << "-1" << std::endl;
    return;
  }
  out << dyn[n] << std::endl;
  std::vector<std::pair<int, int>> ans;
  int cur = n;
  while (cur > 0) {
    ans.push_back(prev[cur]);
    cur -= std::abs(prev[cur].first - prev[cur].second) + 1;
  }
  std::reverse(ans.begin(), ans.end());
  for (std::pair<int, int>& idx : ans) {
    out << idx.first + 1 << "  " << idx.second + 1 << "\n";
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}