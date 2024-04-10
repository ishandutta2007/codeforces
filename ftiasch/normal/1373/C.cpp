#line 1 "sol.cpp"
#include <bits/stdc++.h>

char s[1'000'001];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    long long result = 0;
    int n = strlen(s), bound = 0, init = 0;
    for (int i = 0; i < n; ++i) {
      bound += s[i] == '+' ? -1 : 1;
      // [init, bound)
      if (init < bound) {
        result += (i + 1LL) * (bound - init);
        init = bound;
      }
    }
    printf("%lld\n", result + n);
  }
}