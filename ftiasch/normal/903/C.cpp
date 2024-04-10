#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::map<int, int> cnt;
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    cnt[a]++;
  }
  int result = 0;
  for (auto [k, v] : cnt) {
    result = std::max(result, v);
  }
  printf("%d\n", result);
}