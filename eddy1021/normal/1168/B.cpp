#include <bits/stdc++.h>
using namespace std;
constexpr int N = 303030;
char c[N];
int n;
int main() {
  scanf("%s", c);
  n = strlen(c);
  long long ans = 0;
  for (int l = n - 1, dp = n; l >= 0; --l) {
    for (int i = dp - 1; i >= l + 2; --i) {
      if ((i - l) % 2) {
        continue;
      }
      int mid = (l + i) >> 1;
      if (c[l] == c[mid] and c[i] == c[mid]) {
        dp = i;
      }
    }
    ans += n - dp;
  }
  printf("%lld\n", ans);
}