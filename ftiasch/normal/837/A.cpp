#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d\n", &n);
  std::vector<char> s(n + 1);
  fgets(s.data(), n + 1, stdin);
  int max = 0, sum = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == ' ') {
      max = std::max(max, sum);
      sum = 0;
    } else {
      sum += std::isupper(s[i]) ? 1 : 0;
    }
  }
  printf("%d\n", std::max(max, sum));
}