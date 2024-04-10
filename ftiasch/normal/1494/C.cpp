#include <bits/stdc++.h>

int solve(const std::vector<int> &a, const std::vector<int> &b) {
  int n = a.size();
  int m = b.size();
  std::vector<int> suffix(m + 1);
  for (int j = m, i = n - 1; j--;) {
    while (~i && b[j] < a[i]) {
      i--;
    }
    suffix[j] = suffix[j + 1] + (~i && a[i] == b[j]);
  }
  int result = 0;
  for (int j = 0, i = 0, k = 0; j < m; ++j) {
    while (i < n && a[i] <= b[j]) {
      i++;
    }
    while (k <= j && b[j] - b[k] + 1 > i) {
      k++;
    }
    while (k && b[j] - b[k - 1] + 1 <= i) {
      k--;
    }
    result = std::max(result, j - k + 1 + suffix[j + 1]);
  }
  return result;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<int> a[2], b[2];
    for (int i = 0, x; i < n; ++i) {
      scanf("%d", &x);
      if (x > 0) {
        a[0].push_back(x);
      } else {
        a[1].push_back(-x);
      }
    }
    for (int i = 0, x; i < m; ++i) {
      scanf("%d", &x);
      if (x > 0) {
        b[0].push_back(x);
      } else {
        b[1].push_back(-x);
      }
    }
    std::reverse(a[1].begin(), a[1].end());
    std::reverse(b[1].begin(), b[1].end());
    printf("%d\n", solve(a[0], b[0]) + solve(a[1], b[1]));
  }
}