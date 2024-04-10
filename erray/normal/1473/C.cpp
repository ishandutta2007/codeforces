// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> ans(k);
    iota(ans.begin(), ans.end(), 1);
    reverse(ans.end() - (n - k + 1), ans.end());
    for (auto e : ans) {
      cout << e << ' ';
    }
    cout << '\n';
  }
}