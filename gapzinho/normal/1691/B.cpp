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
   int n;
   cin >> n;
   for(int i = 1; i <= n; i++) {
      cin >> a[i];
      pos[i] = i;
   }
   if(n == 1) {
      cout << "-1" << '\n';
      return;
   }
   int st = 1;
   for(int i = 2; i <= n; i++) {
      if(a[i] != a[st]) {
         int l = st, r = i-1;
         if(r-l <= 0) {
            cout << "-1" << '\n';
            return;
         }
         for(int k = l; k < r; k++) {
            pos[k] = k+1;
         }
         pos[r] = l;
         st = i;
      }
   }
   int l = st, r = n;
         if(r-l <= 0) {
            cout << "-1" << '\n';
            return;
         }
         for(int k = l; k < r; k++) {
            pos[k] = k+1;
         }
         pos[r] = l;
         for(int i = 1; i <= n; i++) {
            cout << pos[i] << " ";
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