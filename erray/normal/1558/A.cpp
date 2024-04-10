// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b;
    cin >> a >> b;
    int n = a + b;
    vector<int> ans;
    for (int j = 0; j < 2; ++j) {
      int f = (n + j) / 2;
      int s = n - f;
      int mn;
      {
        mn = f - min(f, a) + s - min(s, b); 
      }
      int mx;
      {
        mx = min(f, b) + min(s, a);  
      }
      assert(~(mn ^ mx) & 1); 
      for (int i = mn; i <= mx; i += 2) {
        ans.push_back(i);
      }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << int(ans.size()) << '\n';
    for (auto e : ans) {
      cout << e << ' ';
    }
    cout << '\n';
  }
}