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
#include <unordered_map>
#include <random>

struct Solution {
  int n;
  std::vector<std::vector<std::pair<int, int>>> graph;
  std::vector<int> treeSize;
  std::vector<std::pair<int, int>> largestSubtree;
  std::vector<int> ans;
  static constexpr int letters = 'v' - 'a' + 1;

  void dfs(int v, int prev) {
    int size = 1;
    std::pair<int, int> largestNext = {-1, 0};
    int largestSize = 0;
    for (const std::pair<int, int>& edge : graph[v]) {
      int nv = edge.first;
      if (nv == prev) {
        continue;
      }
      dfs(nv, v);
      size += treeSize[nv];
      if (treeSize[nv] > largestSize) {
        largestSize = treeSize[nv];
        largestNext = edge;
      }
    }
    treeSize[v] = size;
    largestSubtree[v] = largestNext;
  }

  struct TreeResult {
    std::unordered_map<int, int> map;
    int maskShift = 0;
    int valueShift = 0;
    TreeResult() = default;
    TreeResult(const TreeResult&) = default;
    TreeResult(TreeResult&&) = default;
    TreeResult& operator=(const TreeResult&) = default;
    TreeResult& operator=(TreeResult&&) = default;
  };

  void updateAns(const TreeResult& res, int mask, int value, int& curAns) {
    auto it = res.map.find(mask ^ res.maskShift);
    if (it != res.map.end()) {
      curAns = std::max(curAns, it->second + res.valueShift + value);
    }
  }

  void updateAnsFull(const TreeResult& res, int mask, int value, int& curAns) {
    if (res.map.size() <= 31) {
      for (const auto& entry : res.map) {
        int diff = mask ^ entry.first ^ res.maskShift;
        if (diff == 0 || (diff & (diff - 1)) == 0) {
          curAns = std::max(curAns, value + res.valueShift + entry.second);
        }
      }
    } else {
      updateAns(res, mask, value, curAns);
      for (int i = 0; i < letters; i++) {
        updateAns(res, mask ^ (1 << i), value, curAns);
      }
    }
  }

  TreeResult dfsAns(int v, int prev) {
    TreeResult res;
    int curAns = 0;
    std::pair<int, int> largestEdge = largestSubtree[v];
    int& nv = largestEdge.first;
    if (nv == -1) {
      res.map[0] = 0;
      ans[v] = 0;
      return res;
    }
    res = dfsAns(nv, v);
    curAns = std::max(curAns, ans[nv]);
    res.valueShift++;
    res.maskShift ^= largestEdge.second;
    updateAnsFull(res, 0, 0, curAns);
    res.map.reserve(treeSize[v]);
    for (const std::pair<int, int>& edge : graph[v]) {
      if (edge.first == nv || edge.first == prev) {
        continue;
      }
      TreeResult res2 = dfsAns(edge.first, v);
      curAns = std::max(curAns, ans[edge.first]);
      res2.valueShift++;
      res2.maskShift ^= edge.second;
      updateAnsFull(res2, 0, 0, curAns);
      for (const auto& entry : res2.map) {
        int mask = entry.first ^ res2.maskShift;
        int value = entry.second + res2.valueShift;
        updateAnsFull(res, mask, value, curAns);
      }
      for (const auto& entry : res2.map) {
        int mask = entry.first ^ res2.maskShift;
        int value = entry.second + res2.valueShift;
        auto emplace_res = res.map.emplace(mask ^ res.maskShift, value - res.valueShift);
        if (!emplace_res.second) {
          emplace_res.first->second = std::max(emplace_res.first->second, value - res.valueShift);
        }
        /* auto it = res.map.find(mask ^ res.maskShift);
        if (it == res.map.end()) {
          res.map.emplace(mask ^ res.maskShift, value - res.valueShift);
        } else {
          it->second = std::max(it->second, value - res.valueShift);
        } */
      }
    }
    auto it = res.map.find(res.maskShift);
    if (it == res.map.end()) {
      res.map.emplace(res.maskShift, -res.valueShift);
    } else {
      it->second = std::max(it->second, -res.valueShift);
    }
    ans[v] = curAns;
    return res;
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n;
    graph.assign(n, std::vector<std::pair<int, int>>());
    treeSize.assign(n, 0);
    largestSubtree.assign(n, std::pair<int, int>(0, 0));
    for (int i = 0; i < n - 1; i++) {
      int v = i + 1;
      int nv;
      char label;
      in >> nv >> label;
      nv--;
      int labelMask = 1 << (int)(label - 'a');
      graph[v].emplace_back(nv, labelMask);
      graph[nv].emplace_back(v, labelMask);
    }
    /* {
      n = 500001;
      std::mt19937 rnd(123);
      graph.assign(n, std::vector<std::pair<int, int>>());
      treeSize.assign(n, 0);
      largestSubtree.assign(n, std::pair<int, int>(0, 0));
      for (int i = 0; i < n - 1; i += 2) {
        int v = i + 1;
        int nv = i / 2;
        int labelMask = 1 << (rnd() % 23);
        graph[v].emplace_back(nv, labelMask);
        graph[nv].emplace_back(v, labelMask);
        v = i + 2;
        labelMask = 1 << (rnd() % 23);
        graph[v].emplace_back(nv, labelMask);
        graph[nv].emplace_back(v, labelMask);
      }
    } */
    dfs(0, -1);
    ans.assign(n, 0);
    dfsAns(0, -1);
    for (int i = 0; i < n; i++) {
      out << ans[i] << " ";
    }
    out << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}