#line 1 "sol.cpp"
// #include "debug.h"

#include <bits/stdc++.h>

const int N = 300'000;

int a, b;
char s[N + 1];

int type(int l) {
  if (b <= l && l < a) {
    return 0;
  }
  if (a <= l && l < 2 * b) {
    return 1;
  }
  if (2 * b <= l) {
    return 2;
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%s", &a, &b, s);
    std::vector<int> segs;
    for (int i = 0; s[i];) {
      if (s[i] == 'X') {
        i++;
      } else {
        int j = i;
        while (s[j] == '.') {
          j++;
        }
        int len = j - i;
        if (len >= b) {
          segs.push_back(len);
        }
        i = j;
      }
    }
    bool awin = false;
    int cnt[3];
    memset(cnt, 0, sizeof(cnt));
    for (int l : segs) {
      cnt[type(l)]++;
    }
    // after Alice moves, there is no segments of type 0 or 2 and the num of
    // type 1 is even
    for (int len : segs) {
      int t = type(len);
      // printf("len=%d type=%d\n", len, t);
      cnt[t]--;
      if (len >= a && !cnt[0] && !cnt[2]) {
        // alice can move
        // x + y = len - a
        // x types | y types
        // -1      | -1
        // -1      | 1
        // 1       | 1
        int s = len - a;
        if (s <= (b - 1) * 2 && !(cnt[1] & 1)) {
          awin = true;
        }
        if (a < 2 * b) {
          // [0, b - 1] + [a, 2b - 1] = [a, 3b)
          if (a <= s && s <= 3 * b - 2 && (cnt[1] & 1)) {
            awin = true;
          }
          if (2 * a <= s && s <= 4 * b - 2 && !(cnt[1] & 1)) {
            awin = true;
          }
        }
      }
      cnt[t]++;
    }
    // printf("%d %d %s ", a, b, s);
    puts(awin ? "YES" : "NO");
  }
}