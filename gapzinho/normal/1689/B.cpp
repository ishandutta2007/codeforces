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
const int ms = 105;

int p[ms];

void solve() {
   int n;
   cin >> n;
   for(int i = 1; i <= n; i++) {
      cin >> p[i];
   }
   if(n == 1) {
      cout << -1 << '\n';
      return;
   }
   for(int i = 1; i <= n; i++) {
      if(p[i] == i) {
         if(i != n) {
            p[i] = i+1;
            i++;
            p[i] = i-1;
         } else {
            swap(p[i], p[i-1]);
         }
      } else {
         p[i] = i;
      }
   }
   for(int i = 1; i <= n; i++) {
      cout << p[i] << " ";
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