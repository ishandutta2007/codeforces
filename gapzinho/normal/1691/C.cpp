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
#define x first
#define y second

int a[ms];
int pos[ms];

void solve() {
   int n, k;
   cin >> n >> k;
   string s;
   cin >> s;
   vector<int> pos;
   for(int i = 0; i < n; i++) {
      if(s[i] == '1') pos.emplace_back(i);
   }
   int ans = pos.size() * 11;
   if(pos.size() > 0) {
      int x = pos.size();
      if(n-1 - pos[x-1] <= k) {
         k -= n-1 - pos[x-1];
         ans -= 10;
         pos[x-1] = n -1;
      }
      if(pos[0] !=  n-1 && pos[0] <= k) {
         k -= pos[0];
         ans--;
      }
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