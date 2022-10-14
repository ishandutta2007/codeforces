#line 1 "sol.cpp"
#include <bits/stdc++.h>

char s[200'001];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    std::array<int, 26> count{};
    for (int i = 0; s[i]; ++i) {
      count[s[i] - 'a']++;
    }
    int i = 0;
    while (count[s[i] - 'a'] >= 2) {
      count[s[i++] - 'a']--;
    }
    puts(s + i);
  }
}