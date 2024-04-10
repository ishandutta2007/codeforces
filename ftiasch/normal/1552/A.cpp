#include <bits/stdc++.h>

const int N = 40;

char s[N + 1];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d%s", &n, s);
    int count[26];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < n; ++i) {
      count[s[i] - 'a']++;
    }
    int result = 0;
    for (int c = 0, i = 0; c < 26; ++c) {
      while (count[c]--) {
        if (s[i] != 'a' + c) {
          result++;
        }
        i++;
      }
    }
    printf("%d\n", result);
  }
}