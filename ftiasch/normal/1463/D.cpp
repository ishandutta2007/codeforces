// #include "debug.h"

#include <bits/stdc++.h>

int T;

// a prefix < b suffix
int solve(int n, const std::vector<int> &a, const std::vector<int> &b) {
  int low = 0;
  int high = n;
  while (low < high) {
    int middle = (low + high + 1) >> 1;
    bool ok = true;
    for (int i = 0; i < middle; ++i) {
      ok &= a[i] < b[n - middle + i];
    }
    if (ok) {
      low = middle;
    } else {
      high = middle - 1;
    }
  }
  return low;
}

int main() {
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a, b(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &b[i]);
    }
    a.reserve(n);
    for (int i = 1, j = 0; i <= n + n; ++i) {
      if (j < n && i == b[j]) {
        j++;
      } else {
        a.push_back(i);
      }
    }
    // x pairs with b min
    // a max max ... min min
    // b min min ... max max
    // b prefix x <= a suffix a
    // a prefix (n - x) <= b suffix (n - x)
    int max_x = solve(n, b, a);
    int min_x = n - solve(n, a, b);
    // std::cout << KV(max_x) << KV(min_x) << std::endl;
    printf("%d\n", std::max(max_x - min_x + 1, 0));
  }
}