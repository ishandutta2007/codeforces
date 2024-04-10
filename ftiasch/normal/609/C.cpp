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
  int s = std::accumulate(a.begin(), a.end(), 0);
  int result = 0;
  for (int i = 0; i < n; ++i) {
    int target = s / n + (i < s % n);
    if (a[i] > target) {
      result += a[i] - target;
    }
  }
  printf("%d\n", result);
}