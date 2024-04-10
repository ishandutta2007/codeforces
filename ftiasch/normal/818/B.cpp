#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> indices(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &indices[i]);
    indices[i]--;
  }
  std::vector<bool> used(n);
  std::vector<int> perm(n, -1);
  auto work = [&]() -> bool {
    for (int j = 1; j < m; ++j) {
      int i = indices[j - 1];
      int d = indices[j] + n - indices[j - 1];
      if (d >= n) {
        d -= n;
      }
      if (~perm[i]) {
        if (perm[i] != d) {
          return false;
        }
      } else {
        if (used[d]) {
          return false;
        }
        used[d] = true;
        perm[i] = d;
      }
    }
    for (int i = 0, j = 0; i < n; ++i) {
      if (!~perm[i]) {
        while (used[j]) {
          j++;
        }
        used[j] = true;
        perm[i] = j;
      }
    }
    return true;
  };
  if (work()) {
    for (int i = 0; i < n; ++i) {
      printf("%d%c", perm[i] ? perm[i] : n, " \n"[i + 1 == n]);
    }
  } else {
    puts("-1");
  }
}