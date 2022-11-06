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
const int ms = 2e5+5;

int a[ms];

void solve() {
   int n, k;
   cin >> n >> k;
   for(int i = 1; i <= n; i++) {
      cin >> a[i];
      a[i] += a[i-1];
   }
   int ans = 0;
   if(k >= n) {
      ans = a[n]; 
   } else {
      for(int i = 0; i+k <= n; i++) {
         int r = i+k;
         ans = max(ans, a[r] - a[i]);
      }
   }
   if(k <= n) ans += (k)*(k-1)/2;
   else {
      ans += (k-1 + k-n) * n / 2;
   }
   cout << ans << '\n';
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