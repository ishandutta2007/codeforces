#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> p(n + 1), q(n + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
  }
  auto solve = [&]() -> bool {
    std::vector<std::vector<int>> cycles(n + 1);
    for (int i = 1; i <= n; ++i) {
      if (p[i]) {
        std::vector<int> cycle;
        int j = i;
        do {
          int k = p[j];
          p[j] = 0;
          j = k;
          cycle.push_back(j);
        } while (j != i);
        int size = cycle.size();
        if (size & 1) {
          int step = (size + 1) >> 1;
          for (int i = 0; i < size; ++i) {
            q[cycle[i]] = cycle[(i + step) % size];
          }
        } else if (cycles[size].empty()) {
          cycles[size] = std::move(cycle);
        } else {
          for (int i = 0; i < size; ++i) {
            q[cycle[i]] = cycles[size][i];
            q[cycles[size][i]] = cycle[(i + 1) % size];
          }
          cycles[size].clear();
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (!cycles[i].empty()) {
        return false;
      }
    }
    return true;
  };
  if (solve()) {
    for (int i = 1; i <= n; ++i) {
      printf("%d%c", q[i], " \n"[i == n]);
    }
  } else {
    puts("-1");
  }
}