#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<char> s(n + 1);
  scanf("%s", s.data());
  int result = 0;
  for (int i = 0; i < n;) {
    if (i + 1 < n && s[i] != s[i + 1]) {
      i += 2;
    } else {
      i++;
    }
    result++;
  }
  printf("%d\n", result);
}