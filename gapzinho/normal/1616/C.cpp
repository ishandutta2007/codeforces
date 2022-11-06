#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int ms = 205; // N-i+qntB[i];
const int mod = 1e9+7;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[ms];
ii hlp[ms];
int qntA[ms], qntB[ms];

ii norm(ii x) {
  int gc = __gcd(x.first, x.second);
  x.first /= gc;
  x.second /= gc;
  return x;
}

ii magic(ii a, ii b) {
  return norm({2*a.first*b.second - b.first*a.second, a.second*b.second});
}

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if(n <= 2) {
    cout << 0 << '\n';
    return;
  }
  int ans = inf;
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      // cout << n << " ";
      // cout << i << " " << j  << endl;
      int tmp = 0;
      hlp[i] = {a[i], 1};
      hlp[i+1] = norm({(a[j] - qntA[j-i]*a[i]), qntB[j-i]});
      for(int k = i+2; k < n; k++) {
        // mdc = hlp[k-1].second
        hlp[k] = magic(hlp[k-1], hlp[k-2]);
      }
      for(int k = i-1; k >= 0; k--) {
        hlp[k] = magic(hlp[k+1], hlp[k+2]);
      }
      for(int k = 0; k < n; k++) {
        // cout << hlp[k].first << " " << hlp[k].second << endl;
        if(hlp[k].second != 1 || hlp[k].first != a[k]) tmp++;
      }
      ans = min(tmp, ans);
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
  qntA[0] = 1;
  qntB[1] = 1;
  for(int i = 2; i <= 70; i++) {
    qntA[i] = 2*qntA[i-1] - qntA[i-2];
    qntB[i] = 2*qntB[i-1] - qntB[i-2];
  }
  while (t--) {
    solve();
  }
  return 0;
}