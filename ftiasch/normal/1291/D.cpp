#include <bits/stdc++.h>

const int N = 200001;

int q;
char s[N];
int count[N][26];

bool check(int l, int r) {
  if (r - l == 1) {
    return true;
  }
  if (s[l] != s[r - 1]) {
    return true;
  }
  int distincts = 0;
  for (int c = 0; c < 26; ++c) {
    distincts += count[r][c] > count[l][c];
  }
  return distincts > 2;
}

int main() {
#ifdef LOCAL_JUDGE
  freopen("D.in", "r", stdin);
#endif
  while (scanf("%s", s) == 1) {
    memset(count[0], 0, sizeof(count[0]));
    for (int i = 0; s[i]; ++i) {
      memcpy(count[i + 1], count[i], sizeof(count[i]));
      count[i + 1][s[i] - 'a']++;
    }
    scanf("%d", &q);
    for (int i = 0, l, r; i < q; ++i) {
      scanf("%d%d", &l, &r);
      puts(check(l - 1, r) ? "Yes" : "No");
    }
  }
}