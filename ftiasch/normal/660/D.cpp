#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
  }
  std::vector<std::pair<int, int>> p;
  p.reserve(n * (n - 1) / 2);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      p.emplace_back(x[i] + x[j], y[i] + y[j]);
    }
  }
  std::sort(p.begin(), p.end());
  long long result = 0;
  for (int i = 0; i < p.size();) {
    int j = i;
    while (j < p.size() && p[i] == p[j]) {
      j++;
    }
    int cnt = j - i;
    result += cnt * (cnt - 1LL) / 2;
    i = j;
  }
  printf("%lld\n", result);
}