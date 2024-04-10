#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::map<int, int> count;
  long long result = 0;
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    if (!count.empty()) {
      int m = count.rbegin()->first;
      for (long long x = 2; x <= m + a; x <<= 1) {
        if (x > a) {
          result += count[x - a];
        }
      }
    }
    count[a]++;
  }
  printf("%lld\n", result);
}