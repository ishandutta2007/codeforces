#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 300'000;

char s[N + 1];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    std::vector<char> v[2];
    for (int i = 0; s[i]; ++i) {
      v[(s[i] - '0') & 1].push_back(s[i]);
    }
    int s[2];
    s[0] = v[0].size();
    s[1] = v[1].size();
    for (int i = 0, j = 0; i < s[0] || j < s[1];) {
      if (j == s[1] || i < s[0] && v[0][i] < v[1][j]) {
        putchar(v[0][i++]);
      } else {
        putchar(v[1][j++]);
      }
    }
    puts("");
  }
}