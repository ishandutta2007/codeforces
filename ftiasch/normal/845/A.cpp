#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n << 1);
  for (int i = 0; i < n << 1; ++i) {
    scanf("%d", &a[i]);
  }
  std::nth_element(a.begin(), a.begin() + n, a.end());
  puts(*std::max_element(a.begin(), a.begin() + n) < a[n] ? "YES" : "NO");
}