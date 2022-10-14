#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 17;
const int M = 100'000;

int n, count[N];

bool valid[N][N], forbid[1 << N], dp[1 << N];

uint32_t cache[N][N][1 << (N - 5)];

int main() {
  int m;
  scanf("%d%d", &m, &n);
  std::vector<char> s(m + 1);
  scanf("%s", s.data());
  for (int i = 0; i < n; ++i) {
    for (int j = 0, x; j < n; ++j) {
      scanf("%d", &x);
      valid[i][j] = x;
    }
  }
  {
    std::vector<std::pair<int, int>> order;
    // 1 - removed
    for (int i = m; i--;) {
      int c = s[i] - 'a';
      count[c]++;
      for (auto &&[d, mask] : order) {
        if (!valid[c][d]) {
          int x = c;
          int y = d;
          if (x > y) {
            std::swap(x, y);
          }
          cache[x][y][mask >> 5] |= 1U << (mask & 31);
        }
        if (d == c) {
          break;
        }
      }
      auto iterator = std::find_if(
          order.begin(), order.end(),
          [&](const std::pair<int, int> &p) { return p.first == c; });
      if (iterator != order.end()) {
        order.erase(iterator);
      }
      for (auto &[_, mask] : order) {
        mask |= 1 << c;
      }
      order.insert(order.begin(), {c, 0});
    }
  }

  for (int c = 0; c < n; ++c) {
    for (int d = c; d < n; ++d) {
      if (!valid[c][d]) {
        for (int mask = 0; mask < 1 << n; ++mask) {
          if (cache[c][d][mask >> 5] >> (mask & 31) & 1) {
            forbid[mask] = true;
            for (int k = 0; k < n; ++k) {
              if (k != c && k != d && (~mask >> k & 1)) {
                int new_mask = mask | 1 << k;
                cache[c][d][new_mask >> 5] |= 1U << (new_mask & 31);
              }
            }
          }
        }
      }
    }
  }
  int result = m;
  dp[0] = true;
  for (int mask = 0; mask < 1 << n; ++mask) {
    if (dp[mask]) {
      int s = 0;
      for (int i = 0; i < n; ++i) {
        if (~mask >> i & 1) {
          s += count[i];
          int new_mask = mask | 1 << i;
          if (!forbid[new_mask]) {
            dp[new_mask] = true;
          }
        }
      }
      result = std::min(result, s);
    }
  }
  printf("%d\n", result);
}