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

int main() {
  int n;
  lint max_cost;
  scanf("%d %lld", &n, &max_cost);
  vector<int> heights(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &heights[i]);
  struct event_t {
    int when;
    int delta_slope;
    lint delta_cost;
  };
  vector<event_t> events;
  for (int i = 0; i < n; ++i) {
    for (int d = 1; d <= heights[i]; ++d) {
      int quocient = heights[i] / d;
      int rest = heights[i] % d;
      if (rest != 0) {
        int extra_steps = (rest - 1) / quocient;
        int delta_cost = d - rest;
        int delta_slope = quocient + 1;
        events.push_back((event_t){d, delta_slope, delta_cost});
        events.push_back((event_t){
            d + extra_steps + 1, -delta_slope,
            -delta_cost - (lint)delta_slope * (extra_steps + 1),
        });
        d += extra_steps;
      }
    }
    events.push_back((event_t){heights[i] + 1, 1, 1});
  }
  sort(events.begin(), events.end(),
       [](const event_t &a, const event_t &b) { return a.when < b.when; });
  lint result = 1;
  lint current_cost = 0, current_slope = 0;
  int previous_when = 1;
  for (int j = 0, i = j; i < (int)events.size(); i = j) {
    while (j < (int)events.size() && events[j].when == events[i].when) ++j;
    const int when = events[i].when;
    if (previous_when != when) {
      assert(current_slope >= 0);

      if (current_cost <= max_cost) {
        if (current_slope == 0) {
          result = when - 1;
        } else {
          result =
              min((lint)when - 1,
                  previous_when + (max_cost - current_cost) / current_slope);
        }
      }

      current_cost += current_slope * (when - previous_when);
    }
    for (int k = i; k < j; ++k) {
      current_cost += events[k].delta_cost;
      current_slope += events[k].delta_slope;
    }
    previous_when = when;
  }
  const int when = previous_when;
  assert(current_slope > 0);
  if (current_cost <= max_cost)
    result = when + (max_cost - current_cost) / current_slope;
  printf("%lld\n", result);
  return 0;
}