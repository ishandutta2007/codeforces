#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1'000'000;

int n, a[N];

void work() {
  std::sort(a, a + n);
  int last_two = 0, p = 1, q = 0;
  for (int i = 0; i < n;) {
    int count = 0;
    while (i + count < n && a[i] == a[i + count]) {
      count++;
    }
    if (count >= 4) {
      printf("%d %d %d %d\n", a[i], a[i], a[i], a[i]);
      return;
    }
    if (count >= 2) {
      if (last_two && a[i] * q < p * last_two) {
        std::tie(p, q) = std::make_pair(a[i], last_two);
      }
      last_two = a[i];
    }
    i += count;
  }
  printf("%d %d %d %d\n", q, q, p, p);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    work();
  }
}