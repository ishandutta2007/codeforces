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

struct item_t {
  int val;
  int weight;
  bool popular;
};

lint combine(const item_t &a, const item_t &b) {
  return (lint)(a.val + b.val) * (a.weight + b.weight);
}

lint solve(vector<item_t> &items, vector<pair<int, int>> &bad, map<int, int> &counts, int threshold) {
  sort(items.begin(), items.end(), [](const item_t &lhs, const item_t &rhs) {
    if (lhs.val != rhs.val)
      return lhs.val < rhs.val;
    return lhs.weight < rhs.weight;
  });

  vector<tuple<int, int, int>> bad2;
  for (pair<int, int> ab : bad) {
    int a = ab.first, b = ab.second;
    bad2.push_back({a, counts[b], -b});
  }
  sort(bad2.begin(), bad2.end());

  lint result = 0LL;

  int cur_bad = 0;
  for (const item_t &item : items) {
    if (!item.popular) continue;

    for (const item_t &item2 : items) {
      while (cur_bad < (int)bad.size() && bad[cur_bad] < make_pair(item.val, item2.val))
        ++cur_bad;
      if (cur_bad < (int)bad.size() && bad[cur_bad] == make_pair(item.val, item2.val)) {
      } else {
        result = max(result, combine(item, item2));
      }
    }
  }

  vector<vector<item_t>> with_weights(threshold);
  for (int i = items.size() - 1; i >= 0; --i) {
    const item_t &item = items[i];
    if (item.weight < threshold)
      with_weights[item.weight].push_back(item);
  }

  int cur_bad2 = 0;
  for (const item_t &item : items) {
    for (int target = 1; target < threshold; ++target) {
      for (const item_t &item2 : with_weights[target]) {
        while (cur_bad2 < (int)bad2.size() && bad2[cur_bad2] < make_tuple(item.val, target, -item2.val))
          ++cur_bad2;
        if (cur_bad2 < (int)bad2.size() && bad2[cur_bad2] == make_tuple(item.val, target, -item2.val)) {
        } else {
          result = max(result, combine(item, item2));
          break;
        }
      }
    }
  }

  return result;
}

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n, m;
    scanf("%d %d", &n, &m);
    map<int, int> counts;
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      counts[a] += 1;
    }
    vector<pair<int, int>> bad;
    for (int i = 0; i < m; ++i) {
      int a, b;
      scanf("%d %d", &a, &b);
      bad.push_back({a, b});
      bad.push_back({b, a});
    }

    int threshold = sqrt(n) + 4;
    vector<item_t> items;
    for (auto it : counts) {
      items.push_back({it.first, it.second, it.second >= threshold});
      bad.push_back({it.first, it.first});
    }

    sort(bad.begin(), bad.end());

    printf("%lld\n", solve(items, bad, counts, threshold));
  }
  return 0;
}