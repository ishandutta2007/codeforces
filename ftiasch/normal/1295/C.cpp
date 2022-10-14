#include <bits/stdc++.h>

const int N = 100000;
const int C = 26;

char a[N + 1], b[N + 1];
int nxt[N + 1][C];

int solve(int n) {
  int result = 1;
  for (int i = 0, j = 0; b[i]; ++i) {
    int c = b[i] - 'a';
    if (nxt[0][c] == n) {
      return -1;
    }
    if (nxt[j][c] < n) {
      j = nxt[j][c] + 1;
    } else {
      result++;
      j = nxt[0][c] + 1;
    }
  }
  return result;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s%s", a, b);
    int n = strlen(a);
    std::fill(nxt[n], nxt[n] + C, n);
    for (int i = n; i--;) {
      memcpy(nxt[i], nxt[i + 1], sizeof(int) * C);
      nxt[i][a[i] - 'a'] = i;
    }
    printf("%d\n", solve(n));
  }
}