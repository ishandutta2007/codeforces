#include <bits/stdc++.h>

int solve(int n, std::vector<int> &&a) {
  int s = std::accumulate(a.begin(), a.end(), 0);
  if (s % n != 0) {
    return -1;
  }
  int avg = s / n;
  return std::count_if(a.begin(), a.end(), [&](int x) { return x > avg; });
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    printf("%d\n", solve(n, std::move(a)));
  }
}