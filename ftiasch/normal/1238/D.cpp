#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 300'000;

int n;
char s[N + 1];

int main() {
  scanf("%d%s", &n, s);
  long long result = n * (n + 1LL) / 2 - n;
  for (int _ = 0; _ < 2; ++_) {
    int con = 1;
    for (int i = 1; i < n; ++i) {
      if (s[i - 1] != s[i]) {
        result -= con;
        con = 1;
      } else {
        con++;
      }
    }
    std::reverse(s, s + n);
  }
  for (int i = 1; i < n; ++i) {
    result += s[i - 1] != s[i];
  }
  printf("%lld\n", result);
}