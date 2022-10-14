#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  std::vector<int> result;
  for (int d = 2; d * d <= n; ++d) {
    while (n % d == 0 && result.size() < k - 1) {
      n /= d;
      result.push_back(d);
    }
  }
  if (n > 1) {
    result.push_back(n);
  }
  if (result.size() == k) {
    result.push_back(n);
    for (int i = 0; i < k; ++i) {
      printf("%d%c", result[i], " \n"[i + 1 == k]);
    }
  } else {
    puts("-1");
  }
}