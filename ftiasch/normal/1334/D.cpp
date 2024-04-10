#line 1 "sol.cpp"
#include <bits/stdc++.h>

void work(int n, long long l, long long r) {
  long long c = 0;
  for (int i = 1; i < n; ++i) {
    if (c + 2 * (n - i) < l) {
      c += 2 * (n - i);
    } else if (r <= c) {
      continue;
    } else {
      for (int j = i + 1; j <= n; ++j) {
        ++c;
        if (l <= c && c <= r) {
          printf("%d%c", i, " \n"[c == r]);
        }
        ++c;
        if (l <= c && c <= r) {
          printf("%d%c", j, " \n"[c == r]);
        }
      }
    }
  }
  ++c;
  if (l <= c && c <= r) {
    printf("%d%c", 1, " \n"[c == r]);
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    long long l, r;
    scanf("%d%lld%lld", &n, &l, &r);
    work(n, l, r);
  }
}