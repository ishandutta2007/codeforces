#include <bits/stdc++.h>

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  while (q--) {
    int t;
    scanf("%d", &t);
    auto iterator = std::find(a.begin(), a.end(), t);
    std::copy_backward(a.begin(), iterator, iterator + 1);
    a[0] = t;
    printf("%d%c", static_cast<int>(iterator - a.begin()) + 1, " \n"[q == 0]);
  }
}