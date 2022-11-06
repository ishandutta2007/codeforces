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

int cst[ms];

void solve() {
   int n, k;
   cin >>  n >> k;
   for(int i = 0; i <= k; i++)  {
      cst[i] = 0;
   }
   int ans = 0;
   for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ans += x/k;
      cst[x%k]++;
   }
   int tot = 0;
   for(int i = 0; i < k - i; i++) {
      tot += cst[k-i];
      int tmp = min(tot, cst[i]);
      ans += tmp;
      tot -= tmp;
   }
   if(k % 2 == 0) tot += cst[k/2];
   ans += tot/2;
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