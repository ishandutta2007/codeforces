#include <bits/stdc++.h>

long long result;

void work(int h) {
  int k, x0, x1;
  scanf("%d%d", &k, &x0);
  for (int i = 1; i < k; ++i) {
    scanf("%d", &x1);
  }
  result = std::max(result, 1LL * (x1 - x0) * h);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int w, h;
    scanf("%d%d", &w, &h);
    result = 0;
    work(h);
    work(h);
    work(w);
    work(w);
    printf("%lld\n", result);
  }
}