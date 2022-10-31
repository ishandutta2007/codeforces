#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int N = 202020;
LL n, p[N], has[N];
int main() {
  scanf("%lld", &n);
  for (int i = 1, d; i < n; ++i) {
    scanf("%d", &d);
    p[i] = p[i - 1] + d;
  }
  LL mn = *min_element(p, p + n);
  for (int i = 0; i < n; ++i) {
    p[i] = p[i] - mn + 1;
  }
  for (int i = 0; i < n; ++i) {
    if (p[i] > n or has[p[i]]) {
      puts("-1");
      exit(0);
    }
    has[p[i]] = 1;
  }
  for (int i = 0; i < n; ++i) {
    printf("%lld%c", p[i], " \n"[i + 1 == n]);
  }
}