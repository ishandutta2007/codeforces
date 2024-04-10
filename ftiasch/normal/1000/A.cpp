#line 1 "sol.cpp"
#include <bits/stdc++.h>

int count[4][3];

int main() {
  int n;
  scanf("%d", &n);
  char buffer[5];
  for (int t = 0; t < 2; ++t) {
    int delta = t ? 1 : -1;
    for (int i = 0; i < n; ++i) {
      scanf("%s", buffer);
      int x = strlen(buffer) - 1;
      int s = buffer[x] == 'M' ? 2 : buffer[x] == 'L';
      count[x][s] += delta;
    }
  }
  int result = 0;
  for (int i = 0; i <= 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      result += std::abs(count[i][j]);
    }
  }
  printf("%d\n", result >> 1);
}