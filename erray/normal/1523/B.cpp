// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    
    vector<array<int, 3>> ans;
    auto Do = [&](int me, int ot) {
      auto Add = [&](int x) {
        ans.push_back({x, me, ot});
      };
      Add(1);
      Add(2);
      Add(1);
    };
    
    for (int i = 0; i < n; i += 2) {
      Do(i, i + 1);
      Do(i, i + 1);
    }

    cout << int(ans.size()) << '\n';
    for (auto e : ans) {
      cout << e[0] << ' ' << e[1] + 1 << ' ' << e[2] + 1 << '\n';
    }
  }
}