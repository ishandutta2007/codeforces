#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 300'000;

char s[N + 1];

int main() {
  scanf("%s", s);
  long long result = 0;
  for (int i = 0; s[i]; ++i) {
    result += (s[i] - '0') % 4 == 0;
    if (i && ((s[i - 1] - '0') * 10 + s[i] - '0') % 4 == 0) {
      result += i;
    }
  }
  printf("%lld\n", result);
}