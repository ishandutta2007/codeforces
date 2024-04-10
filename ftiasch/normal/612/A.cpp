#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, p, q;
  scanf("%d%d%d", &n, &p, &q);
  std::vector<char> s(n + 1);
  scanf("%s", s.data());
  auto [x, y] = [&]() -> std::pair<int, int> {
    for (int i = 0; i * p <= n; ++i) {
      if ((n - i * p) % q == 0) {
        return {i, (n - i * p) / q};
      }
    }
    return {-1, -1};
  }();
  if (~x) {
    printf("%d\n", x + y);
    int offset = 0;
    for (int i = 0; i < x + y; ++i) {
      int l = i < x ? p : q;
      for (int j = 0; j < l; ++j) {
        putchar(s[offset + j]);
      }
      puts("");
      offset += l;
    }
  } else {
    puts("-1");
  }
}