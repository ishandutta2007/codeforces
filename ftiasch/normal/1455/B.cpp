#include <bits/stdc++.h>

int main() {
  std::vector<int> pre;
  for (int k = 0;; ++k) {
    pre.push_back(k * (k + 1) / 2);
    if (pre.back() >= 1e6) {
      break;
    }
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    auto k = std::lower_bound(pre.begin(), pre.end(), n) - pre.begin();
    if (pre[k] - 1 == n) {
      k++;
    }
    printf("%d\n", k);
  }
}