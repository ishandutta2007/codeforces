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

struct bit_t {
  int n;
  vector<int> tree;
  bit_t(int _n): n(_n), tree(n + 1) {}
  void update(int i, int delta) {
    for (++i; i <= n; i += i&-i)
      tree[i] += delta;
  }
  int query(int i) {
    int result = 0;
    for (++i; i > 0; i -= i&-i)
      result += tree[i];
    return result;
  }
};

int main() {
  int n;
  scanf("%d", &n);
  vector<int> values(n);
  vector<pair<int, int>> value_pos(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &values[i]);
    value_pos[i] = make_pair(values[i], i);
  }
  sort(value_pos.begin(), value_pos.end());
  bit_t bit(n);
  for (int i = 0; i < n; ++i)
    bit.update(i, +1);
  lint result = 0;
  int current_pos = 0;
  for (int j = 0, i = j; i < n; i = j) {
    while (j < n && value_pos[j].first == value_pos[i].first) ++j;
    const int current_value = value_pos[i].first, block_size = j - i;
    int first = lower_bound(value_pos.begin() + i, value_pos.begin() + j,
                            make_pair(current_value, current_pos)) -
                value_pos.begin();
    if (first == j) first = i;
    for (int order = 0; order < block_size; ++order) {
      int k = first + order;
      if (k >= j) k -= block_size;
      int next_pos = value_pos[k].second;
      int cost;
      if (next_pos >= current_pos) {
        cost = bit.query(next_pos) - bit.query(current_pos - 1);
      } else {
        cost = (bit.query(n - 1) - bit.query(current_pos - 1)) +
          bit.query(next_pos);
      }
      result += cost;
      current_pos = next_pos;
      bit.update(current_pos, -1);
    }
  }
  printf("%lld\n", result);
  return 0;
}