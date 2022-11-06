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
  int x, y;
};

vector<point_t> read() {
  vector<point_t> result;
  for (int i = 0; i < 4; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    result.push_back({x, y});
  }
  return result;
}

pair<int, int> get_range(const vector<point_t> &points, int mx, int my) {
  int min_v = INT_MAX, max_v = INT_MIN;
  for (const point_t &p : points) {
    int v = p.x * mx + p.y * my;
    min_v = min(min_v, v);
    max_v = max(max_v, v);
  }
  return {min_v, max_v};
}

pair<int, int> mult2(const pair<int, int> &a) {
  return {a.first * 2, a.second * 2};
}

bool in_range(int v, const pair<int, int> &a) {
  return a.first <= v && v <= a.second;
}

int main() {
  vector<point_t> s1 = read();
  vector<point_t> s2 = read();
  pair<int, int> s1_x = mult2(get_range(s1, 1, 0));
  pair<int, int> s1_y = mult2(get_range(s1, 0, 1));
  pair<int, int> s2_sum = mult2(get_range(s2, 1, 1));
  pair<int, int> s2_diff = mult2(get_range(s2, 1, -1));

  bool result = false;

  for (int x = -200; x <= 200; ++x)
    for (int y = -200; y <= 200; ++y) {
      if (in_range(x, s1_x) && in_range(y, s1_y) &&
          in_range(x + y, s2_sum) && in_range(x - y, s2_diff)) {
        result = true;
      }
    }

  if (result) printf("Yes\n");
  else printf("No\n");

  return 0;
}