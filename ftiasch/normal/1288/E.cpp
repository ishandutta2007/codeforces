#include <bits/stdc++.h>

const int N = 300000;

int n, q, minp[N], maxp[N], prev[N], count[N + N];

template <int d> void add(int k) {
  for (; k >= 0; k -= ~k & k + 1) {
    count[k] += d;
  }
}

int ask(int k) {
  int result = 0;
  for (; k < n + q; k += ~k & k + 1) {
    result += count[k];
  }
  return result;
}

int main() {
  scanf("%d%d", &n, &q);
  std::iota(minp, minp + n, 0);
  memset(prev, -1, sizeof(prev));
  for (int i = 0, a; i < n + q; ++i) {
    if (i < n) {
      a = n - 1 - i;
    } else {
      scanf("%d", &a);
      minp[--a] = 0;
    }
    if (~prev[a]) {
      maxp[a] = std::max(maxp[a], ask(prev[a] + 1));
    }
    add<-1>(prev[a]), add<1>(i);
    prev[a] = i;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d %d\n", minp[i] + 1, std::max(maxp[i], ask(prev[i] + 1)) + 1);
  }
}