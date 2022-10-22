#include <bits/stdc++.h>

using namespace std;

struct BIT {
  vector<long long> sum;

  BIT(int _n) : sum(_n + 2, 0) {}

  void update(int x, long long v) {
    for (++x; x < (int)sum.size(); x += x&-x)
      sum[x] += v;
  }

  long long get(int x) {
    long long ret = 0;
    for (++x; x; x -= x&-x)
      ret += sum[x];
    return ret;
  }
};

const int M = 3e5 + 5;

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  BIT sum(M), cnt(M);
  long long ans = 0, tot = 0;
  for (int i = 0; i < n; ++i) {
    int v = a[i];
    ans += tot + 1LL * v * i - sum.get(v);
    long long last = 0;
    for (int u = v; u < M + v; u += v) {
      long long cur = cnt.get(min(u - 1, M));
      ans -= (u - v) * (cur - last);
      last = cur;
    }
    cnt.update(v, +1);
    for (int u = v; u < M; u += v) {
      sum.update(u, v);
    }
    tot += v;
    printf("%lld%c", ans, i + 1 == n ? '\n' : ' ');
  }
}

int main() {
  int tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}