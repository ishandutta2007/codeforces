#include <bits/stdc++.h>

namespace {
static const int N = 1 << 18;

char s[N + 1];
int n, dp[N];

void update(int i) {
  if (i << 1 >= n) {
    dp[i] = s[i] == '?' ? 2 : 1;
  } else {
    dp[i] = 0;
    if (s[i] != '0') {
      dp[i] += dp[i << 1];
    }
    if (s[i] != '1') {
      dp[i] += dp[i << 1 | 1];
    }
  }
}

} // namespace

int main() {
  int k;
  scanf("%d%s", &k, s + 1);
  n = 1 << k;
  std::reverse(s + 1, s + n);
  for (int i = n; i-- > 1;) {
    update(i);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int index;
    char buffer[2];
    scanf("%d%s", &index, buffer);
    index = n - index;
    s[index] = *buffer;
    for (int i = index; i; i >>= 1) {
      update(i);
    }
    printf("%d\n", dp[1]);
  }
}