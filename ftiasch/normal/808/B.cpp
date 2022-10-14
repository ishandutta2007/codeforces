#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> a(n);
  std::vector<long long> s(n + 1);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    s[i + 1] = s[i] + a[i];
  }
  long long result = 0;
  for (int i = m; i <= n; ++i) {
    result += s[i] - s[i - m];
  }
  printf("%.9f\n", 1.0 * result / (n - m + 1));
}