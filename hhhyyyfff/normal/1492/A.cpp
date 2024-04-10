#include <bits/stdc++.h>

using namespace std;

int T;
long long ans, p, a;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%lld", &p);
    ans = 1e18;
    for (int i = 0; i < 3; ++i) {
      scanf("%lld", &a);
      ans = min(ans, a - (p - 1) % a - 1);
    }
    printf("%lld\n", ans);
  }
  return 0;
}