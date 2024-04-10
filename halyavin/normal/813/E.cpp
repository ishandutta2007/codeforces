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

struct Node {
  int l = -1;
  int r = -1;
  int mod = 0;
};

struct Solution {
  std::vector<Node> tree;
  std::vector<int> treeStates;
  std::map<int, std::vector<int>> values;
  int n, k;
  std::vector<int> as;

  int createEmptyTree(int start, int size) {
    int node = (int)tree.size();
    tree.emplace_back();
    if (size == 1) {
      return node;
    }
    int size1 = size / 2;
    int size2 = size - size1;
    int left = createEmptyTree(start, size1);
    int right = createEmptyTree(start + size1, size2);
    tree[node].l = left;
    tree[node].r = right;
    return node;
  }

  int copyNode(int n) {
    int node = (int) tree.size();
    tree.push_back(tree[n]);
    return node;
  }

  int addTree(int cur, int start, int size, int addStart, int addSize) {
    if (size == addSize) {
      int ret = copyNode(cur);
      tree[ret].mod++;
      return ret;
    }
    int size1 = size / 2;
    int size2 = size - size1;
    int left = tree[cur].l;
    if (addStart < start + size1) {
      left = addTree(left, start, size1, addStart, std::min(addSize, start + size1 - addStart));
    }
    int right = tree[cur].r;
    if (addStart + addSize > start + size1) {
      int newStart = std::max(addStart, start + size1);
      right = addTree(right, start + size1, size2, newStart, addStart + addSize - newStart);
    }
    int ret = copyNode(cur);
    tree[ret].l = left;
    tree[ret].r = right;
    return ret;
  }

  int request(int cur, int start, int size, int node) {
    if (size == 1) {
      return tree[cur].mod;
    }
    int size1 = size / 2;
    if (node < start + size1) {
      return tree[cur].mod + request(tree[cur].l, start, size1, node);
    } else {
      return tree[cur].mod + request(tree[cur].r, start + size1, size - size1, node);
    }
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n >> k;
    as.resize(n);
    values.clear();
    for (int i = 0; i < n; i++) {
      in >> as[i];
      values[as[i]].push_back(i);
    }
    treeStates.resize(n + 1);
    tree.clear();
    treeStates[n] = createEmptyTree(0, n);
    for (int i = n - 1; i >= 0; i--) {
      int x = as[i];
      std::vector<int>& idx = values[x];
      int xIndex = (int)(std::lower_bound(idx.begin(), idx.end(), i) - idx.begin());
      int last = xIndex + k;
      int bound;
      if (last >= idx.size()) {
        bound = n;
      } else {
        bound = idx[last];
      }
      treeStates[i] = addTree(treeStates[i + 1], 0, n, i, bound - i);
      std::cerr << i << " " << bound << std::endl;
    }
    int q;
    in >> q;
    int last = 0;
    for (int i = 0; i < q; i++) {
      int x, y;
      in >> x >> y;
      x = (x + last) % n;
      y = (y + last) % n;
      if (y < x) std::swap(x, y);
      last = request(treeStates[x], 0, n, y);
      out << last << "\n";
    }
    out.flush();
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}