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
const int ms = 1005;

string s[ms];
int dt[ms][ms];
int db[ms][ms];
int dl[ms][ms];
int dr[ms][ms];

void solve() {
   int n, m;
   cin >> n >> m;
   for(int i = 0; i < n; i++) {
      cin >> s[i];
   }
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
         dt[i][j] = s[i][j] == 'B' ? 0 : -1;
         if(j && dt[i][j-1] != -1) dt[i][j] = dt[i][j-1] + 1;
      }
      for(int j = m-1; j >= 0; j--) {
         db[i][j] = s[i][j] == 'B' ? 0 : -1;
         if(j!=m-1 && db[i][j+1] != -1) db[i][j] = db[i][j+1] + 1;
      }
   } // tenho distancia pro top e pro bot , resposta da linha = max(db, dt)
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
         dl[i][j] = max(db[i][j], dt[i][j]);
         if(i && dl[i-1][j] != -1) dl[i][j] = max(dl[i][j], dl[i-1][j] + 1);
      }
   }
   for(int i = n-1; i >= 0; i--) {
      for(int j = 0; j < m; j++) {
         dr[i][j] = max(db[i][j], dt[i][j]);
         if(i!=n-1 && dr[i+1][j] != -1) dr[i][j] = max(dr[i][j], dr[i+1][j] + 1);
      }
   }
   pair<int, ii> ans = {inf, {0, 0}};
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
         if(s[i][j] )
         ans = min(ans, {max(dr[i][j], dl[i][j]), {i, j}});
      }
   }
   // cout << dl[0][0] << endl;
   // cout << d
   // cout << ans.first << "-> ";
   cout << ans.second.first+1  << " " << ans.second.second+1 << '\n';
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