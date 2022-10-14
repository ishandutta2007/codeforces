#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::vector<char> s(n + 1);
  scanf("%s", s.data());
  long long result = 0;
  for (int i = 0; i < n;) {
    int j = i;
    while (s[i] == s[j]) {
      j++;
    }
    if (j - i <= m) {
      result += std::accumulate(a.begin() + i, a.begin() + j, 0LL);
    } else {
      std::nth_element(a.begin() + i, a.begin() + j - m, a.begin() + j);
      result += std::accumulate(a.begin() + j - m, a.begin() + j, 0LL);
    }
    i = j;
  }
  printf("%lld\n", result);
}