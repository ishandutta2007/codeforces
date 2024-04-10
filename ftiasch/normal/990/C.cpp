#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 300'000;

int n, right[N], count[N + 1];
char s[N + 1];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    int len = strlen(s);
    {
      int left = 0;
      for (int i = 0; i < len; ++i) {
        if (s[i] == '(') {
          left++;
        } else {
          left--;
          if (left < 0) {
            break;
          }
        }
      }
      if (left >= 0) {
        count[left]++;
      }
    }
    {
      int count = 0;
      for (int i = len; i--;) {
        if (s[i] == ')') {
          count++;
        } else {
          count--;
          if (count < 0) {
            break;
          }
        }
      }
      right[i] = count;
    }
  }
  long long result = 0;
  for (int i = 0; i < n; ++i) {
    if (right[i] >= 0) {
      result += count[right[i]];
    }
  }
  printf("%lld\n", result);
}