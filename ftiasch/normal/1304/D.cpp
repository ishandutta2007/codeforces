#include <bits/stdc++.h>

const int N = 200000;

char cmp[N];
int a[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d%s", &n, cmp);
    for (int i = 0, prev = 0; i < n; ++i) {
      if (i == n - 1 || cmp[i] == '>') {
        int start = n - i;
        for (int j = prev; j <= i && j < n; ++j) {
          a[j] = start + j - prev;
        }
        prev = i + 1;
      }
    }
    for (int i = 0; i < n; ++i) {
      printf("%d%c", a[i], " \n"[i + 1 == n]);
    }
    for (int i = 0, prev = 0; i < n; ++i) {
      if (i == n - 1 || cmp[i] == '<') {
        int start = i + 1;
        for (int j = prev; j <= i && j < n; ++j) {
          a[j] = start - j + prev;
        }
        prev = i + 1;
      }
    }
    for (int i = 0; i < n; ++i) {
      printf("%d%c", a[i], " \n"[i + 1 == n]);
    }
  }
}