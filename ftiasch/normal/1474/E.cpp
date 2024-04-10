#include <bits/stdc++.h>

const int N = 100000;

int n, p[N];
std::pair<int, int> ops[N - 1];

// p[i], p[j] = {x, i}
// swap
// p[i], p[j] = {i, x}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    std::iota(p, p + n, 0);
    long long cost = 0;
    for (int i = 0; i < n - 1; ++i) {
      int j = i > n - 1 - i ? 0 : n - 1;
      cost += 1LL * (i - j) * (i - j);
      ops[i] = {i, j};
      std::swap(p[i], p[j]);
    }
    printf("%lld\n", cost);
    for (int i = 0; i < n; ++i) {
      printf("%d%c", p[i] + 1, " \n"[i + 1 == n]);
    }
    printf("%d\n", n - 1);
    for (int k = n - 2; k >= 0; --k) {
      int i, j;
      std::tie(i, j) = ops[k];
      printf("%d %d\n", i + 1, j + 1);
      assert(p[j] == i);
      std::swap(p[i], p[j]);
    }
    for (int i = 0; i < n; ++i) {
      assert(p[i] == i);
    }
  }
}