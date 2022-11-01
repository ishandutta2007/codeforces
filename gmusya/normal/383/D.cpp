#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

const int W = 10'000;
const ll MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector <ll> dp(2 * W + 1);
  dp[W] = 1;
  ll ans = 0;
  for (int w : a) {
    vector <ll> newdp(2 * W + 1);
    for (int oldw = 0; oldw <= 2 * W; oldw++) {
      if (oldw - w >= 0) {
        newdp[oldw - w] += dp[oldw];
        if (newdp[oldw - w] >= MOD)
          newdp[oldw - w] -= MOD;
      }
      if (oldw + w <= 2 * W) {
        newdp[oldw + w] += dp[oldw];
        if (newdp[oldw + w] >= MOD)
          newdp[oldw + w] -= MOD;
      }
    }
    ans += newdp[W];
    newdp[W]++;
    swap(dp, newdp);
  }
  cout << ans % MOD;
  return 0;
}