#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 1e18;
const int ms = 600;
const int mod = 1e9+7;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[ms][ms];
int cst[ms][ms];

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < 2*n; i++) {
    for(int j = 0; j < 2*n; j++) {
      cin >> a[i][j];
    }
  }
  int ans = inf;
  vector<ii> v = {{0, n}, {0, 2*n-1}, {n-1, n}, {n-1, 2*n-1}};
  for(auto k : v) {
    ans = min(ans, a[k.first][k.second]);
    ans = min(ans, a[k.second][k.first]);
  }
  for(int i = n; i < 2*n; i++) {
    for(int j = n; j < 2*n; j++) {
      ans += a[i][j];
    }
  }
  cout << ans << '\n';
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