#line 1 "sol.cpp"
#include <bits/stdc++.h>

char s[51];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    int odds = 0, cnt[]{0, 0};
    for (int i = 0; i < n; ++i) {
      scanf("%s", s);
      int len = strlen(s);
      odds += len & 1;
      for (int j = 0; j < len; ++j) {
        cnt[s[j] - '0'] ^= 1;
      }
    }
    printf("%d\n", [&]() {
      if (odds > 0) {
        return n;
      }
      return cnt[0] && cnt[1] ? n - 1 : n;
    }());
  }
}