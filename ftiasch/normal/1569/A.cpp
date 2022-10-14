#include <bits/stdc++.h>

const int N = 50;

char s[N + 1];
int sum[N + 1], last[N + N + 1];

std::pair<int, int> solve(int n) {
  sum[0] = 0;
  memset(last, -1, sizeof(last));
  last[n] = 0;
  for (int i = 0; i < n; ++i) {
    sum[i + 1] = sum[i] + (s[i] == 'a' ? 1 : -1);
    int &ref = last[n + sum[i + 1]];
    if (~ref) {
      return {ref + 1, i + 1};
    }
    ref = i + 1;
  }
  return {-1, -1};
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d%s", &n, s);
    auto [a, b] = solve(n);
    printf("%d %d\n", a, b);
  }
}