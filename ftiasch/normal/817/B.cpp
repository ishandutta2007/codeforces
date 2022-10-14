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
  int left = 3;
  for (auto [_, c] : cnt) {
    if (left > c) {
      left -= c;
    } else {
      long long result = 1;
      for (int i = 0; i < left; ++i) {
        result = result * (c - i) / (i + 1);
      }
      printf("%lld\n", result);
      break;
    }
  }
}