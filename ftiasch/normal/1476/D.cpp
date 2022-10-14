#include <bits/stdc++.h>

const int N = 300'001;

char s[N];
int left[N], right[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d%s", &n, s);
    left[0] = 1;
    for (int i = 1; i <= n; ++i) {
      if (s[i - 1] == 'L') {
        if (i >= 2 && s[i - 2] == 'R') {
          left[i] = left[i - 2] + 2;
        } else {
          left[i] = 2;
        }
      } else {
        left[i] = 1;
      }
    }
    right[n] = 1;
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == 'R') {
        if (i + 1 < n && s[i + 1] == 'L') {
          right[i] = right[i + 2] + 2;
        } else {
          right[i] = 2;
        }
      } else {
        right[i] = 1;
      }
    }
    for (int i = 0; i <= n; ++i) {
      printf("%d%c", left[i] + right[i] - 1, " \n"[i == n]);
    }
  }
}