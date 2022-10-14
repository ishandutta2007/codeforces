#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100;

char s[N + 1];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d%s", &n, s);
    bool ok = true;
    for (int i = 0; i < n - 1 - i; ++i) {
      ok &= s[i] == s[n - 1 - i] || std::abs(s[i] - s[n - 1 - i]) == 2;
    }
    puts(ok ? "YES" : "NO");
  }
}