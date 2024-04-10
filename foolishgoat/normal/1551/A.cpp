#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  int a = n / 3, b = a;
  int c = n - a - 2 * b;
  if (c == 1)
    ++a;
  else if (c == 2)
    ++b;
  else
    assert(c == 0);
  printf("%d %d\n", a, b);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}