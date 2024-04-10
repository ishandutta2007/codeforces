#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

const int N = 200'000;

using Pair = std::pair<int, int>;

Pair merge(const Pair &a, const Pair &b) {
  if (a.first == b.first) {
    auto [x, y] = a;
    add(y, b.second);
    return {x, y};
  }
  return std::min(a, b);
}

const int INF = 1e9 + 7;

int n, l[N], r[N];
Pair dp[N];

int main() {
  scanf("%d", &n);
  int right_maxl = 0;
  std::vector<std::pair<int, int>> events;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", r + i, l + i);
    right_maxl = std::max(right_maxl, l[i]);
    events.emplace_back(r[i], i);
    events.emplace_back(l[i], n + i);
  }
  std::sort(events.begin(), events.end());
  int left_maxl = 0, left_minr = INF;
  Pair result{INF, 0};
  std::fill(dp, dp + n, Pair{INF, 0});
  std::map<int, int> count;
  std::deque<int> queue;
  for (auto [_, encoding] : events) {
    if (encoding >= n) {
      // l
      int i = encoding - n;
      while (!queue.empty()) {
        int j = queue.front();
        if (left_maxl < r[j]) {
          break;
        }
        add(count[dp[j].first - r[j]], MOD - dp[j].second);
        queue.pop_front();
      }
      if (l[i] < left_minr) {
        dp[i] = merge(dp[i], {l[i], 1});
      }
      if (!queue.empty()) {
        int j = queue.front();
        int k = dp[j].first - r[j];
        dp[i] = merge(dp[i], Pair{k + l[i], count[k]});
      }
    } else {
      // r
      int i = encoding;
      if (right_maxl < r[i]) {
        result = merge(result, dp[i]);
      }
      {
        while (!queue.empty()) {
          int j = queue.back();
          if (dp[j].first - r[j] <= dp[i].first - r[i]) {
            break;
          }
          add(count[dp[j].first - r[j]], MOD - dp[j].second);
          queue.pop_back();
        }
        add(count[dp[i].first - r[i]], dp[i].second);
        queue.emplace_back(i);
      }
      left_maxl = std::max(left_maxl, l[i]);
      left_minr = std::min(left_maxl, r[i]);
    }
  }
  printf("%d\n", result.second);
}