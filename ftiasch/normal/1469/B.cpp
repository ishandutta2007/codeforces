#include <bits/stdc++.h>

int read() {
  int n;
  scanf("%d", &n);
  int sum = 0, maxsum = 0;
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    sum += a;
    maxsum = std::max(maxsum, sum);
  }
  return maxsum;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a = read();
    int b = read();
    printf("%d\n", a + b);
  }
}