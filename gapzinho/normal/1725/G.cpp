#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
using ull = uint64_t;
using ii = pair<int, int>;
using iii = pair<ii, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
using ld =  long double;
const int inf = 1e18+2;
 
const int ms = 3005;
const int mod = 1e9+7;

void solve() {
  int n;
  cin >> n;
  int l = 1, r = inf;
  while(l < r) {
    int m = (l+r)/2;
    int cnt = (m-1)/2 + (m-4)/4;
    // cout << m << " - " << cnt << endl;
    if(cnt < n) l = m+1;
    else r = m;
  }
  cout << l << endl;
}
 
 
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int T = 1; T <= t; T++) {
    // cout << "Case #" << T << ": ";
    solve(); 
  }
  return 0;
}