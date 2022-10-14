#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 30;

int n, b;
long long a[N];

bool check() {
  std::set<int> used;
  for (int i = 0; i < n; ++i) {
    long long x = a[i];
    for (int k = 0; x; ++k, x /= b) {
      int r = x % b;
      if (r > 1) {
        return false;
      }
      if (r == 1) {
        if (!used.insert(k).second) {
          return false;
        }
      }
    }
  }
  return true;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &b);
    for (int i = 0; i < n; ++i) {
      scanf("%lld", a + i);
    }
    puts(check() ? "YES" : "NO");
  }
}