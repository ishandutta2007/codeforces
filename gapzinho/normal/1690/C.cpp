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

int s[ms], f[ms];

void solve() {
   int n;
   cin >>  n;
   for(int i = 1; i <= n; i++) {
      cin >> s[i];
   }
   for(int i = 1; i <= n; i++) {
      cin >> f[i];
   }
   for(int i = 1; i<= n; i++) {
      int st = max(s[i], f[i-1]);
      cout << f[i] - st << " ";
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