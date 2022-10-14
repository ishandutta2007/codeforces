#line 1 "sol.cpp"
#include <bits/stdc++.h>

char s[200'001];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    int cnt[]{0, 0, 0}, result = INT_MAX;
    for (int i = 0, j = 0; s[i]; i++) {
      cnt[s[i] - '1']++;
      if (cnt[0] && cnt[1] && cnt[2]) {
        while (j <= i && cnt[s[j] - '1'] > 1) {
          cnt[s[j] - '1']--;
          j++;
        }
        result = std::min(result, i - j + 1);
      }
    }
    printf("%d\n", result < INT_MAX ? result : 0);
  }
}