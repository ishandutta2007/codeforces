#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
using ull = uint64_t;
using ii = pair<int, int>;
using iii = pair<int, ii>;
// using i4 = tuple<int, int, int, int>;
using i4 = pair<ii, ii>;
using ll = long long;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int ms = 2e5+5;

vector<int> v;

int sqr(int l) {
  int lo = 0, hi = 1e9+5;
  while(lo < hi) {
    int mi = (lo+hi+1)/2;
    if(mi*mi <= l) {
      lo = mi;
    } else {
      hi = mi-1;
    }
  }
  int cnt = lo*3-2;
  if(lo*(lo+1) <= l) cnt++;
  if(lo*(lo+2) <= l) cnt++;;
  return cnt;
}


void solve() {
  int l, r;
  cin >> l >> r;
  l--;
  int x1 = sqr(l), x2 = sqr(r);
  // x1 += cnt(l); x2 += cnt(r);
  cout << x2 - x1 << '\n';
}
 
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for(int i = 1; i <= 500; i++) {
    
  }
  for(int T = 1; T <= t; T++) {
    // cout << "Case #" << T << ": ";
    solve(); 
  }
  return 0;
}