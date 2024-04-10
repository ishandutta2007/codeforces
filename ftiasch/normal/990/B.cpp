#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::sort(a.begin(), a.end());
  int result = 0, last = 0, last_count = 0;
  for (int x : a) {
    if (last == x) {
      last_count++;
    } else {
      if (x - last > m) {
        result += last_count;
      }
      last = x;
      last_count = 1;
    }
  }
  printf("%d\n", result + last_count);
}