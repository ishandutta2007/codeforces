#include <bits/stdc++.h>

long long compare(int x1, int p1, int x2, int p2) {
  if (p1 > p2) {
    return -compare(x2, p2, x1, p1);
  }
  // p1 <= p2
  int p = p2 - p1;
  // x1 ? x2 * 10^{p}
  if (p > 6) {
    return -1;
  }
  long long y = x2;
  for (int i = 0; i < p; ++i) {
    y *= 10;
  }
  return x1 - y;
}

int main() {
  std::ios::sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    int x1, p1, x2, p2;
    std::cin >> x1 >> p1 >> x2 >> p2;
    long long result = compare(x1, p1, x2, p2);
    puts(result == 0 ? "=" : (result > 0 ? ">" : "<"));
  }
}