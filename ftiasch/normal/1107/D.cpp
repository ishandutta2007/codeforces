#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 5200;

int n, sqr[N + 1][N + 1], down[N];
char s[N / 4 + 1];
int a[N + 1][N + 1];

bool check(int x) {
  if (n % x != 0) {
    return false;
  }
  for (int i = 0; i < n; i += x) {
    for (int j = 0; j < n; j += x) {
      if (sqr[i][j] < x) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  scanf("%d", &n);
  memset(a, -1, sizeof(a));
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    for (int j = 0; s[j]; ++j) {
      int enc = std::isdigit(s[j]) ? s[j] - '0' : 10 + (s[j] - 'A');
      a[i][j << 2] = enc >> 3;
      a[i][j << 2 | 1] = enc >> 2 & 1;
      a[i][j << 2 | 2] = enc >> 1 & 1;
      a[i][j << 2 | 3] = enc & 1;
    }
  }
  for (int i = n; i--;) {
    int right = 0;
    for (int j = n; j--;) {
      right = (a[i][j] == a[i][j + 1] ? right : 0) + 1;
      down[j] = (a[i][j] == a[i + 1][j] ? down[j] : 0) + 1;
      sqr[i][j] =
          std::min({right, down[j],
                    (a[i][j] == a[i + 1][j + 1] ? sqr[i + 1][j + 1] : 0) + 1});
    }
  }
  int x = n;
  while (!check(x)) {
    x--;
  }
  printf("%d\n", x);
}