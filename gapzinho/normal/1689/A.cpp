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
   int n, m, k;
   cin >> n >> m >> k;
   string a, b;
   cin >> a >> b;
   int lst = 0, cnt = 0;
   sort(a.begin(), a.end());
   reverse(a.begin(), a.end());
   sort(b.begin(), b.end());
   reverse(b.begin(), b.end());
   string c;
   while(!a.empty() && !b.empty()) {
      int go = 0;
      if(cnt == k) {
         go = !lst;
      } else {
         if(*b.rbegin() < *a.rbegin()) {
            go = 1;
         }
      }

      if(go != lst) {
         lst = go;
         cnt = 1;
      } else {
         cnt++;
      }
      if(go) {
         c.push_back(*b.rbegin());
         b.pop_back();
      } else {
         c.push_back(*a.rbegin());
         a.pop_back();
      }
   }
   cout << c << '\n';
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