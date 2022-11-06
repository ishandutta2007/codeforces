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
  int n, d;
  cin >> n >> d;
  vector<int> v(n);
  for(int &x : v) {
    cin >> x;
  }
  sort(v.begin(), v.end());
  int cnt = 0;
  int l = 0;
  for(int r = n-1; r >= l; r--) {
    int pd = d/v[r];
    l += pd;
    if(l <= r) {
      cnt++;
    }
  }
  cout << cnt << '\n';
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