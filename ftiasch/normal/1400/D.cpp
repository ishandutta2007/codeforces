#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n), cnt(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      a[i]--;
    }
    long long result = 0;
    for (int j = n; j--;) {
      int cross = 0;
      for (int i = j; i--;) {
        if (a[i] == a[j]) {
          result += cross;
        }
        cross += cnt[a[i]];
      }
      cnt[a[j]]++;
    }
    printf("%lld\n", result);
  }
}