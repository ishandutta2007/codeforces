// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    if (k > (n - 1) / 2) {
      cout << -1 << '\n';
      continue;
    }  
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);
    for (int i = 1; k > 0; i += 2, --k) {
      swap(ans[i], ans[i + 1]);
    }
    for (auto e : ans) {
      cout << e << ' ';
    }
    cout << '\n';
  }
}