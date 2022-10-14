#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> alives(n);
  std::iota(alives.begin(), alives.end(), 1);
  for (int i = 0, k = 0, step; k < m; ++k) {
    scanf("%d", &step);
    i = (i + step) % alives.size();
    int dead = alives[i];
    alives.erase(alives.begin() + i);
    printf("%d%c", dead, " \n"[k + 1 == m]);
  }
}