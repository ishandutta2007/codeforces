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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    
    vector<bool> vis(n + 1);
    int big = n;
    vector<int> ans;
    for (int i = n - 1; i >= 0; ) {
      vector<int> add;
      while (vis[big]) {
        --big;
      }

      while (i >= 0 && !vis[big]) {
        vis[a[i]] = true;
        add.push_back(a[i]);
        --i;
      }


      ans.insert(ans.end(), add.rbegin(), add.rend());
    }

    for (auto e : ans) {
      cout << e << ' ';
    }

    cout << '\n';
  }
}