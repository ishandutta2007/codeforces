// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    vector<pair<int, int>> ans;
    long long tot = 0;

    auto add = [&](int x, int y) {
      swap(p[x], p[y]);   
      ans.emplace_back(x, y);
      tot += 1LL * (y - x) * (y - x);
    };

    for (int i = 0; i < n - 1; ++i) {
      add(i, (i > (n - i - 1) ? 0 : n - 1));
    }

    reverse(ans.begin(), ans.end());
    cout << tot << '\n';
    for (auto e : p) {
      cout << e + 1 << ' ';
    }

    cout << '\n' << n - 1 << '\n';
    for (auto[x, y] : ans) {
      cout << x + 1 << ' ' << y + 1 << '\n';
    } 
  }
}