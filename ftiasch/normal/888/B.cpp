#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<char> s(n + 1);
  scanf("%s", s.data());
  std::array<int, 4> count{};
  for (int i = 0; i < n; ++i) {
    count[std::string{"LRUD"}.find(s[i])]++;
  }
  printf("%d\n",
         2 * (std::min(count[0], count[1]) + std::min(count[2], count[3])));
}