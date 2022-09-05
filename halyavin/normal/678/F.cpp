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

const int64_t inf = 2000000000000000000;

using TreeNode = std::vector<std::pair<int, int>>;

struct Solution {
  std::vector<std::pair<int, int>> queries; // size, q.
  std::vector<int64_t> qAnswer;
  std::vector<std::pair<int, int>> points;
  std::vector<std::pair<int, int>> pointIntervals;
  int npoints;
  std::vector<std::vector<TreeNode>> tree;

  void sortNodes(TreeNode& nodes) {
    std::sort(nodes.begin(), nodes.end());
    int size = 1;
    for (size_t i = 1; i < nodes.size(); i++) {
      if (nodes[i].first == nodes[size - 1].first) {
        nodes[size - 1] = nodes[i];
        continue;
      }
      while (size > 1) {
        std::pair<int, int>& last = nodes[size - 1];
        std::pair<int, int>& beforeLast = nodes[size - 2];
        if (int64_t(nodes[i].first - last.first) * int64_t(last.second - beforeLast.second) -
            int64_t(nodes[i].second - last.second) * int64_t(last.first - beforeLast.first) <= 0) {
          size--;
        } else {
          break;
        }
      }
      nodes[size] = nodes[i];
      size++;
    }
    nodes.resize(size);
  }

  int64_t findBest(TreeNode& nodes, int q) {
    if (nodes.empty()) {
      return -inf;
    }
    int left = 0;
    int right = (int) nodes.size();
    while (right - left > 1) {
      int middle = (left + right) / 2;
      int64_t delta = int64_t(nodes[middle].first - nodes[middle - 1].first) * q
          + (nodes[middle].second - nodes[middle - 1].second);
      if (delta >= 0) {
        left = middle;
      } else {
        right = middle;
      }
    }
    return int64_t(nodes[left].first) * q + nodes[left].second;
  }

  void buildTree() {
    tree.clear();
    int size = npoints;
    while (size) {
      tree.emplace_back(size);
      size /= 2;
    }
    for (size_t i = 0; i < points.size(); i++) {
      const std::pair<int, int>& p = points[i];
      int left = pointIntervals[i].first;
      int right = pointIntervals[i].second;
      for (int level = 0; right > left; level++) {
        if (left & 1) {
          tree[level][left].push_back(p);
          left++;
        }
        if (right & 1) {
          right--;
          tree[level][right].push_back(p);
        }
        left /= 2;
        right /= 2;
      }
    }
    for (auto& treeLevel : tree) {
      for (TreeNode& node : treeLevel) {
        if (node.size() > 2) {
          sortNodes(node);
        }
      }
    }
  }

  void calcAnswers() {
    for (size_t i = 0; i < queries.size(); i++) {
      int r = queries[i].first;
      if (r == 0) {
        continue;
      }
      int q = queries[i].second;
      int64_t ans = -inf;
      for (size_t level = 0; level < tree.size(); level++) {
        int node = (r - 1) >> level;
        if (node < tree[level].size()) {
          ans = std::max(ans, findBest(tree[level][node], q));
        }
      }
      qAnswer[i] = ans;
    }
  }

  void run(std::istream& in, std::ostream& out) {
    int n;
    in >> n;
    std::vector<int> pointIdx(n);
    int coord = 0;
    bool qs = false;
    for (int i = 0; i < n; i++) {
      int t;
      in >> t;
      if (t == 1) {
        qs = false;
        int a, b;
        in >> a >> b;
        int idx = points.size();
        pointIdx[i] = idx;
        points.emplace_back(a, b);
        pointIntervals.emplace_back(coord, -1);
      } else if (t == 2) {
        qs = false;
        int idx;
        in >> idx;
        idx = pointIdx[idx - 1];
        pointIntervals[idx].second = coord;
      } else {
        int q;
        in >> q;
        if (!qs) {
          coord++;
          qs = true;
        }
        queries.emplace_back(coord, q);
      }
    }
    npoints = qs ? coord : coord + 1;
    for (std::pair<int, int>& interval : pointIntervals) {
      if (interval.second == -1) {
        interval.second = npoints;
      }
    }
    qAnswer.assign(queries.size(), -inf);
    if (npoints != 0) {
      buildTree();
      calcAnswers();
    }
    for (size_t i = 0; i < queries.size(); i++) {
      if (qAnswer[i] == -inf) {
        out << "EMPTY SET" << "\n";
      } else {
        out << qAnswer[i] << "\n";
      }
    }
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}