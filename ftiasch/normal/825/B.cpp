#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int DX[]{1, 0, 1, 1};
const int DY[]{0, 1, 1, -1};

char s[10][11];

bool check() {
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      for (int k = 0; k < 4; ++k) {
        bool has_o = false;
        int cnt = 0, x = i, y = j;
        for (int _ = 0; _ < 5; ++_) {
          if (0 <= x && x < 10 && 0 <= y && y < 10) {
            if (s[x][y] == 'O') {
              has_o = true;
            } else {
              cnt += s[x][y] == '.';
            }
          } else {
            has_o = true;
          }
          x += DX[k];
          y += DY[k];
        }
        if (!has_o && cnt == 1) {
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  for (int i = 0; i < 10; ++i) {
    scanf("%s", s[i]);
  }
  puts(check() ? "YES" : "NO");
}