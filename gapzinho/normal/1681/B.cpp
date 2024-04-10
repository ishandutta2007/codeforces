#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 0x3f3f3f3f;
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
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  for(int i = 0; i < m; i++) {
    cin >> b[i];
  }
  int cur = 0;
  for(int i = m-1; i >= 0; i--) {
    int k = n - b[i];
    if(cur < k) {
      cur += b[i];
    } else {
      cur -= k;
    }
  }
  cout << a[cur] << '\n';
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