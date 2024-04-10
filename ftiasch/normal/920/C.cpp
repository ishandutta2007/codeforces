#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::vector<char> s(n);
  scanf("%s", s.data());
  for (int i = 0; i < n;) {
    int j = i;
    while (s[j] == '1') {
      j++;
    }
    j++;
    std::sort(a.begin() + i, a.begin() + j);
    i = j;
  }
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    ok &= a[i] == i + 1;
  }
  puts(ok ? "YES" : "NO");
}