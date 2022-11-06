#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f;
const int ms = 1e6+5;
const int mod = 1e9+7;
using ull = uint64_t;
#define endl '\n'
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;

int a[ms];

void solve() {
  int n, x;
  cin >> n >> x;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(i) ans += abs(a[i] - a[i-1]);
  }
  int lo = a[0], hi = a[0];
  for(int i = 1; i < n; i++) {
    lo = min(a[i], lo);
    hi = max(a[i], hi);
  }
  if(lo > 1) {
    // int h = min(lo-1, x);
    int k = lo - 1 + lo - 1;
    k = min(k, a[0] - 1);
    k = min(k, a[n-1]-1);
    ans += k;
  }
  if(hi < x) {
    // int h = min(lo-1, x);
    int k = x - hi + x - hi;
    k = min(k, x - a[0]);
    k = min(k, x - a[n-1]);
    ans += k;
  }
  cout << ans << endl;
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
    // T++;
    solve(); 
  }
  return 0;
}