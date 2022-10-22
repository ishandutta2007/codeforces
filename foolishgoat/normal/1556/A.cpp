#include <bits/stdc++.h>

using namespace std;

int solve() {
  int u, v;
  scanf("%d %d", &u, &v);
  if ((u + v) & 1) {
    puts("-1");
    return 0;
  }
  if (u == 0 && v == 0) {
    puts("0");
    return 0;
  }
  if (abs(u) == abs(v)) {
    puts("1");
    return 0;
  }
  puts("2");
  return 0;
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  for (int t = 1; t <= tc; ++t) {
    solve();
  }
  return 0;
}