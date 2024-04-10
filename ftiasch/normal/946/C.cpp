#line 1 "sol.cpp"
#include <bits/stdc++.h>

char s[100'001];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for (int j = 0, i = 0; j < 26; ++j) {
    while (i < n && s[i] - 'a' > j) {
      i++;
    }
    if (i == n) {
      puts("-1");
      return 0;
    }
    s[i ++] = 'a' + j;
  }
  puts(s);
}