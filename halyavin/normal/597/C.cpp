#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

const int levels = 20;

struct IntTree {
  std::vector<std::vector<uint64_t>> tree;
  IntTree(int n) : tree(levels) {
    for (int i = 0; i < levels; i++) {
      tree[i].resize((n + (1 << i) - 1) >> i);
    }
  }

  void add(int idx, uint64_t value) {
    for (int i = 0; i < levels; i++) {
      tree[i][idx] += value;
      idx = idx >> 1;
    }
  }

  uint64_t sum(int idx) {
    uint64_t res = 0;
    for (int i = 0; i < levels && idx > 0; i++) {
      if (idx % 2) {
        res += tree[i][idx - 1];
      }
      idx = idx >> 1;
    }
    return res;
  }
};

void run(std::istream &in, std::ostream &out) {
  int n, k;
  in >> n >> k;
  std::vector<int> numbers(n);
  for (int i = 0; i < n; i++) {
    in >> numbers[i];
    numbers[i]--;
  }
  std::vector<uint64_t> dyn(n, 1);
  for (int i = 0; i < k; i++) {
    IntTree tree(n);
    for (int j = 0; j < n; j++) {
      uint64_t sumPrev = tree.sum(numbers[j]);
      tree.add(numbers[j], dyn[j]);
      dyn[j] = sumPrev;
    }
  }
  uint64_t total = std::accumulate(dyn.begin(), dyn.end(), uint64_t(0));
  out << total << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}