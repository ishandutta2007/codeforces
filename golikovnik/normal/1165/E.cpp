#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::string;
using std::vector;

using ll = int64_t;

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int& x : a) {
    cin >> x;
  }
  for (int& x : b) {
    cin >> x;
  }
  vector<ll> new_a(n);
  for (int i = 0; i < n; i++) {
    new_a[i] = 1ll * a[i] * (i + 1) * (n - i);
  }
  std::sort(new_a.begin(), new_a.end());
  std::sort(b.rbegin(), b.rend());
  int const MOD = 998244353;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    new_a[i] %= MOD;
    ans += static_cast<int>(new_a[i] * b[i] % MOD);
    if (ans >= MOD) {
      ans -= MOD;
    }
  }
  cout << ans << "\n";
  return 0;
}