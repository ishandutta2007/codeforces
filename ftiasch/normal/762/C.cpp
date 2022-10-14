#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100'000;

char a[N + 1], b[N + 1];
int pre[N + 1], suf[N + 1];

int main() {
  scanf("%s%s", a, b);
  int n = strlen(a);
  int m = strlen(b);
  pre[0] = -1;
  for (int i = 0; i < m; ++i) {
    pre[i + 1] = std::min(pre[i] + 1, n);
    while (pre[i + 1] < n && a[pre[i + 1]] != b[i]) {
      pre[i + 1]++;
    }
  }
  suf[m] = n;
  for (int i = m; i--;) {
    suf[i] = std::max(suf[i + 1] - 1, -1);
    while (~suf[i] && a[suf[i]] != b[i]) {
      suf[i]--;
    }
  }
  // i <= j pre[i] < suf[j]
  std::pair<int, int> best{m, 0};
  for (int j = 0, i = -1; j <= m; ++j) {
    if (~suf[j]) {
      while (i + 1 <= j && pre[i + 1] < suf[j]) {
        i++;
      }
      best = std::min(best, {j - i, i});
    }
  }
  if (best.first == m) {
    puts("-");
  } else {
    int i = best.second;
    int j = best.first + best.second;
    for (int k = 0; k < i; ++k) {
      putchar(b[k]);
    }
    for (int k = j; k < m; ++k) {
      putchar(b[k]);
    }
    puts("");
  }
}