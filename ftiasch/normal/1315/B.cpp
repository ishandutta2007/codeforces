#include <bits/stdc++.h>

const int N = 100000;

int a, b, p, n, dp[N];
char s[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d%s", &a, &b, &p, s);
    n = strlen(s);
    dp[n - 1] = 0;
    int nxt[]{n - 1, n - 1};
    for (int i = n - 1; i--;) {
      dp[i] = std::min((s[i] == 'A' ? a : b) + dp[nxt[s[i] - 'A' ^ 1]], p + 1);
      nxt[s[i] - 'A'] = i;
    }
    int i = 0;
    while (dp[i] > p) {
      i++;
    }
    printf("%d\n", i + 1);
  }
}