#line 1 "sol.cpp"
// #include "debug.h"

#include <bits/stdc++.h>

const int N = 500002;

int n, m, a[N], now, timestamp[N], fenwick[N];
bool fixed[N];

int get(int i) { return timestamp[i] == now ? fenwick[i] : 0; }

void set(int i, int x) {
  timestamp[i] = now;
  fenwick[i] = x;
}

int ask(int i) {
  int result = 0;
  for (; ~i; i -= ~i & i + 1) {
    result = std::max(result, get(i));
  }
  return result;
}

void add(int i, int v) {
  for (; i < n + 2; i += ~i & i + 1) {
    set(i, std::max(get(i), v));
  }
}

int solve() {
  int result = n - m;
  for (int left = 0; left <= n;) {
    int right = left + 1;
    while (!fixed[right]) {
      right++;
    }
    if (a[left] > a[right]) {
      return -1;
    }
    now++;
    int max_dp = 0;
    for (int i = left + 1; i < right; ++i) {
      if (a[left] <= a[i] && a[i] <= a[right]) {
        // std::cerr << a[i] << std::endl;
        int dp = ask(a[i]) + 1;
        max_dp = std::max(max_dp, dp);
        add(a[i], dp);
      }
    }
    result -= max_dp;
    left = right;
  }
  return result;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    a[i] -= i;
  }
  a[0] = INT_MIN;
  a[n + 1] = INT_MAX;
  {
    std::vector<int> values(a, a + (n + 2));
    std::sort(values.begin(), values.end());
    values.erase(std::unique(values.begin(), values.end()), values.end());
    for (int i = 0; i <= n + 1; ++i) {
      a[i] =
          std::lower_bound(values.begin(), values.end(), a[i]) - values.begin();
    }
  }
  fixed[0] = fixed[n + 1] = true;
  for (int j = 0; j < m; ++j) {
    int i;
    scanf("%d", &i);
    fixed[i] = true;
  }
  printf("%d\n", solve());
}