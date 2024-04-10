#include <bits/stdc++.h>

const int N = 200'000;

int n, q, premin[N + 1], premax[N + 1], presum[N + 1], sufmin[N + 1],
    sufmax[N + 1];
char s[N + 1];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%s", &n, &q, s);
    premin[0] = premax[0] = presum[0] = 0;
    for (int i = 0; i < n; ++i) {
      presum[i + 1] = presum[i] + (s[i] == '+' ? 1 : -1);
      premin[i + 1] = std::min(premin[i], presum[i + 1]);
      premax[i + 1] = std::max(premax[i], presum[i + 1]);
    }
    sufmin[n] = sufmax[n] = 0;
    for (int i = n; i--;) {
      int a = s[i] == '+' ? 1 : -1;
      sufmin[i] = std::min(0, a + sufmin[i + 1]);
      sufmax[i] = std::max(0, a + sufmax[i + 1]);
    }
    while (q--) {
      int l, r;
      scanf("%d%d", &l, &r);
      l--;
      int min = std::min(premin[l], presum[l] + sufmin[r]);
      int max = std::max(premax[l], presum[l] + sufmax[r]);
      printf("%d\n", max - min + 1);
    }
  }
}