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

set<int> groups;
int ds[ms];
int qnt[ms];

int find(int u) {
   if(u != ds[u]) {
      ds[u] = find(ds[u]);
   }
   return ds[u];
}

void unite(int u, int v) {
   u = find(u); v = find(v);
   ds[u] = v;
   if(u != v) {
      groups.erase(u);
      qnt[v] += qnt[u];
   }
}

int c[ms];

void solve() {
   int n;
   cin >> n;
   for(int i = 1; i <= n; i++) {
      ds[i] = i;
      qnt[i] = 0;
   }
   vector<ii> ev;
   for(int i = 1; i <= n; i++) {
      int l, r;
      cin >> c[i] >> l >> r;
      ev.emplace_back(l, -i);
      ev.emplace_back(r, i);
   }
   sort(ev.begin(), ev.end());
   int tot[2] = {0, 0};
   for(auto [fods, idx] : ev) {
      if(idx < 0) {
         idx = -idx;
         if(qnt[idx]++ == 0) {
            groups.insert(idx);
         }
         tot[c[idx]]++;
         if(tot[0] && tot[1]) {
            vector<int> grps;
            for(int k : groups) grps.emplace_back(k);
            for(int i = 1; i < grps.size(); i++) {
               // cout << fods << endl;
               // cout << "unir grupos " << grps[0] << " e  "  << grps[i] << endl;
               unite(grps[0], grps[i]);
            }
         }
      } else {
         if(--qnt[find(idx)] == 0) {
            groups.erase(find(idx));
         }
         tot[c[idx]]--;
      }
   }
   int ans = 0;
   for(int i = 1; i <= n; i++) {
      // cout << i << " " << ds[i] << endl;
      ans += (ds[i] == i);
   }
   cout  << ans << '\n';
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