#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    int unmatch_x = -1;
    std::vector<bool> match_y(n);
    std::vector<int> g;
    for (int i = 0, k, j; i < n; ++i) {
      scanf("%d", &k);
      g.resize(k);
      for (int j = 0; j < k; ++j) {
        scanf("%d", &g[j]);
        g[j]--;
      }
      bool match_x = false;
      for (int j = 0; j < k; ++j) {
        if (!match_y[g[j]]) {
          match_x = true;
          match_y[g[j]] = true;
          break;
        }
      }
      if (!match_x) {
        unmatch_x = i;
      }
    }
    if (~unmatch_x) {
      int j =
          std::find(match_y.begin(), match_y.end(), false) - match_y.begin();
      puts("IMPROVE");
      printf("%d %d\n", unmatch_x + 1, j + 1);
    } else {
      puts("OPTIMAL");
    }
  }
}