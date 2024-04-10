#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'001;

int n, a[N], b[N];
bool taken[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", b + i);
  }
  for (int i = 0, j = 0; j < n; ++j) {
    int result = 0;
    while (!taken[b[j]]) {
      result++;
      taken[a[i++]] = true;
    }
    printf("%d%c", result, " \n"[j + 1 == n]);
  }
}