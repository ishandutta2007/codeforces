#include <bits/stdc++.h>

int n;
char s[100001];

int main() {
  scanf("%d%s", &n, s);
  int l = 0, r = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') {
      l++;
    } else {
      r++;
    }
  }
  printf("%d\n", l + r + 1);
}