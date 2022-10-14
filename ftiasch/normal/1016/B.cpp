#line 1 "/home/ftiasch/Documents/shoka/prefix_table.h"
#include <algorithm>
#include <vector>

std::vector<int> prefix_table(int n, const char *s) {
  std::vector<int> z(n);
  z[0] = 0;
  for (int i = 1, j = 0; i < n; ++i) {
    z[i] = i < j + z[j] ? std::min(z[i - j], j + z[j] - i) : 0;
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] > j + z[j]) {
      j = i;
    }
  }
  z[0] = n;
  return z;
}
#line 2 "sol.cpp"

#include <bits/stdc++.h>

const int N = 1000;

int n, m, q, sum[N + 1];
char s[N + 1], t[N + N + 1];

int count(int l, int r) {
  r = r - m + 1;
  if (l >= r) {
    return 0;
  }
  return sum[l] - sum[r];
}

int main() {
  scanf("%d%d%d%s%s", &n, &m, &q, s, t);
  memcpy(t + m + 1, s, sizeof(char) * n);
  auto z = prefix_table(m + 1 + n, t);
  for (int i = n; i--;) {
    sum[i] = (z[m + 1 + i] >= m) + sum[i + 1];
  }
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", count(l - 1, r));
  }
}