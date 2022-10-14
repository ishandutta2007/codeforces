#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> count(n);
  for (int i = 0, c; i < m; ++i) {
    scanf("%d", &c);
    count[c - 1]++;
  }
  printf("%d\n", *std::min_element(count.begin(), count.end()));
}