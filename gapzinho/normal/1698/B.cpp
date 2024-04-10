#include <bits/stdc++.h>
using namespace std;

#define int long long

using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const int ms = 1e6+5;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if(k == 1) {
    cout << (n-1)/2 << '\n';
  } else {
    int ans = 0;
    for(int i = 1; i < n-1; i++) {
      if(a[i] > a[i-1] + a[i+1]) {
        ans++;
      }
    }
    cout << ans << '\n';
  }
  return;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(3);
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