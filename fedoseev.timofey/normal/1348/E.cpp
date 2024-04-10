#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
 
using namespace std;
 
typedef long long ll;

int k;

int mod(int x) {
  x %= k;
  if (x < 0) x += k;
  return x;
}

const ll Inf = 1e18;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n >> k;
  vector <int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  vector <ll> dp(k, -Inf);
  dp[0] = 0;
  vector <ll> ndp(k);
  ll sa = 0, sb = 0;
  for (int i = 0; i < n; ++i) {
    fill(ndp.begin(), ndp.end(), -Inf);
    for (int ra = 0; ra < k; ++ra) {
      int kl = mod(sa - ra);
      int rb = mod(sb + kl);
      for (int ta = 0; ta < k; ++ta) {
        if (ta > a[i]) continue;
        ll delta = (b[i] + a[i] - ta) / k;
        if (ta + delta * k < a[i]) continue;
        int tb = (b[i] + a[i] - ta) % k;
        int ga = ta, gb = tb;
        ll val = dp[ra] + delta;
        if (ra + ga >= k) ++val;
        if (rb + gb >= k) ++val;
        ndp[(ra + ga) % k] = max(ndp[(ra + ga) % k], val);
      }
    }
    sa = (sa + a[i] % k) % k;
    sb = (sb + b[i] % k) % k;
    /*for (int i = 0; i < k; ++i) {
      cout << ndp[i] << ' ';
    }
    cout << endl;*/
    swap(dp, ndp);
  }
  ll ans = 0;
  for (int i = 0; i < k; ++i) ans = max(ans, dp[i]);
  cout << ans << '\n';
}