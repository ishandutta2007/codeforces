#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e18;
const int mod = 1e9+7;
using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int ms = 1e6+5;

int v[ms];
int ans[ms];

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }
  if(n % 2) {
    cout << "NO" << '\n';
    return;
  }
  sort(v, v+n);
  for(int i = 0; i < n/2; i++) {
    ans[i*2+1] = v[i];
    ans[i*2+2] = v[i+n/2];
  }
  ans[0] = ans[n];
  ans[n+1] = ans[0];
  for(int i = 1; i <= n; i++) {
    if(ans[i] == ans[i-1]) {
      cout << "NO" << '\n';
      return;
    }
  }
  cout << "YES\n";
  for(int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
   #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
  cin >> t;
  while (t--) {
    solve(); 
  }
  return 0;
}