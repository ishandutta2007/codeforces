#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100;

int n, a[N], count[3];
char s[N + 1];

void work() {
  if (count[0] && count[1] && count[2]) {
    return;
  }
  for (int len = 1; len <= 3; ++len) {
    for (int i = 0; i + len <= n; ++i) {
      int sub[]{count[0], count[1], count[2]};
      for (int j = 0; j < len; ++j) {
        sub[a[i + j]]--;
      }
      if ((!sub[0] + !sub[1] + !sub[2]) <= len) {
        for (int j = 0; j < 3; ++j) {
          if (!sub[j]) {
            s[i++] = "0aA"[j];
          }
        }
        return;
      }
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    n = strlen(s);
    memset(count, 0, sizeof(count));
    for (int i = 0; i < n; ++i) {
      if (std::isdigit(s[i])) {
        a[i] = 0;
      } else if (std::islower(s[i])) {
        a[i] = 1;
      } else {
        a[i] = 2;
      }
      count[a[i]]++;
    }
    work();
    puts(s);
  }
}