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
   int n;
   cin >>  n;
   for(int i = 0; i < n; i++) {
      cin >> a[i];
   }
   int minTirar = 0, exatoTirar = -1;
   for(int i = 0; i < n; i++) {
      cin >> b[i];
   }
   for(int i = 0; i < n; i++) {
      if(b[i] == 0) {
         minTirar = max(minTirar, a[i]);
      } else {
         if(b[i] > a[i]) {
            cout << "NO\n";
            return;
         }
         if(exatoTirar == -1) {
            exatoTirar = a[i] - b[i];
         } else {
            if(exatoTirar != a[i] - b[i]) {
               cout << "NO\n";
               return;
            }
         }
      }
   }
   if(exatoTirar == -1 || (exatoTirar >= minTirar)) {
      cout << "YES\n";
   } else {
      cout << "NO\n";
   }
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