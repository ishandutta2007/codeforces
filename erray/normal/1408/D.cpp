// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(n), b(m);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }

  for (int i = 0; i < m; ++i) {
    cin >> b[i].first >> b[i].second;
  }

  const int X = (int) 1e6 + 3;
  vector<int> cs(X); 
  for (auto x : a) {
    for (auto y : b) {
      auto need = make_pair(max(0, y.first - x.first + 1), max(0, y.second - x.second + 1));
      cs[need.first] = max(cs[need.first], need.second);    
    }
  }

  vector<int> mx(X);
  for (int i = X - 1; i >= 0; --i) {
    mx[i] = max(cs[i], mx[i + (i != X - 1)]);
  }
  int ans = mx[0];
  for (int i = 0; i <  X - 1; ++i) {
    ans = min(ans, i + mx[i + 1]);                    
  }
  cout << ans << '\n';
}