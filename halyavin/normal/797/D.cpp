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
#include <set>

struct Node {
  int value;
  int left;
  int right;
  Node() : value(0), left(-1), right(-1) {}
  Node(int value, int left, int right) : value(value), left(left), right(right) {}
};

void rec(const std::vector<Node>& nodes, int left, int right, int node, std::set<int>& good) {
  if (left >= right) {
    return;
  }
  const Node& cur = nodes[node];
  if (cur.value > left && cur.value < right) {
    good.insert(cur.value);
  }
  if (cur.left >= 0) {
    rec(nodes, left, std::min(right, cur.value), cur.left, good);
  }
  if (cur.right >= 0) {
    rec(nodes, std::max(left, cur.value), right, cur.right, good);
  }
}

void run(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  std::vector<Node> nodes(n);
  std::vector<bool> flags(n);
  for (int i = 0; i < n; i++) {
    in >> nodes[i].value >> nodes[i].left >> nodes[i].right;
    if (nodes[i].left > 0) {
      nodes[i].left--;
      flags[nodes[i].left] = true;
    }
    if (nodes[i].right > 0) {
      nodes[i].right--;
      flags[nodes[i].right] = true;
    }
  }
  int root = 0;
  for (int i = 0; i < n; i++) {
    if (!flags[i]) {
      root = i;
      break;
    }
  }
  std::set<int> good;
  rec(nodes, -1, 1000000001, root, good);
  int answer = 0;
  for (Node& node : nodes) {
    if (good.find(node.value) == good.end()) {
      answer++;
    }
  }
  out << answer << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}