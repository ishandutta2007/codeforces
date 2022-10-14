#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 500'000;

int n, a[N], suffix[N];

int solve() {
  int result = 0;
  suffix[n - 1] = INT_MIN;
  for (int i = n - 2; i >= 0; --i) {
    suffix[i] = INT_MAX;
    if (a[i] > a[i + 1]) {
      suffix[i] = std::min(suffix[i], suffix[i + 1]);
    }
    if (a[i] > suffix[i + 1]) {
      suffix[i] = std::min(suffix[i], a[i + 1]);
    }
  }
  int m = std::max_element(a, a + n) - a;
  // ... m ... m' ....
  int prefix = INT_MIN;
  for (int i = 1; i <= m; ++i) {
    int new_dp = INT_MAX;
    if (a[i - 1] < a[i]) {
      new_dp = std::min(new_dp, prefix);
    }
    if (prefix < a[i]) {
      new_dp = std::min(new_dp, a[i - 1]);
    }
    prefix = new_dp;
  }
  int min_asc = prefix;   // i in desc
  int max_desc = INT_MIN; // i in asc
  for (int i = m + 1; i < n; ++i) {
    int new_asc = INT_MAX;
    if (a[i - 1] > a[i]) {
      // desc desc
      new_asc = std::min(new_asc, min_asc);
    }
    if (max_desc > a[i]) {
      // asc desc
      new_asc = std::min(new_asc, a[i - 1]);
    }
    int new_desc = INT_MIN;
    if (a[i - 1] < a[i]) {
      // asc asc
      new_desc = std::max(new_desc, max_desc);
    }
    if (min_asc < a[i]) {
      // desc asc
      new_desc = std::max(new_desc, a[i - 1]);
    }
    min_asc = new_asc;
    max_desc = new_desc;
    if (max_desc > suffix[i]) {
        result ++;
    }
  }
  return result;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  int result = solve();
  std::reverse(a, a + n);
  result += solve();
  printf("%d\n", result);
}