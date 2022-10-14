#line 1 "sol.cpp"
#include <bits/stdc++.h>

char s[200'001];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    int cnt[2]{};
    for (int i = 0; s[i]; ++i) {
      cnt[s[i] - '0']++;
    }
    if (cnt[0] == cnt[1]) {
      printf("%d\n", cnt[0] - 1);
    } else {
      printf("%d\n", std::min(cnt[0], cnt[1]));
    }
  }
}