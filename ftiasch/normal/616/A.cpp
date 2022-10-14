#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1'000'000;

char a[N + 1], b[N + 1];

int main() {
  scanf("%s%s", a, b);
  char *u = a;
  while (*u == '0') {
    u++;
  }
  char *v = b;
  while (*v == '0') {
    v++;
  }
  int n = strlen(u);
  int m = strlen(v);
  auto cmp = [&]() -> int {
    if (n != m) {
      return n - m;
    }
    for (int i = 0; i < n; ++i) {
      if (u[i] != v[i]) {
        return u[i] - v[i];
      }
    }
    return 0;
  };
  int result = cmp();
  puts(result ? (result < 0 ? "<" : ">") : "=");
}