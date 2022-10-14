#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200000;

char s[N + 1];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    int result = 0, count[] = {0, 0};
    for (int i = 0; s[i]; ++i) {
      int t = s[i] == '[' || s[i] == ']';
      if (s[i] == '(' || s[i] == '[') {
        count[t]++;
      } else if (count[t]) {
        result++;
        count[t]--;
      }
    }
    printf("%d\n", result);
  }
}