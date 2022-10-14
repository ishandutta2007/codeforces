#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;

int n, p[N], fenwick[N];
char s[N + 1], rev_s[N];

int main() {
  scanf("%d%s", &n, s);
  memcpy(rev_s, s, sizeof(char) * n);
  std::reverse(rev_s, rev_s + n);
  for (int cc = 0; cc < 26; ++cc) {
    char c = 'a' + cc;
    for (int i = 0, j = 0; i < n; ++i) {
      if (rev_s[i] == c) {
        while (s[j] != c) {
          j++;
        }
        p[i] = j++;
      }
    }
  }
  long long result = 0;
  for (int i = 0; i < n; ++i) {
    for (int k = p[i]; k < n; k += ~k & k + 1) {
        result += fenwick[k];
    }
    for (int k = p[i]; ~k; k -= ~k & k + 1) {
        fenwick[k] ++;
    }
  }
  printf("%lld\n", result);
}