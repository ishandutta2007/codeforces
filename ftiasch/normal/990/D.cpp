#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1000;

bool graph[N][N];

int main() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  auto work = [&]() -> bool {
    if (a > 1 && b > 1) {
      return false;
    }
    if (a == 1 && b == 1) {
      if (n == 2 || n == 3) {
        return false;
      }
      for (int i = 1; i < n; ++i) {
        graph[i - 1][i] = graph[i][i - 1] = true;
      }
    } else if (a > 1) {
      for (int i = a; i < n; ++i) {
        graph[i - 1][i] = graph[i][i - 1] = true;
      }
    } else {
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          graph[i][j] = graph[j][i] = true;
        }
      }
      for (int i = b; i < n; ++i) {
        graph[i - 1][i] = graph[i][i - 1] = false;
      }
    }
    puts("YES");
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        putchar("01"[graph[i][j]]);
      }
      puts("");
    }
    return true;
  };
  if (!work()) {
    puts("NO");
  }
}