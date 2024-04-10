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
  vector<int> v(n);
  int cnt0 = 0, cntrest = 0;
  for(int &x : v) {
    cin >> x;
    if(x % 3) x = 1;
    else x = 0;
    if(x == 0) cnt0++;
    else cntrest++;
    if(x == 0 && cnt0 > n/2) {
      x = 1;
    } else if(x == 1 && cntrest > n/2) {
      x = 0;
    }
  }
  if(cnt0 <= n/2) {
    cout << 0 << '\n'; // lado 1: 0 1 - lado 2: 1
  } else {
    cout << 2 << '\n'; // lado 1: 0 - lado 2: 0 1
  }
  for(int x : v){ 
    cout << x;
  }
  cout << '\n';
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