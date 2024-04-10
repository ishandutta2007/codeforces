#include <bits/stdc++.h>

using Long = long long;

int main() {
  int n;
  Long limit;
  scanf("%d%lld", &n, &limit);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::reverse(a.begin(), a.end());
  auto check = [&](Long k) -> bool {
    if (k == 0) {
      return *std::max_element(a.begin(), a.end()) >= limit;
    }
    Long sum = 0;
    __int128 binom = 1;
    for (int i = 0; i < n; ++i) {
      sum = std::min(sum + __int128(binom) * a[i], __int128(limit));
      binom = binom * (k + i) <= __int128(limit) * (i + 1) ? binom * (k + i) / (i + 1) : limit;
    }
    return sum >= limit;
  };
  Long low = 0;
  Long high = limit;
  while (low < high) {
    Long middle = (low + high) >> 1;
    if (check(middle)) {
      high = middle;
    } else {
      low = middle + 1;
    }
  }
  printf("%lld\n", high);
}