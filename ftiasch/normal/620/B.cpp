#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int SEGMENTS[]{6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  int result = 0;
  for (int i = a; i <= b; ++i) {
    int x = i;
    while (x) {
      result += SEGMENTS[x % 10];
      x /= 10;
    }
  }
  printf("%d\n", result);
}