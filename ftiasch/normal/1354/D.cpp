#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  std::vector<int> a(n), b(q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < q; ++i) {
    scanf("%d", &b[i]);
  }
  int low = 0;
  int high = n;
  while (low < high) {
    int middle = (low + high + 1) >> 1;
    // if >= middle
    int zeros = std::lower_bound(a.begin(), a.end(), middle) - a.begin();
    int ones = n - zeros;
    for (int i = 0; i < q; ++i) {
      if (b[i] > 0) {
        (b[i] >= middle ? ones : zeros)++;
      } else {
        int r = -b[i];
        if (r <= zeros) {
          zeros--;
        } else {
          ones--;
        }
      }
    }
    if (ones) {
      low = middle;
    } else {
      high = middle - 1;
    }
  }
  printf("%d\n", low);
}