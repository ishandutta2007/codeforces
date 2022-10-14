#include <bits/stdc++.h>

const int N = 300'000;

int n, a[N], next[N], result;
long long sum[N + 1];

void work() {
  std::fill(next, next + n, n);
  int next_dup = n, suf_max = 1;
  for (int i = n; i--;) {
    sum[i] = sum[i + 1] + a[i];
    next_dup = std::min(next_dup, next[a[i]]);
    next[a[i]] = i;
    if (a[i] == 0) {
      suf_max = 1;
    } else {
      suf_max = std::max(suf_max, a[i] + 1);
      if (i + suf_max <= next_dup &&
          sum[i] - sum[i + suf_max] == suf_max * (suf_max - 1LL) / 2) {
        result++;
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    a[i]--;
  }
  result = std::count(a, a + n, 0);
  work();
  std::reverse(a, a + n);
  work();
  printf("%d\n", result);
}