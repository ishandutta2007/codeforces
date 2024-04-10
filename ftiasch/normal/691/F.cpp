#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int q;
  scanf("%d", &q);
  std::vector<int> b(q);
  for (int i = 0; i < q; ++i) {
    scanf("%d", &b[i]);
  }
  int m = std::max(*std::max_element(a.begin(), a.end()),
                   *std::max_element(b.begin(), b.end()));
  std::vector<int> count(m + 1), suf(m + 2);
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }
  for (int i = m; i >= 0; --i) {
    suf[i] = count[i] + suf[i + 1];
  }
  std::vector<long long> result(m + 1);
  for (int i = 1; i <= m; ++i) {
    for (int j = 1, pd = i; pd <= m; ++j, pd += i) {
      result[pd] += 1LL * count[i] * count[j];
    }
    result[m] += 1LL * count[i] * suf[m / i + 1];
    result[std::min(1LL * i * i, static_cast<long long>(m))] -= count[i];
  }
  for (int i = m; i--;) {
    result[i] += result[i + 1];
  }
  for (int i = 0; i < q; ++i) {
    printf("%lld\n", result[b[i]]);
  }
}