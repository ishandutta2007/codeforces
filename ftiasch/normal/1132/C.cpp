#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 5000;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<std::vector<int>> p(n);
  for (int i = 0, l, r; i < m; ++i) {
    scanf("%d%d", &l, &r);
    for (int j = l - 1; j < r; ++j) {
      if (static_cast<int>(p[j].size()) <= 2) {
        p[j].push_back(i);
      }
    }
  }
  int sum = 0;
  std::vector<int> one(m);
  std::vector<std::vector<int>> two(m, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    sum += !p[i].empty();
    if (static_cast<int>(p[i].size()) == 1) {
      one[p[i][0]]++;
    } else if (static_cast<int>(p[i].size()) == 2) {
      two[p[i][0]][p[i][1]]++;
    }
  }
  int result = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      result = std::max(result, sum - one[i] - one[j] - two[i][j]);
    }
  }
  printf("%d\n", result);
}