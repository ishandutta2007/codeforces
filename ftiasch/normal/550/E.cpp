#include <bits/stdc++.h>

const int N = 100000;

int n, a[N];

bool work() {
  if (a[n - 1]) {
    return false;
  }
  if (n == 1) {
    puts("Yes\n0");
    return true;
  }
  int i = 0;
  while (a[i]) {
    i++;
  }
  if (i == n - 2) {
    return false;
  }
  printf("Yes\n(");
  if (i == n - 1) {
    for (int j = 0; j < i; ++j) {
      printf("1");
      if (j + 1 < i) {
        printf("->");
      }
    }
    puts(")->0");
  } else {
    for (int j = 0; j < i; ++j) {
      printf("1->");
    }
    printf("0->(");
    for (int j = i + 1; j < n - 1; ++j) {
      printf("%d", a[j]);
      if (j + 1 < n - 1) {
        printf("->");
      }
    }
    puts("))->0");
  }
  return true;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  if (!work()) {
    puts("No");
  }
}