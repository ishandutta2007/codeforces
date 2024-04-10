#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1000;

int a[N];
std::pair<int, int> sufmin[N + 1];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    sufmin[n] = {n + 1, -1};
    for (int i = n; i--;) {
      sufmin[i] = std::min(sufmin[i + 1], {a[i], i});
    }
    std::pair<int, int> premin{n + 1, -1};
    bool found = false;
    for (int i = 0; i < n && !found; ++i) {
      if (premin.first < a[i] && a[i] > sufmin[i + 1].first) {
        found = true;
        printf("YES\n%d %d %d\n", premin.second + 1, i + 1,
               sufmin[i + 1].second + 1);
      }
      premin = std::min(premin, {a[i], i});
    }
    if (!found) {
      puts("NO");
    }
  }
}