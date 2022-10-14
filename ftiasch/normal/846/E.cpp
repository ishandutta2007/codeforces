#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;

const Long LIMIT = 1'000'000'000'000'000'000;

Long safe_mul(Long a, Long b) { return a <= LIMIT / b ? a * b : LIMIT; }

int main() {
  int n;
  scanf("%d", &n);
  std::vector<Long> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    Long demand;
    scanf("%lld", &demand);
    a[i] -= demand;
  }
  std::vector<int> parent(n), coef(n);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &parent[i], &coef[i]);
    parent[i]--;
  }
  for (int i = n; i-- > 1;) {
    if (a[i] >= 0) {
      a[parent[i]] += a[i];
    } else {
      a[parent[i]] = std::max(a[parent[i]] - safe_mul(-a[i], coef[i]), -LIMIT);
    }
  }
  puts(a[0] >= 0 ? "YES" : "NO");
}