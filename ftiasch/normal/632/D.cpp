#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> a(n), count(m + 1);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] <= m) {
      count[a[i]] += 1;
    }
  }
  for (int i = m; i >= 1; --i) {
    for (int j = i + i; j <= m; j += i) {
      count[j] += count[i];
    }
  }
  int l = std::max_element(count.begin() + 1, count.end()) - count.begin();
  int kmax = 0;
  for (int i = 0; i < n; ++i) {
    kmax += l % a[i] == 0;
  }
  printf("%d %d\n", l, kmax);
  for (int i = 0; i < n; ++i) {
    if (l % a[i] == 0) {
      printf("%d ", i + 1);
    }
  }
}