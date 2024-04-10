#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int const MAX = 1e5 + 10;
  vector<int> a(MAX);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++a[x];
  }
  vector<int> g(MAX), mu(MAX);
  mu[1] = 1;
  for (int i = 1; i < MAX; ++i) {
    g[i] = a[i];
    for (int j = i * 2; j < MAX; j += i) {
      g[i] += a[j];
      mu[j] -= mu[i];
    }
  }
  int const MOD = (int) 1e9 + 7;
  vector<int> pw(n + 1);
  pw[0] = 1;
  auto mul = [MOD](i64 x, int y) -> int {
    if (x < MOD) {
      x += MOD;
    }
    if (y < MOD) {
      y += MOD;
    }
    return x * y % MOD;
  };
  for (int i = 0; i < n; ++i) {
    pw[i + 1] = mul(pw[i], 2);
  }
  int ans = 0;
  for (int i = 1; i < MAX; ++i) {
    auto k = pw[g[i]] - 1;
    ans += mul(mu[i], k);
    if (ans >= MOD) {
      ans -= MOD;
    }
  }
  cout << ans << '\n';
  return 0;
}