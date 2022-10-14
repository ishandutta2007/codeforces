#include <bits/stdc++.h>

const int N = 50;

char s[N + 1];

bool check(int mask) {
  int sum = 0;
  for (int i = 0; s[i]; ++i) {
    if (mask >> (s[i] - 'A') & 1) {
      sum++;
    } else {
      sum--;
    }
    if (sum < 0) {
      return false;
    }
  }
  return sum == 0;
}

bool check() {
  for (int mask = 0; mask < 8; ++mask) {
    if (check(mask)) {
      return true;
    }
  }
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    puts(check() ? "YES" : "NO");
  }
}