#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
typedef long long LL;
LL n, a[N], d[N], sum_pos;
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  for (int i = 2; i <= n; ++i) {
    d[i] = a[i] - a[i - 1];
    if (d[i] >= 0) sum_pos += d[i];
  }
  auto query = [&]{
    LL ans = (a[1] + sum_pos) / 2;
    if (ans > 0 and (a[1] + sum_pos) % 2 == 1) ++ ans;
    printf("%lld\n", ans);
  };
  auto upd = [&](int idx, LL dlt) {
    if (d[idx] >= 0) sum_pos -= d[idx];
    d[idx] += dlt;
    if (d[idx] >= 0) sum_pos += d[idx];
  };
  query();
  int q;
  scanf("%d", &q);
  while (q--) {
    LL l, r, x;
    scanf("%lld%lld%lld", &l, &r, &x);
    if (l == 1) a[1] += x;
    else upd(l, x);
    if (r < n) upd(r + 1, -x);
    query();
  }
}