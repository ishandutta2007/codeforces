#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::sort(a.begin(), a.end(), std::greater<int>());
  long long sum = std::accumulate(a.begin(), a.end(), 0LL);
  int m;
  scanf("%d", &m);
  while (m --) {
      int q;
      scanf("%d", &q);
      printf("%lld\n", sum - a[q - 1]);
  }
}