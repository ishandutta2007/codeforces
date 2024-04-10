#line 1 "sol.cpp"
#include <bits/stdc++.h>

char s[101];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    int n = strlen(s);
    int count[]{0, 0};
    for (int i = 0; i < n; ++i) {
      count[s[i] - '0']++;
    }
    puts(std::min(count[0], count[1]) & 1 ? "DA" : "NET");
  }
}