#include <bits/stdc++.h>

const int N = 200'000;

int n, k, h[N];

bool check() {
  int min = h[0], max = h[0];
  for (int i = 1; i < n; ++i) {
    // x in [h[i], h[i] + k - 1]
    min = std::max(min - k + 1, h[i]);
    max = std::min(max + k - 1, h[i] + k - 1);
    if (min > max) {
      return false;
    }
  }
  return min <= h[n - 1] && h[n - 1] <= max;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
      scanf("%d", h + i);
    }
    puts(check() ? "YES" : "NO");
  }
}