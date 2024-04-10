#include <bits/stdc++.h>

const int N = 200'001;

int n, m, dp[N];
std::set<int> comb[N];

void update(int &x, int a) { x = std::max(x, a); }

int main() {
  int q;
  scanf("%d%d%d", &n, &m, &q);
  bool swapped = false;
  if (n > m) {
    swapped = true;
    std::swap(n, m);
  }
  for (int i = 0; i < q; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (swapped) {
      std::swap(x, y);
    }
    comb[x].insert(y);
  }
  dp[1] = 1;
  int steps = 0;
  while (dp[n] < m) {
    steps++;
    for (int i = n; i >= 1; --i) {
      int j = dp[i];
      if (j > 0) {
        int c = i + j + comb[i].count(j);
        update(dp[std::min(c, n)], j);
        update(dp[i], std::min(c, m));
      }
    }
  }
  printf("%d\n", steps);
}