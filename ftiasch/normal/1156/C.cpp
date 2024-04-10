#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::sort(a.begin(), a.end());
  int low = 0;
  int high = n >> 1;
  while (low < high) {
    int middle = (low + high + 1) >> 1;
    bool ok = true;
    for (int i = 0; i < middle; ++i) {
      ok &= a[n - middle + i] - a[i] >= m;
    }
    if (ok) {
      low = middle;
    } else {
      high = middle - 1;
    }
  }
  printf("%d\n", low);
}