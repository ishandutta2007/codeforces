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
#include <random>

struct Node {
  int comp = 0;
  //std::vector<int> left;
  //std::vector<int> right;
  std::array<int, 10> left;
  std::array<int, 10> right;
  int leftIndex = 0;
  int rightIndex = 0;
  int colors = 0;
  Node() = default;
};

Node unite(Node left, Node right, const std::vector<std::vector<int>>& grid) {
  if (left.colors == 0) return right;
  if (right.colors == 0) return left;
  size_t n = grid[0].size();
  Node result;
//  result.left.resize(left.left.size());
//  result.right.resize(left.right.size());
  result.comp = left.comp + right.comp;
  result.leftIndex = left.leftIndex;
  result.rightIndex = right.rightIndex;
  result.colors = left.colors + right.colors;
  int offset = left.colors;
  std::array<int, 40> colors;
  int ncolors = result.colors;
  std::iota(colors.begin(), colors.begin() + ncolors, 0);
  int i1 = left.rightIndex;
  int i2 = right.leftIndex;
  for (size_t i = 0; i < n; i++) {
    if (grid[i1][i] == grid[i2][i]) {
      int c1 = colors[left.right[i]];
      int c2 = colors[right.left[i] + offset];
      if (c1 != c2) {
        result.colors--;
        for (int j = 0; j < ncolors; j++) {
          if (colors[j] == c2) {
            colors[j] = c1;
          }
        }
      }
    }
  }
  std::array<int, 40> cIndex;
  std::fill(cIndex.begin(), cIndex.begin() + ncolors, -1);
  int cs = 0;
  for (size_t i = 0; i < n; i++) {
    int c = colors[left.left[i]];
    if (cIndex[c] == -1) {
      cIndex[c] = cs;
      cs++;
    }
    result.left[i] = cIndex[c];
  }
  for (size_t i = 0; i < n; i++) {
    int c = colors[right.right[i] + offset];
    if (cIndex[c] == -1) {
      cIndex[c] = cs;
      cs++;
    }
    result.right[i] = cIndex[c];
  }
  result.comp += result.colors - cs;
  result.colors = cs;
  return result;
}

struct BinTree1 {
  using T = Node;
  size_t size;
  std::vector<T> t;
  std::vector<std::vector<int>>& grid;

  BinTree1(const std::vector<T>& other, std::vector<std::vector<int>>& grid) :
      size(other.size()),
      t(2 * other.size()),
      grid(grid) {
    std::copy(other.begin(), other.end(), t.begin() + size);
    for (size_t i = size; i-- > 1;) {
      t[i] = combine(t[2 * i], t[2 * i + 1]);
    }
  }

  T get(size_t p) {
    return t[p + size];
  }

  void modify(size_t p, T value) {
    p += size;
    t[p] = value;
    while (p > 1) {
      p = p / 2;
      t[p] = combine(t[2 * p], t[2 * p + 1]);
    }
  }

  T query(size_t l, size_t r) {
    l += size;
    r += size;
    T left = init();
    T right = init();
    while (l < r) {
      if (l & 1) {
        left = combine(left, t[l]);
        l++;
      }
      if (r & 1) {
        r--;
        right = combine(t[r], right);
      }
      l = l / 2;
      r = r / 2;
    }
    return combine(left, right);
  }

 private:
  T combine(T left, T right) {
    return unite(left, right, grid);
  }

  T init() {
    return T();
  }
};

void run(std::istream& in, std::ostream& out) {
  int n, m, q;
  in >> n >> m >> q;
  std::vector<std::vector<int>> grid(m, std::vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      in >> grid[j][i];
    }
  }
  std::vector<Node> nodes;
  for (int i = 0; i < m; i++) {
    nodes.emplace_back();
    Node& node = nodes.back();
    int prev = -1;
    for (int j = 0; j < n; j++) {
      if (grid[i][j] != prev) {
        prev = grid[i][j];
        node.colors++;
      }
      //node.left.push_back(node.colors - 1);
      node.left[j] = node.colors - 1;
    }
    node.right = node.left;
    node.leftIndex = i;
    node.rightIndex = i;
  }
  BinTree1 tree(nodes, grid);
  for (int i = 0; i < q; i++) {
    int l, r;
    in >> l >> r;
    l--;
    Node result = tree.query(l, r);
    out << result.comp + result.colors << "\n";
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}