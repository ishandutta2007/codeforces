#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 1e18;
const int ms = 2e5+5; // N-i+qntB[i];
const int mod = 1e9+7;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int arr[ms];

void solve() {
  int n;
  cin >> n;
  ii lo, hi;
  cin >> lo.first >> hi.first >> lo.second;
  hi.second = -lo.second;
  int ans = lo.second;
  cout << ans << '\n';
  for(int i = 1; i < n; i++) {
    int l, r, p;
    cin >> l >> r >> p;
    if (l <= lo.first && r >= hi.first) {
      ans = min(ans, p);
      if(l < lo.first || r > hi.first) ans = p;
      lo = min(lo, {l, p});
      hi = max(hi, {r, -p});
    } else {
      if(l < lo.first || r > hi.first) {
        lo = min(lo, {l, p});
        hi = max(hi, {r, -p});
        ans = lo.second - hi.second;
      } else {
        lo = min(lo, {l, p});
        hi = max(hi, {r, -p});
        ans = min(ans, lo.second - hi.second);
      }
    }
    cout << ans << '\n';
  }
  // cout << "fim" << endl;
}
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // #ifdef ONLINE_JUDGE
  //   freopen("grid.in", "r", stdin);
  //   freopen("grid.out", "w", stdout);
  // #endif
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}