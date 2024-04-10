#include <bits/stdc++.h>

const int N = 100;

int n, m, o[N];
std::vector<int> p[N];
std::pair<int, int> result[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0, c; i < n * m; ++i) {
    scanf("%d", &c);
    p[c - 1].push_back(i);
  }
  std::iota(o, o + n, 0);
  int bound = (n + (m - 2)) / (m - 1);
  std::fill(result, result + n, std::make_pair(-1, -1));
  for (int k = 1; k < m; ++k) {
    std::sort(o, o + n, [&](int i, int j) { return p[i][k] < p[j][k]; });
    int count = 0;
    for (int _ = 0; _ < n && count < bound; ++_) {
      int i = o[_];
      if (result[i].first == -1) {
        result[i] = std::make_pair(p[i][k - 1], p[i][k]);
        count++;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d %d\n", result[i].first + 1, result[i].second + 1);
  }
}