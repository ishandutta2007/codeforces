#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int ms = 2e5+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int s[ms];

void solve() {
  int n, k;
  cin >> n >> k;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
    ans = s[i];
  }
  int needPairs = max(0ll, n - k);
  // cout << needPairs << endl;
  for(int i = 0; i < needPairs; i++) {
    ans = max(ans, s[i] + s[2*needPairs-i-1]);
  }
  cout << ans << endl;
}
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
      solve();
  }
  return 0;
}