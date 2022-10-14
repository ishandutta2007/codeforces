#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  long long t;
  scanf("%d%d%lld", &n, &m, &t);
  char buffer[2];
  std::vector<std::pair<int, int>> a(n);
  std::vector<int> b(n);
  int offset = 0;
  for (int i = 0, x_; i < n; ++i) {
    scanf("%d%s", &x_, buffer);
    long long x = x_ - 1;
    a[i] = {x, i};
    if (*buffer == 'R') {
      x += t;
      offset = (offset + x / m) % n;
      x %= m;
    } else {
      x -= t;
      offset = offset + n - ((-x + m - 1) / m) % n;
      if (offset >= n) {
        offset -= n;
      }
      x %= m;
      if (x < 0) {
        x += m;
      }
    }
    b[i] = x;
  }
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  std::vector<int> result(n);
  for (int i = 0; i < n; ++i) {
    result[a[i].second] = b[(offset + i) % n];
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", 1 + result[i], " \n"[i + 1 == n]);
  }
}