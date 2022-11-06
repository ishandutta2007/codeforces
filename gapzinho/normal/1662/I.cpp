#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

using ii = pair<int, int>;
const int inf =  1e9;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> v(m+2);
  v[0] = -inf;
  vector<int> per(n);
  for(int i = 0; i < n; i++) {
    cin >> per[i];
  }
  for(int i = 1; i <= m; i++){
    cin >> v[i];
  }
  v[m+1] = inf;
  sort(v.begin(), v.end());
  vector<ii> evs;
  for(int i = 0; i < n; i++) {
    int k = i * 100;
    int p = upper_bound(v.begin(),v.end(), k) - v.begin() - 1;
    int l1 = v[p];
    int r1 = k + k - v[p];
    int l2 = k + k - v[p+1];
    int r2 = v[p+1]; 
    int l = max(l1, l2);
    int r = min(r1, r2);
    if(r > l) {
      evs.emplace_back(l, per[i]);
      evs.emplace_back(r, -per[i]);
    }
  }
  sort(evs.begin(), evs.end());
  int ans = 0, cur = 0;
  for(auto [p, x] : evs) {
    cur += x;
    ans = max(cur, ans);
  }
  cout << ans << endl;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int t = 1;
  // cin >> t;
  while(t--) {
      solve();
  }
}