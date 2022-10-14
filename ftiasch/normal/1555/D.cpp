#include <bits/stdc++.h>

const int N = 200000;

int n, q;
char s[N + 1];
int count[3][3][N + 1];

int main() {
  scanf("%d%d%s", &n, &q, s);
  for (int c = 0; c < 3; ++c) {
    for (int p = 0; p < 3; ++p) {
      count[c][p][n] = 0;
      for (int i = n; i--;) {
        count[c][p][i] = count[c][p][i + 1] + (s[i] - 'a' == c && i % 3 == p);
      }
    }
  }
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    int result = 0;
    for (int a = 0; a < 3; ++a) {
      for (int b = 0; b < 3; ++b) {
        if (a == b) {
          continue;
        }
        int c = 3 - a - b;
        // abcabc
        result = std::max(result, count[a][0][l] - count[a][0][r] +
                                      count[b][1][l] - count[b][1][r] +
                                      count[c][2][l] - count[c][2][r]);
      }
    }
    printf("%d\n", r - l - result);
  }
}