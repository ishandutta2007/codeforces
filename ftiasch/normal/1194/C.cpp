#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 101;

char s[N], t[N], p[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s%s%s", s, t, p);
    int st_cnt[26]{}, p_cnt[26]{};
    for (int i = 0; s[i]; ++i) {
      st_cnt[s[i] - 'a']--;
    }
    for (int i = 0; t[i]; ++i) {
      st_cnt[t[i] - 'a']++;
    }
    for (int i = 0; p[i]; ++i) {
      p_cnt[p[i] - 'a']++;
    }
    bool ok = true;
    for (int i = 0; i < 26; ++i) {
      ok &= st_cnt[i] <= p_cnt[i];
    }
    for (int i = 0, j = 0; s[i] && ok; ++i) {
      while (t[j] && s[i] != t[j]) {
        j++;
      }
      if (t[j]) {
        j++;
      } else {
        ok = false;
      }
    }
    puts(ok ? "YES" : "NO");
  }
}