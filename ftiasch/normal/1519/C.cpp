#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> u(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &u[i]);
    }
    std::vector<std::vector<int>> groups(n);
    for (int i = 0; i < n; ++i) {
      int s;
      scanf("%d", &s);
      groups[u[i] - 1].push_back(s);
    }
    std::vector<long long> result(n + 1), presum(n + 1);
    for (int i = 0; i < n; ++i) {
      std::vector<int> &group = groups[i];
      std::sort(group.begin(), group.end(), std::greater<int>());
      int c = group.size();
      presum[0] = 0;
      for (int i = 0; i < c; ++i) {
        presum[i + 1] = presum[i] + group[i];
      }
      for (int r = 1; r <= c; ++r) {
        result[r] += presum[c / r * r];
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%lld%c", result[i], " \n"[i == n]);
    }
  }
}