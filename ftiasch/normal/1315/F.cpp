#include <bits/stdc++.h>
#include <stdexcept>

const int N = 1001;

int n, m, lcp[N][N];
long long k, dp[N][N];
char s[N];

struct Range {
  int s, l;
} ranges[N * (N + 1) / 2];

bool operator<(const Range &a, const Range &b) {
  int l = std::min(lcp[a.s][b.s], std::min(a.l, b.l));
  return l < a.l && l < b.l ? s[a.s + l] < s[b.s + l] : a.l < b.l;
}

bool operator==(const Range &a, const Range &b) {
  return a.l == b.l && lcp[a.s][b.s] >= b.l;
}

bool check(const Range &r, long long k) {
  dp[n][0] = 1;
  for (int j = 1; j <= m; ++j) {
    dp[n][j] = 0;
  }
  for (int i = n; i--;) {
    int l = lcp[i][r.s];
    if (l >= r.l) {
      l = r.l;
    } else if (i + l == n || s[i + l] < s[r.s + l]) {
      l = -1;
    }
    dp[i][0] = 1;
    long long value = 0;
    for (int j = 1; j <= m; ++j) {
      value = ~l ? dp[i + l + 1][j - 1] : 0;
      dp[i][j] = std::min(dp[i + 1][j] + value, k);
    }
    if (!i) {
      return value < k;
    }
  }
  return false;
}

int main() {
  scanf("%d%d%lld%s", &n, &m, &k, s);
  for (int i = n; i--;) {
    for (int j = n; j--;) {
      lcp[i][j] = s[i] == s[j] ? 1 + lcp[i + 1][j + 1] : 0;
    }
  }
  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; i + j <= n; ++j) {
      ranges[count++] = Range{i, j};
    }
  }
  std::sort(ranges, ranges + count);
  count = std::unique(ranges, ranges + count) - ranges;
  int low = 0;
  int high = count;
  while (low < high) {
    int middle = low + high >> 1;
    if (check(ranges[middle], k)) {
      high = middle;
    } else {
      low = middle + 1;
    }
  }
  auto r = ranges[high];
  for (int i = 0; i < r.l; ++i) {
    putchar(s[r.s + i]);
  }
  puts("");
}