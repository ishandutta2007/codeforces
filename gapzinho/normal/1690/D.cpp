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

int pre[ms];

void solve() {
   int n, k;
   cin >>  n >> k;
   string s;
   cin >> s;
   for(int i = 1; i <= n; i++) {
      pre[i] = pre[i-1];
      if(s[i-1] == 'W') pre[i]++;
   }
   int ans = pre[n];
   for(int i = 0; i+k <= n; i++) {
      ans = min(ans, pre[i+k] - pre[i]);
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