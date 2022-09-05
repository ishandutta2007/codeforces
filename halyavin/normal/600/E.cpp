#ifdef __GNUC__
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,bmi,fma,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <unordered_map>

uint64_t hash_mult1;

uint32_t rd() {
  uint32_t res;
#ifdef __MINGW32__
  asm volatile("rdrand %0" :"=a"(res) ::"cc");
#else
  res = std::random_device()();
#endif
  return res;
}

void init_hash() {
  while ((hash_mult1 = (uint64_t(rd()) << 32) + rd()) < (1ull << 32))
    ;
}

struct IHash {
  uint32_t operator()(int v) const {
    return (uint64_t(v) * hash_mult1) >> 32;
  }
};

struct Problem {
  int n;
  std::vector<std::vector<int>> g;
  std::vector<int> colors;
  std::vector<int> subtreeSize;
  std::vector<int64_t> ans;
  int fillSize(int v, int prev) {
    int res = 1;
    for (int nv : g[v]) {
      if (nv != prev) {
        res += fillSize(nv, v);
      }
    }
    subtreeSize[v] = res;
    return res;
  }
  using umap = std::unordered_map<int, int, IHash>;
  struct Ans {
    umap map;
    int max;
    int64_t sum;
  };
  Ans getAns(int v, int prev) {
    if (g[v].size() == 1 && prev >= 0) {
      ans[v] = colors[v];
      Ans result;
      result.map[colors[v]] = 1;
      result.max = 1;
      result.sum = colors[v];
      return result;
    }
    int imax = -1;
    int max = -1;
    for (size_t i = 0; i < g[v].size(); i++) {
      if (g[v][i] == prev) {
        continue;
      }
      if (subtreeSize[g[v][i]] > max) {
        max = subtreeSize[g[v][i]];
        imax = i;
      }
    }
    Ans result = getAns(g[v][imax], v);
    for (size_t i = 0; i < g[v].size(); i++) {
      if (i != size_t(imax) && g[v][i] != prev) {
        Ans small = getAns(g[v][i], v);
        for (std::pair<const int, int>& entry : small.map) {
          int res = result.map[entry.first] += entry.second;
          if (res > result.max) {
            result.max = res;
            result.sum = entry.first;
          } else if (res == result.max) {
            result.sum += entry.first;
          }
        }
      }
    }
    int res = result.map[colors[v]] += 1;
    if (res > result.max) {
      result.max = res;
      result.sum = colors[v];
    } else if (res == result.max) {
      result.sum += colors[v];
    }
    ans[v] = result.sum;
    return result;
  }
  void run(std::istream &in, std::ostream &out) {
    init_hash();
    in >> n;
    g.resize(n);
    colors.resize(n);
    subtreeSize.resize(n);
    for (int i = 0; i < n; i++) {
      in >> colors[i];
    }
    for (int i = 0; i < n - 1; i++) {
      int from, to;
      in >> from >> to;
      from--;
      to--;
      g[from].push_back(to);
      g[to].push_back(from);
    }
    fillSize(0, -1);
    ans.resize(n);
    getAns(0, -1);
    for (size_t i = 0; i < ans.size(); i++) {
      out << ans[i] << " ";
    }
    out << std::endl;
  }

};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Problem().run(std::cin, std::cout);
  return 0;
}