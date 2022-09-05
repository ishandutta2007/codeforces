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
#include <map>

struct DynMax {
  std::array<int, 7> congMax = {};
  //std::map<int, int> all;
  void add(int x, int value) {
    //int& v = all[x];
    //v = std::max(v, value);
    congMax[x % 7] = std::max(congMax[x % 7], value);
  }
  /*int getOpt(int x) {
    int res = 0;
    auto it = all.find(x - 1);
    if (it != all.end()) {
      res = it->second;
    }
    it = all.find(x + 1);
    if (it != all.end()) {
      res = std::max(res, it->second);
    }
    return res;
  }*/
};

struct DynMap {
  int n;
  std::vector<std::vector<int>> all;
  DynMap(int max, int n) : n(n), all(max) {};

  void add(int x, int idx, int value) {
    auto& v = all[x];
    if (v.empty()) v.resize(n);
    v[idx] = std::max(v[idx], value);
  }

  int getOpt(int x, int idx) {
    int res = all[x - 1].empty() ?  0 : all[x - 1][idx];
    res = std::max(res, all[x + 1].empty() ? 0 : all[x + 1][idx]);
    return res;
  }
};

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<int> notes(n);
  for (int i = 0; i < n; i++) {
    in >> notes[i];
  }
  std::vector<std::vector<int>> dyn(n + 1, std::vector<int>(n + 1));
  std::vector<DynMax> dynMax(n + 1);
  DynMap dynMap(100002, n + 1);
  dyn[0][0] = 0;
  for (int i = 0; i < n; i++) {
    int x = notes[i];
    for (int j = 0; j <= i; j++) {
      int maxValue = dyn[j][0];
      maxValue = std::max(maxValue, dynMax[j].congMax[x % 7]);
      maxValue = std::max(maxValue, dynMap.getOpt(x, j));
      dyn[j][i + 1] = maxValue + 1;
      dynMax[j].add(x, maxValue + 1);
      dynMap.add(x, j, maxValue + 1);
    }
    for (int j = 0; j <= i; j++) {
      dyn[i + 1][j] = dyn[j][i + 1];
      if (j > 0) {
        dynMax[i + 1].add(notes[j - 1], dyn[i + 1][j]);
        dynMap.add(notes[j - 1], i + 1, dyn[i + 1][j]);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans = std::max(dyn[i][j], ans);
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