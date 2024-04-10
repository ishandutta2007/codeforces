#include <bits/stdc++.h>

int l[3];

bool check() {
  for (int i = 0; i < 3; ++i) {
    for (int j = i + 1; j < 3; ++j) {
      int k = 3 - i - j;
      if (l[i] == l[j] && (l[k] & 1) == 0) {
        return true;
      }
      if (l[i] + l[j] == l[k]) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", l, l + 1, l + 2);
    puts(check() ? "YES" : "NO");
  }
}