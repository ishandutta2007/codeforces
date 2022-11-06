#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long

using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int ms = 1505;

int a[ms][ms];
int x[ms][ms], y[ms][ms];
 
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> a[i][j];
      x[i][j] = a[i][j];
      y[j][i] = a[i][j];
    }
  }
  for(int i = 0; i < n; i++) {
    sort(x[i], x[i]+n);
    sort(y[i], y[i]+n);
  }
  int ans = 2 * (n * (n-1))/2 * (n * (n-1))/2;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int k1 = lower_bound(x[i], x[i]+n, a[i][j]) - x[i];
      int k2 = lower_bound(y[j], y[j]+n, a[i][j]) - y[j];
      // cout << i << " " << j << " = " << k1 << " e " << k2 << endl;;
      ans -= k1*k2;
    }
  }
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(3);
   #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
  // cin >> t;
  while (t--) {
    solve(); 
  }
  return 0;
}