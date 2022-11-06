#include <bits/stdc++.h>
using namespace std;

#define int long long

using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const int ms = 1e6+5;

void solve() {
  int n;
  cin >> n;
  int l = 1, r = n;
  while(l < r) {
    int mi = (l+r)/2;
    cout << "? " << l << " " << mi << endl;
    int tot = 0;
    for(int i = l; i <= mi; i++) {
      int x;
      cin >> x;
      if(x >= l && x  <= mi) tot++;
    }
    if(tot % 2) {
      r = mi;
    } else {
      l = mi+1;
    }
  }
  cout << "! " << l << endl;
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
  cin >> t;
  while (t--) {
    solve(); 
  }
  return 0;
}