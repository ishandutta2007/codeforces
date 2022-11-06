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

int vis[ms];
int p[ms];

void solve() {
   int n;
   cin >>  n;
   string s;
   cin >> s;
   vector<string> hlp;
   for(int i = 1; i <= n; i++) {
      cin >> p[i];
      vis[i] = 0;
   }
   for(int i = 1; i <= n; i++) {
      if(vis[i]) continue;
      string tmp = "";
      int k = i;
      while(!vis[k]) {
         vis[k] = 1;
         tmp.push_back(s[k-1]);
         k = p[k];
      }
      hlp.emplace_back(tmp);
   }
   int ans = 1;
   for(auto &t : hlp) {
      int tsz = t.size();
      int cyc = -1;
      // cout << t << " -> ";
      for(int k = 1; k <= tsz; k++) {
         string P = t.substr(k) + t.substr(0, k);
         // cout << k << " e " << P << endl;
         if(t == P) {
            cyc = k;
            break;
         }
      }
      assert(cyc != -1);
      // cout << cyc << endl;
      ans = ans * cyc / __gcd(ans, cyc);
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
    solve(); 
  }
  return 0;
}