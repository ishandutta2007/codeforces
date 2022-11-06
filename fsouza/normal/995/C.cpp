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

struct point_t {
  int x, y, id;
  unique_ptr<point_t> pos, neg;
  point_t() {}
  point_t(int _x, int _y, int _id): x(_x), y(_y), id(_id) {}
  point_t(unique_ptr<point_t> _pos, unique_ptr<point_t> _neg)
      : pos(move(_pos)), neg(move(_neg)) {
    x = pos->x - neg->x;
    y = pos->y - neg->y;
    id = -1;
  }
};

const int limit = 1000000, final_limit = 1500000, ngroup = 9;

int get_group_id(const point_t *p) {
  const int div0 = -limit + 2 * limit / 3;
  const int div1 = limit - 2 * limit / 3;
  int result = 0;
  for (int value : {p->x, p->y}) {
    result *= 3;
    if (value <= div0) result += 0;
    else if (value <= div1) result += 1;
    else result += 2;
  }
  return result;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<vector<unique_ptr<point_t>>> groups(ngroup);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    unique_ptr<point_t> point = make_unique<point_t>(x, y, i);
    int group_id = get_group_id(point.get());
    groups[group_id].push_back(move(point));
  }
  bool repeat;
  do {
    repeat = false;
    for (vector<unique_ptr<point_t>> &group : groups) {
      while (group.size() >= 2) {
        unique_ptr<point_t> a = move(group.back());
        group.pop_back();
        unique_ptr<point_t> b = move(group.back());
        group.pop_back();
        unique_ptr<point_t> new_point = make_unique<point_t>(move(a), move(b));
        int new_point_group = get_group_id(new_point.get());
        groups[new_point_group].push_back(move(new_point));
        repeat = true;
      }
    }
  } while (repeat);
  vector<unique_ptr<point_t>> remain;
  for (vector<unique_ptr<point_t>> &group : groups) {
    for (unique_ptr<point_t> &point : group)
      remain.push_back(move(point));
    group.clear();
  }
  vector<int> result(n, 0);
  function<void(const point_t *, int)> set_result = [&](const point_t *p,
                                                        int mult) {
    if (p->id >= 0) {
      result[p->id] = mult;
    } else {
      if (p->pos) set_result(p->pos.get(), mult);
      if (p->neg) set_result(p->neg.get(), -mult);
    }
  };
  for (int s = 0; s < (1<<(int)remain.size()); ++s) {
    int sum_x = 0, sum_y = 0;
    for (int i = 0; i < (int)remain.size(); ++i) {
      if (s & (1<<i)) {
        sum_x += remain[i]->x;
        sum_y += remain[i]->y;
      } else {
        sum_x -= remain[i]->x;
        sum_y -= remain[i]->y;
      }
    }
    if ((lint)sum_x * sum_x + (lint)sum_y * sum_y <=
        (lint)final_limit * final_limit) {
      for (int i = 0; i < (int)remain.size(); ++i) {
        if (s & (1<<i)) set_result(remain[i].get(), +1);
        else set_result(remain[i].get(), -1);
      }
      break;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i > 0) printf(" ");
    printf("%d", result[i]);
  }
  printf("\n");

  return 0;
}