#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, MOD;
  cin >> n >> MOD;

  auto add = [&](int& x, int y) {
    x += y;
    if (x >= MOD) {
      x -= MOD;
    }
  };
  auto prod = [&](i64 x, int y) {
    return (int) (x * y % MOD);
  };
  vector<int> fact(n + 2);
  fact[0] = 1;
  for (int i = 0; i + 1 < (int) fact.size(); ++i) {
    fact[i + 1] = prod(fact[i], i + 1);
  }
  int ans = 0;
  for (int len = 1; len <= n; ++len) {
    add(ans, prod(fact[len], prod(n - len + 1, fact[n - len + 1])));
  }
  cout << ans << '\n';
  return 0;
}