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

template<class T>
std::pair<T, T> gcd2(T x, T y) {
  if (x == 0) {
    return {0, 1};
  }
  T s = y / x;
  std::pair<T, T> res = gcd2(y % x, x);
  return {res.second - s * res.first, res.first};
}

template<class T>
T inv(T x, T p) {
  x = x % p;
  if (x < 0) {
    x += p;
  }
  std::pair<T, T> res = gcd2(x, p);
  if (res.first < 0) {
    res.first += p;
  }
  if (res.first >= p) {
    res.first -= p;
  }
  return res.first;
}

struct Solution {
  int s, t;
  std::vector<std::vector<int>> sTree;
  std::vector<std::vector<int>> tTree;
  std::vector<int> hash;
  std::vector<std::vector<int>> color;
  std::vector<std::vector<int>> allColors;
  int colors;
  std::vector<std::vector<int>> dyn;
  std::vector<std::pair<int, int>> edges;
  std::vector<std::vector<int>> vEdges;

  int tHashDfs(int v, int prev) {
    std::vector<int> color;
    for (int nv : tTree[v]) {
      if (nv == prev) continue;
      color.push_back(tHashDfs(nv, v));
    }
    std::sort(color.begin(), color.end());
    auto it = std::find(allColors.begin(),allColors.end(), color);
    int result = it - allColors.begin();
    if (it == allColors.end()) {
      allColors.push_back(color);
    }
    return result;
  }

  int calcTHash() {
    hash.resize(t);
    color.resize(t);
    allColors.clear();
    int result = tHashDfs(0, -1);
    colors = allColors.size();
    return result;
  }

  void calcSEdges() {
    edges.clear();
    vEdges.assign(s, std::vector<int>());
    for (int i = 0; i < s; i++) {
      std::vector<int>& curEdges = vEdges[i];
      curEdges.push_back(edges.size());
      edges.emplace_back(i, -1);
      for (int nv : sTree[i]) {
        curEdges.push_back(edges.size());
        edges.emplace_back(i, nv);
      }
    }
  }

  void calcDyn(int color) {
    std::vector<int> prevColors = allColors[color];
    std::vector<std::pair<int, int>> prevColorsStats;
    for (size_t i = 0; i < prevColors.size(); i++) {
      if (i == 0 || prevColors[i] != prevColors[i - 1]) {
        size_t j = i + 1;
        while (j < prevColors.size() && prevColors[j] == prevColors[i]) {
          j++;
        }
        prevColorsStats.emplace_back(prevColors[i], j - i);
      }
    }
    int dynSize = 1;
    std::vector<int> shifts;
    std::vector<int> dimSize;
    for (std::pair<int, int>& stat : prevColorsStats) {
      shifts.push_back(dynSize);
      dimSize.push_back(stat.second + 1);
      dynSize *= stat.second + 1;
    }

    std::vector<int> v1(dynSize);
    std::vector<int> v2(dynSize);
    for (size_t i = 0; i < edges.size(); i++) {
      int v = edges[i].first;
      int prev = edges[i].second;
      std::fill(v1.begin(), v1.end(), 0);
      v1[0] = 1;
      for (int nv : sTree[v]) {
        if (nv == prev) continue;
        int backEdge = -1;
        for (int e : vEdges[nv]) {
          if (edges[e].second == v) {
            backEdge = e;
            break;
          }
        }
        std::copy(v1.begin(), v1.end(), v2.begin());
        for (size_t j = 0; j < shifts.size(); j++) {
          int shift = shifts[j];
          int color = prevColorsStats[j].first;
          int mult = dyn[color][backEdge];
          for (size_t k = shift; k < v2.size(); k++) {
            if ((k / shift) % dimSize[j] != 0) {
              v2[k] = (v2[k] + int64_t(v1[k - shift]) * mult) % mod;
            }
          }
        }
        std::swap(v1, v2);
      }
      dyn[color][i] = v1[dynSize - 1];
    }
  }

  void run(std::istream& in, std::ostream& out) {
    in >> s;
    sTree.assign(s, std::vector<int>());
    for (int i = 0; i < s - 1; i++) {
      int from, to;
      in >> from >> to;
      from--;
      to--;
      sTree[from].push_back(to);
      sTree[to].push_back(from);
    }
    in >> t;
    tTree.assign(t, std::vector<int>());
    for (int i = 0; i < t - 1; i++) {
      int from, to;
      in >> from >> to;
      from--;
      to--;
      tTree[from].push_back(to);
      tTree[to].push_back(from);
    }
    calcSEdges();
    int root = calcTHash();
    int groupSize = 1;
    for (int i = 1; i < t; i++) {
      if (tHashDfs(i, -1) == root) {
        groupSize++;
      }
    }
    allColors.resize(colors);
    dyn.resize(colors);
    for (int color = 0; color < colors; color++) {
      dyn[color].assign(edges.size(), 0);
      calcDyn(color);
    }
    int ans = 0;
    for (size_t i = 0; i < edges.size(); i++) {
      if (edges[i].second == -1) {
        ans = (ans + dyn[colors - 1][i]) % mod;
      }
    }
    int d = inv(groupSize, mod);
    ans = (ans * int64_t(d)) % mod;
    out << ans << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}