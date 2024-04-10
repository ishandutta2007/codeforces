#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1000;

std::tuple<int, int, int> result[N + 1];

int main() {
  memset(result, -1, sizeof(result));
  for (int c = 0; c < 3; ++c) {
    for (int b = 0; b < 3; ++b) {
      for (int a = 0; 3 * a + 5 * b + 7 * c <= N; ++a) {
        result[3 * a + 5 * b + 7 * c] = {a, b, c};
      }
    }
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    auto [a, b, c] = result[n];
    if (!~a) {
      puts("-1");
    } else {
      printf("%d %d %d\n", a, b, c);
    }
  }
}