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

int a[ms], b[ms];

void solve() {
   int n, m;
   cin >>  n >> m;
   set<pair<ii, int>> trains; // {r, l, velocidade}
   for(int i = 0; i < n; i++) {
      cin >> a[i];
      if(i == 0) trains.emplace(ii(1, 0), a[i]);
      else {
         auto v = *trains.rbegin();
         if(v.second <= a[i]) {
            trains.erase(v);
            v.first.first++;
            trains.emplace(v);
         } else {
            trains.emplace(ii(i+1, i), a[i]);
         }
      }
   }
   // cout << trains.size() << endl;
   for(int i = 0; i < m; i++) {
      int k, d;
      cin >> k >> d;
      k--;
      a[k] -= d;
      auto v = *trains.upper_bound({ii(k, inf), inf});
      if(a[k] >= v.second) {
         cout << trains.size() << " ";
         continue;  
      }
      // cout << endl << v.first.first << " " << v.first.second << " " << v.second << endl;
      trains.erase(v);
      if(v.first.second != k) {
         auto p = v;
         p.first.first = k;
         trains.insert(p);
         v.first.second = k;
      }
      // cout << trains.size() << " hlp " << endl;
      v.second = a[k];
      auto it = trains.upper_bound({ii(k, inf), inf});
      while(it != trains.end() && it->second >= v.second) {
         v.first.first = (it->first).first;
         trains.erase(it);
         it = trains.upper_bound({ii(k, inf), inf});
      }
      trains.insert(v);
      cout << trains.size()<< ' ';
   }
   cout << endl;
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