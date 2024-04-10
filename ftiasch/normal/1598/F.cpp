#include <bits/stdc++.h>

const int N = 20;
const int M = 400'000;

int n, m, pre[N][M + 1], sum[1 << N], dp[1 << N];
std::string s[N];

struct Stat {
  void initialize(const std::string &s) {
    for (char c : s) {
      delta += c == '(' ? 1 : -1;
      if (min >= delta && delta <= 0) {
        partial[-delta]++;
      }
      if (min > delta) {
        min = delta;
        min_occ = 0;
      }
      min_occ += min == delta;
    }
  }

  int delta, min = INT_MAX, min_occ, partial[M + 1];
} stat[N];

void update(int &x, int a) { x = std::max(x, a); }

int main() {
  std::ios::sync_with_stdio(false);
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> s[i];
    stat[i].initialize(s[i]);
  }
  sum[0] = 0;
  for (int mask = 1, i = 0; mask < 1 << n; ++mask) {
    i += mask >> (i + 1) & 1;
    sum[mask] = sum[mask ^ (1 << i)] + stat[i].delta;
  }
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  int result = 0;
  for (int mask = 0; mask < 1 << n; ++mask) {
    if (~dp[mask]) {
      for (int i = 0; i < n; ++i) {
        if (~mask >> i & 1) {
          update(result, dp[mask] + stat[i].partial[sum[mask]]);
          if (sum[mask] + stat[i].min >= 0) {
            update(dp[mask ^ (1 << i)],
                   dp[mask] +
                       (sum[mask] + stat[i].min == 0 ? stat[i].min_occ : 0));
          }
        }
      }
    }
  }
  std::cout << result << std::endl;
}