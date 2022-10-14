// #include "debug.h"

#include <bits/stdc++.h>

std::tuple<int, int> p[4];
std::vector<int> events;

template <int t> void add_events() {
  for (int i = 0; i < 4; ++i) {
    if (i >> t & 1) {
      for (int j = 0; j < 4; ++j) {
        if (~j >> t & 1) {
          int d = std::get<t>(p[i]) - std::get<t>(p[j]);
          if (d > 0) {
            events.push_back(d);
          }
        }
      }
    }
  }
}

using Linear = std::pair<int, long long>;

Linear operator+(const Linear &a, const Linear &b) {
  return {a.first + b.first, a.second + b.second};
}

Linear operator-(const Linear &a, const Linear &b) {
  return {a.first - b.first, a.second - b.second};
}

template <int t> std::pair<int, int> eval(int mid) {
  std::tuple<long long, int, int> values[4];
  for (int i = 0; i < 4; ++i) {
    int k = i >> t & 1;
    int b = std::get<t>(p[i]);
    values[i] = {2LL * b - (k ? mid : 0), k, b};
  }
  std::sort(values, values + 4);
  Linear sum{0, 0};
  for (int i = 0; i < 4; ++i) {
    auto [_, k, b] = values[i];
    if (i < 2) {
      sum = sum - Linear{k, b};
    } else {
      sum = sum + Linear{k, b};
    }
  }
  return sum;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    for (int i = 0; i < 4; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      p[i] = {x, y};
    }
    long long result = 8e9;
    std::sort(p, p + 4);
    do {
      events = {0, 1'000'000'000};
      add_events<0>();
      add_events<1>();
      std::sort(events.begin(), events.end());
      events.erase(std::unique(events.begin(), events.end()), events.end());
      for (int i = 1; i < static_cast<int>(events.size()); ++i) {
        int mid = events[i - 1] + events[i];
        Linear sum_x = eval<0>(mid);
        Linear sum_y = eval<1>(mid);
        Linear sum = sum_x + sum_y;
        result = std::min(result, sum.second - 1LL * sum.first * events[i - 1]);
        result = std::min(result, sum.second - 1LL * sum.first * events[i]);
      }
    } while (std::next_permutation(p, p + 4));
    printf("%lld\n", result);
  }
}