#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, s, k;
    scanf("%d%d%d", &n, &s, &k);
    std::set<int> closed;
    while (k--) {
      int a;
      scanf("%d", &a);
      closed.insert(a);
    }
    auto check = [&](int x) { return 1 <= x && x <= n && !closed.count(x); };
    int res = 0;
    while (!check(s - res) && !check(s + res)) {
      res++;
    }
    printf("%d\n", res);
  }
}