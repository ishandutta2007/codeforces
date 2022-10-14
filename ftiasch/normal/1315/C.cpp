#include <bits/stdc++.h>

const int N = 100;

int n, a[N << 1], b[N], count[N << 1];

bool check(int x) {
  if (count[x] != -1) {
    return false;
  }
  count[x] = 0;
  for (int i = 0, s = 0; i < n << 1; ++i) {
    s += count[i];
    if (s < 0) {
      count[x] = -1;
      return false;
    }
  }
  count[x] = -1;
  return true;
}

bool solve() {
  memset(count, -1, sizeof(*count) * (n << 1));
  for (int i = 0; i < n; ++i) {
    if (count[b[i]] == 1) {
      return false;
    }
    count[b[i]] = 1;
  }
  for (int i = 0; i < n; ++i) {
    count[a[i << 1] = b[i]] = 0;
    int x = b[i] + 1;
    while (x < (n << 1) && !check(x)) {
      x++;
    }
    if (x == (n << 1)) {
      return false;
    }
    count[a[i << 1 | 1] = x] = 0;
  }
  for (int i = 0; i < n << 1; ++i) {
    printf("%d%c", a[i] + 1, " \n"[i + 1 == (n << 1)]);
  }
  return true;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", b + i);
      b[i]--;
    }
    if (!solve()) {
      puts("-1");
    }
  }
}