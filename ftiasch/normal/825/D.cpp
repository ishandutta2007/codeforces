#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1'000'000;
const int C = 26;

char s[N + 1], t[N + 1];

int main() {
  int qm = 0;
  std::array<int, C> s_cnt{}, t_cnt{}, need{};
  scanf("%s%s", s, t);
  for (int i = 0; s[i]; ++i) {
    if (s[i] == '?') {
      qm++;
    } else {
      s_cnt[s[i] - 'a']++;
    }
  }
  for (int i = 0; t[i]; ++i) {
    t_cnt[t[i] - 'a']++;
  }
  auto check = [&](int occ) {
    int need = 0;
    for (int c = 0; c < C; ++c) {
      if (t_cnt[c] * occ > s_cnt[c]) {
        need += t_cnt[c] * occ - s_cnt[c];
        if (need > qm) {
          return false;
        }
      }
    }
    return true;
  };
  int result = 0;
  while (check(result + 1)) {
    result++;
  }
  for (int c = 0; c < C; ++c) {
    need[c] = std::max(t_cnt[c] * result - s_cnt[c], 0);
  }
  for (int i = 0, c = 0; s[i]; ++i) {
    if (s[i] == '?') {
      while (c < C && !need[c]) {
        c++;
      }
      if (c < C) {
        need[c]--;
        s[i] = 'a' + c;
      } else {
        s[i] = 'z';
      }
    }
  }
  puts(s);
}