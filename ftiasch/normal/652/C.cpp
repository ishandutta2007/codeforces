#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> q(n + 1);
  for (int i = 0, p; i < n; ++i) {
    scanf("%d", &p);
    q[p] = i;
  }
  std::vector<int> left(n, -1);
  for (int i = 0, a, b; i < m; ++i) {
    scanf("%d%d", &a, &b);
    a = q[a];
    b = q[b];
    if (a > b) {
      std::swap(a, b);
    }
    left[b] = std::max(a, left[b]);
  }
  long long result = 0;
  for (int i = 0, l = -1; i < n; ++i) {
    l = std::max(l, left[i]);
    result += i - l;
  }
  printf("%lld\n", result);
}