#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 18;

int n, rank[2][1 << N];
char s[(1 << N) + 1];
std::pair<std::pair<int, int>, int> order[1 << N];

int main() {
  scanf("%d%s", &n, s);
  for (int j = 0; j < 1 << n; ++j) {
    rank[0][j] = s[j] - 'a';
  }
  for (int k = 1; k <= n; ++k) {
    for (int j = 0; j < 1 << n; ++j) {
      order[j] = {{rank[(k + 1) & 1][j], rank[(k + 1) & 1][j ^ (1 << (k - 1))]},
                  j};
    }
    std::sort(order, order + (1 << n));
    int current = 0;
    for (int j = 0; j < 1 << n; ++j) {
      current += j && (order[j - 1].first != order[j].first);
      rank[k & 1][order[j].second] = current;
    }
  }
  int j = std::find(rank[n & 1], rank[n & 1] + (1 << n), 0) - rank[n & 1];
  for (int i = 0; i < 1 << n; ++ i) {
      putchar(s[i ^ j]);
  }
  puts("");
}