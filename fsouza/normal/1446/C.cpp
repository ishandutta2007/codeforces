#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

const int max_bit = 29;

struct node_t {
  int dp = -1;
  int many = 0;
  node_t *children[2] = {nullptr, nullptr};

  void add(int value, int b) {
    if (b == -1) {
      ++many;
    } else {
      int side = (value & (1<<b)) != 0;
      if (children[side] == nullptr) children[side] = new node_t;
      children[side]->add(value, b - 1);
    }
  }

  void compute() {
    for (int side = 0; side < 2; ++side)
      if (children[side] != nullptr)
        children[side]->compute();

    int many0 = (children[0] == nullptr ? 0 : children[0]->many);
    int dp0 = (children[0] == nullptr ? 0 : children[0]->dp);

    int many1 = (children[1] == nullptr ? 0 : children[1]->many);
    int dp1 = (children[1] == nullptr ? 0 : children[1]->dp);

    if (many > 0) {
      dp = many;
    } else {
      many = many0 + many1;

      dp = max(min(1, many0) + dp1,
               dp0 + min(1, many1));
    }
  }
};

int main() {
  int n;
  scanf("%d", &n);
  node_t tree;
  for (int i = 0; i < n; ++i) {
    int value;
    scanf("%d", &value);
    tree.add(value, max_bit);
  }
  tree.compute();
  printf("%d\n", n - tree.dp);
  return 0;
}