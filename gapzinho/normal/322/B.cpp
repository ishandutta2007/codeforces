#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int ms = 2e5+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int s[ms];
int t[ms], l[ms], r[ms];

int brute(int r, int g, int b) {
  int ans = 0;
  if(r >= 3) ans = max(ans,1+ brute(r-3, g, b));
  if(g >= 3) ans = max(ans,1+ brute(r, g-3, b));
  if(b >= 3) ans =max(ans, 1+brute(r, g, b-3));
  if(r && g && b) ans = max(ans, 1+brute(r-1, g-1, b-1));
  return ans;
}

void solve() {
  int r, g, b;
  cin >> r >> g >> b;
  int mix = min(r, min(g, b));
  int cur = (r- mix)/3 + (g-mix)/3 + (b-mix)/3;
  r -= 3*((r-mix)/3);
  g -= 3*((g-mix) / 3);
  b -= 3 *((b-mix) / 3);
  int k = max(0ll, mix-2);
  r -= k;
  g -= k;
  b -= k;
  cur += k;
  // cout << cur << " " << r << " " <<  g << " " << b<< endl;
  cout << brute(r, g, b) + cur << endl;
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