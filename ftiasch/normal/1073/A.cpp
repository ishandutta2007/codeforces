#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1000;

int n, count[26];
char s[N + 1];

int main() {
  scanf("%d%s", &n, s);
  for (int i = 0; i < n; ++i) {
    memset(count, 0, sizeof(count));
    int max_count = 0;
    for (int j = i; j < n; ++j) {
      max_count = std::max(max_count, ++count[s[j] - 'a']);
      if (max_count + max_count <= j - i + 1) {
          s[j + 1] = '\0';
          printf("YES\n%s\n", s + i);
          return 0;
      }
    }
  }
  puts("NO");
}