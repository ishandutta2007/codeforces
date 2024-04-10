#line 1 "sol.cpp"
#include <bits/stdc++.h>

char s[200'001];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int dim;
    scanf("%d%s", &dim, s);
    auto solve = [&]() -> long long {
      int n = strlen(s);
      int zeros = std::count(s, s + n, s[0]);
      int ones = n - zeros;
      if (!ones) {
        return dim;
      }
      int first = 1;
      while (s[0] == s[first]) {
        first++;
      }
      long long result = dim - (zeros - first);
      int h = dim - zeros;
      int w = dim - ones;
      result += 1LL * h * w;
      result += 1LL * (zeros - first) * w;
      result += 1LL * (ones - 1) * h;
      return result;
    };
    printf("%lld\n", solve());
  }
}