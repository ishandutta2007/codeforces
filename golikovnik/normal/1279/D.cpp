#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int const MAX = (int) 1e6 + 20;
  vector<vector<int>> a(n);
  vector<int> cnt(MAX);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    a[i].resize(k);
    for (int j = 0; j < k; ++j) {
      int x;
      cin >> x;
      --x;
      a[i][j] = x;
      ++cnt[x];
    }
  }
  int const MOD = 998244353;
  auto add = [&](int x, int y) {
    x += y;
    if (x >= MOD) {
      x -= MOD;
    }
    return x;
  };
  auto mul = [&](i64 x, int y) -> int {
    return x * y % MOD;
  };
  auto pw = [&](int x, int d) {
    int res = 1;
    while (d) {
      if (d & 1) {
        res = mul(res, x);
      }
      x = mul(x, x);
      d /= 2;
    }
    return res;
  };
  auto inv = [&](int x) {
    return pw(x, MOD - 2);
  };
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int k = inv((int) a[i].size());
    int c = 0;
    for (auto x : a[i]) {
      c = add(c, cnt[x]);
    }
    ans = add(ans, mul(c, k));
  }
  ans = mul(ans, inv(n));
  ans = mul(ans, inv(n));
  cout << ans << '\n';
  return 0;
}