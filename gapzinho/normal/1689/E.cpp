#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e18;
const int mod = 998244353;
using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int ms = 2005;

int a[ms];
int n;
int bts[32];
int ds[32];
int dsz[32];
int carinha[30];
 
int dsfind(int u) {
   if(u != ds[u]) ds[u] = dsfind(ds[u]);
   return ds[u];
}
 
void unite(int u, int v) {
   u = dsfind(u);
   v = dsfind(v);
   if(u == v) return;
   if(dsz[u] > dsz[v]) swap(u, v);
   ds[u] = v;
   dsz[u] += dsz[v];
}

int get(bool change = false) {
   for(int i = 0; i < 30; i++) {
      bts[i] = 0;
      ds[i] = i;
   }
   for(int i = 0; i < n; i++) {
      int lst = -1;
      for(int j = 0; j < 30; j++) {
         if(!(a[i] & (1 << j))) continue;
         bts[j] = 1;
         carinha[j] = i;
         if(lst != -1) {
            unite(j, lst);
         }
         lst = j;
      }
   }
   int cnt = 0;
   int check = 0;

   for(int i = 0; i < 30; i++) {
      if(bts[i] && ds[i] == i) {
         check++;
      }
   }
   if(check == 1) return 0;
   for(int i = 0; i < 30; i++) {
      if(bts[i] && ds[i] == i && ds[i] != ds[0]) {
         cnt++;
         if(change) {
            a[carinha[i]]++;
         }
      }
   }
   return cnt;
}



void solve() {
   cin >> n;
   int csthlp = 0;
   for(int i = 0; i < n; i++) {
      cin >> a[i];
      if(a[i] == 0) {
         csthlp++;
         a[i]++;
      }
   }
   pair<int, ii> ans = {get(), {-1, -1}};
   // cout << "tmp " << ans << endl;
   for(int i = 0; i < n; i++) {
      // try diminuir ele
      if(a[i] & 1) continue;
      int cst = 1;
      a[i] -= cst;
      ans = min(ans, {get() + cst, {i, cst}});
      a[i] += cst;
   }
   cout << ans.first+csthlp << '\n';
   if(ans.second.first != -1) {
      a[ans.second.first] -= ans.second.second;
   }
   get(true);
   for(int i = 0; i < n; i++) {
      cout << a[i] << " ";
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
//   a[1] = 1;
//   for(int i = 1; i < ms; i++) {
//      for(int j = i*i; j < ms; j++) {
//         if(i == j) continue;
//         a[j] += a[i];
//      }
//   }
//   for(int i = 1; i <= t; i++) {
//      cout << a[i] << endl;
//   }
  while (t--) {
    solve(); 
  }
  return 0;
}