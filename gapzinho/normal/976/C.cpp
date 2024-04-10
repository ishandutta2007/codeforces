#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int ms = 3e5+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pair<ii, int> v[ms];

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i< n; i++) {
    cin >> v[i].first.first >> v[i].first.second;
    v[i].first.second *= -1;
    v[i].second = i+1;
  }
  pair<int, int> cur = {-1, -1};
  sort(v, v+n);
  for(int i = 0; i < n; i++) {
    auto [l, r] = v[i].first;
    r = -r;
    // cout << r << " " << cur.first << endl;
    if(r  <= cur.first) {
      cout << v[i].second << " " << cur.second << endl;
      return;
    }
    cur = max(cur, {r, v[i].second});
  }
  cout << -1 << " " << -1 << endl;
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