#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<char> s(n + 1);
  scanf("%s", s.data());
  std::pair<char, int> candidate = {s[0], 0};
  for (int i = 1; i < n; ++i) {
    if (candidate.first > s[i]) {
      printf("YES\n%d %d\n", candidate.second + 1, i + 1);
      return 0;
    }
    candidate = std::max(candidate, {s[i], i});
  }
  puts("NO");
}