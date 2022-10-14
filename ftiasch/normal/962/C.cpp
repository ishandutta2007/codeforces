#line 1 "sol.cpp"
#include <bits/stdc++.h>

int check(const std::vector<int> &n, int s) {
  int result = 0, i = 0;
  while (s) {
    int r = s % 10;
    s /= 10;
    while (i < static_cast<int>(n.size()) && n[i] != r) {
      result++;
      i++;
    }
    if (i == static_cast<int>(n.size())) {
      return -1;
    }
    i++;
  }
  return result + (static_cast<int>(n.size()) - i);
}

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> s;
  for (int x = n; x; x /= 10) {
    s.push_back(x % 10);
  }
  for (int r = std::sqrt(n) + 1; r >= 1; --r) {
    int result = check(s, r * r);
    if (~result) {
      printf("%d\n", result);
      return 0;
    }
  }
  puts("-1");
}