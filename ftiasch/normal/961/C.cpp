#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<char> buffer(n + 1);
  int count[4][2];
  memset(count, 0, sizeof(count));
  for (int k = 0; k < 4; ++k) {
    for (int i = 0; i < n; ++i) {
      scanf("%s", buffer.data());
      for (int j = 0; j < n; ++j) {
        count[k][(buffer[j] == '1') ^ ((i + j) & 1)]++;
      }
    }
  }
  int result = 4 * n * n;
  for (int mask = 0; mask < 1 << 4; ++mask) {
    if (__builtin_popcount(mask) == 2) {
      int cost = 0;
      for (int i = 0; i < 4; ++i) {
        cost += count[i][mask >> i & 1];
      }
      result = std::min(result, cost);
    }
  }
  printf("%d\n", result);
}