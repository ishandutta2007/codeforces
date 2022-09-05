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

uint32_t rd() {
  uint32_t res;
#ifdef __MINGW32__
  asm volatile("rdrand %0" :"=a"(res) ::"cc");
#else
  res = std::random_device()();
#endif
  return res;
}

class IHash {
  uint64_t hash_mult1;
  uint64_t hash_mult2;
 public:
  void init() {
    while ((hash_mult1 = (uint64_t(rd()) << 32) + rd()) < (1ull << 32));
    while ((hash_mult2 = (uint64_t(rd()) << 32) + rd()) < (1ull << 32));
  }
  uint64_t operator()(uint64_t v) {
    return ((uint64_t(v) * hash_mult1) >> 32) ^ (uint64_t(v) * hash_mult2) + 18723123817ULL ^ (v >> 32);
  }
};

struct ColorStat {
  std::vector<int> stat;
  int different;
  ColorStat(int colors) {
    stat.resize(colors);
    different = 0;
  }

  void add(int c) {
    stat[c]++;
    if (stat[c] == 1) different++;
  }
  void remove(int c) {
    stat[c]--;
    if (stat[c] == 0) different--;
  }

};

struct Solution {
  std::vector<std::vector<int>> graph;
  std::map<uint64_t, int> colorMap;
  std::vector<std::vector<int>> edgeColor;
  std::vector<std::vector<uint64_t>> edgeHash;
  std::vector<std::vector<std::vector<uint32_t>>> masks;
  int colors;
  int n;
  size_t maskLength;
  IHash hash;
  int ans;
  int opt;

  int getColor(uint64_t hash) {
    auto it = colorMap.find(hash);
    if (it == colorMap.end()) {
      colorMap[hash] = colors;
      return colors++;
    }
    return it->second;
  }

  void colorDfs(int prev, int edge) {
    int v = graph[prev][edge];
    uint64_t sum = 0;
    for (size_t i = 0; i < graph[v].size(); i++) {
      int nv = graph[v][i];
      if (nv == prev) continue;
      colorDfs(v, i);
      sum += edgeHash[v][i];
    }
    uint64_t vhash = hash(sum);
    edgeHash[prev][edge] = vhash;
    edgeColor[prev][edge] = getColor(vhash);
  }

  void colorDfs2(int v, int prev, uint64_t prevSum) {
    uint64_t sum = prevSum;
    for (size_t i = 0; i < graph[v].size(); i++) {
      int nv = graph[v][i];
      if (nv == prev) {
        edgeHash[v][i] = prevSum;
        edgeColor[v][i] = getColor(prevSum);
        continue;
      }
      sum += edgeHash[v][i];
    }
    for (size_t i = 0; i < graph[v].size(); i++) {
      int nv = graph[v][i];
      if (nv != prev) {
        colorDfs2(nv, v, hash(sum - edgeHash[v][i]));
      }
    }
  }

  void dfs1(int v, int prev, ColorStat& stat) {
    for (size_t i = 0; i < graph[v].size(); i++) {
      int nv = graph[v][i];
      if (nv == prev) continue;
      stat.add(edgeColor[v][i]);
      dfs1(nv, v, stat);
    }
  }

  void dfs2(int v, int prev, ColorStat& stat) {
    int c = -1;
    for (size_t i = 0; i < graph[v].size(); i++) {
      int nv = graph[v][i];
      if (nv == prev) {
        c = edgeColor[v][i];
        stat.add(edgeColor[v][i]);
      }
    }
    if (stat.different > opt) {
      opt = stat.different;
      ans = v;
    }
    for (size_t i = 0; i < graph[v].size(); i++) {
      int nv = graph[v][i];
      if (nv == prev) continue;
      stat.remove(edgeColor[v][i]);
      dfs2(nv, v, stat);
      stat.add(edgeColor[v][i]);
    }
    if (c != -1) {
      stat.remove(c);
    }
  }

  void run(std::istream& in, std::ostream& out) {
    hash.init();
    in >> n;
    graph.assign(n, std::vector<int>());
    edgeColor.assign(n, std::vector<int>());
    edgeHash.assign(n, std::vector<uint64_t>());
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      in >> x >> y;
      x--;
      y--;
      graph[x].push_back(y);
      graph[y].push_back(x);
      edgeColor[x].push_back(-1);
      edgeColor[y].push_back(-1);
      edgeHash[x].push_back(0);
      edgeHash[y].push_back(0);
    }
    colors = 0;
    colorMap.clear();
    for (size_t i = 0; i < graph[0].size(); i++) {
      colorDfs(0, i);
    }
    colorDfs2(0, -1, 0);
    ColorStat stats(colors);
    dfs1(0, -1, stats);
    ans = 0;
    opt = stats.different;
    dfs2(0, -1, stats);
    out << (ans + 1) << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}