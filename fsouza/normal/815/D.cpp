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

struct box_t {
  int a, b, c;
  box_t() {}
  box_t(int _a, int _b, int _c): a(_a), b(_b), c(_c) {}
};

struct rectangle_union_area_t {
  lint area = 0LL;
  set<pair<int, int>> active;

  lint get_area_contribution(set<pair<int, int>>::iterator it) {
    int width = it->first, height = it->second;
    if (it != active.begin()) {
      --it;
      width -= it->first;
      ++it;
    }
    {
      ++it;
      if (it != active.end()) {
        height -= it->second;
      }
      --it;
    }
    return (lint)width * height;
  }

  void add(int x, int y) {
    if (!is_covered(x, y)) {
      set<pair<int, int>>::iterator it;
      while (it = get_covered_by(x, y), it != active.end()) {
        area -= get_area_contribution(it);
        active.erase(it);
      }
      area += get_area_contribution(active.insert(make_pair(x, y)).first);
    }
  }

  set<pair<int, int>>::iterator get_covered_by(int x, int y) {
    auto it = active.upper_bound(make_pair(x, INT_MAX));
    if (it != active.begin()) {
      --it;
      if (it->second <= y)
        return it;
    }
    return active.end();
  }

  bool is_covered(int x, int y) {
    auto it = active.lower_bound(make_pair(x, INT_MIN));
    return it != active.end() && it->second >= y;
  }

  lint get_area() { return area; }
};

lint volume_union_boxes(vector<box_t> boxes) {
  lint result = 0;
  rectangle_union_area_t solver;
  sort(boxes.begin(), boxes.end(), [](const box_t &a, const box_t &b) {
      return a.c < b.c;
    });
  for (int i = (int)boxes.size() - 1; i >= 0; --i) {
    solver.add(boxes[i].a, boxes[i].b);
    result += solver.get_area() *
      (boxes[i].c - (i - 1 >= 0 ? boxes[i-1].c : 0));
  }
  return result;
}

int main() {
  int n;
  scanf("%d", &n);
  int maxa, maxb, maxc;
  scanf("%d %d %d", &maxa, &maxb, &maxc);

  vector<box_t> boxes;
  for (int i = 0; i < n; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    boxes.emplace_back(a, b, maxc);
    boxes.emplace_back(a, maxb, c);
    boxes.emplace_back(maxa, b, c);
  }

  lint result = (lint)maxa * maxb * maxc - volume_union_boxes(boxes);
  printf("%lld\n", result);

  return 0;
}