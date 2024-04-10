// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> ans;
  int big = (1 << (int) log2(n));
  for (int bit = 1; bit <= n; bit <<= 1) {
    for (int i = 0; i < n; ++i) {
      if (big - i - 1 < bit) continue;
      if ((i & bit) == 0) {
        ans.emplace_back(i, i + bit);
      }
    }
  }                                  

  for (int bit = 1; bit <= n; bit <<= 1) {
    for (int i = n - 1; i >= 0; --i) {
      if (big - (n - i - 1) - 1 < bit) continue;
      if (((n - i - 1) & bit) == 0) {
        ans.emplace_back(i, i - bit);
      }
    }
  }
  cout << (int) ans.size() << '\n';
  for (auto[x, y]: ans) {
    cout << x + 1 << ' ' << y + 1 << '\n';  
  }
}