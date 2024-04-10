#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100'000;

char a[N + 1], b[N + 1];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s%s", a, b);
    int n = strlen(a);
    int m = strlen(b);
    int j = m - 1;
    while (b[j] == '0') {
      j--;
    }
    int k = 0;
    while (a[n - (m - j) - k] == '0') {
      k++;
    }
    printf("%d\n", k);
  }
}