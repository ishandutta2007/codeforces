#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100001;

int n, a[N];
long long s[N];

int take(int i, int lim) {
  return static_cast<int>(std::upper_bound(s + i, s + (n + 1), s[i] + lim) -
                          (s + i)) -
         1;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int lim;
    scanf("%d%d", &n, &lim);
    s[0] = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      s[i] = s[i - 1] + a[i];
    }
    std::pair<int, int> result{take(0, lim), 0};
    for (int i = 1; i <= n; ++i) {
      if (s[i - 1] - s[0] <= lim) {
        result =
            std::max(result, {(i - 1) + take(i, lim - (s[i - 1] - s[0])), i});
      }
    }
    printf("%d\n", result.second);
  }
}