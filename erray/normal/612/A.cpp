// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, p, q;
  cin >> n >> p >> q;
  string s;
  cin >> s;
  int ans = -1;
  for (int i = 0; i * q <= n; ++i) {
    int left = n - (i * q);
    if (left % p == 0) {
      ans = i;
    }
  }

  if (ans == -1) {
    return cout << -1, 0;
  }
  //cerr << ans << '\n';

  vector<string> res;
  for (int i = 0; i < ans; ++i) {
    string add;
    for (int j = 0; j < q; ++j) {
      add += s.back();
      s.pop_back();  
    }
    reverse(add.begin(), add.end());
    res.push_back(add);
  }

  string add;
  while (!s.empty()) {
    add += s.back();
    s.pop_back();
    if ((int) add.size() == p) {
      reverse(add.begin(), add.end());
      res.push_back(add);
      add.clear();
    }
  }

  reverse(res.begin(), res.end());
  cout << (int) res.size() << '\n';
  for (auto e : res) {
    cout << e << '\n';
  }
}