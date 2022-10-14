#include <bits/stdc++.h>

const int N = 100000;

int s[N], ends[N], begins[N];

int main() {
  int n;
  scanf("%d", &n);
  int m = 0;
  for (int i = 0, l; i < n; ++i) {
    scanf("%d", &l);
    bool ok = true;
    for (int j = 0; j < l; ++j) {
      scanf("%d", s + j);
      ok &= !j || s[j - 1] >= s[j];
    }
    if (ok) {
      ends[m] = s[l - 1];
      begins[m++] = s[0];
    }
  }
  std::sort(ends, ends + m);
  std::sort(begins, begins + m);
  long long result = 1LL * n * n;
  for (int i = 0, j = 0; i < m; ++i) {
    while (j < m && begins[j] <= ends[i]) {
      j++;
    }
    result -= j;
  }
  printf("%lld\n", result);
}