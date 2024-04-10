#include <bits/stdc++.h>
using namespace std;

main() {
  int n;
  cin >> n;
  int x;
  cin >> x;
  int total = x;
  int coali = x;
  vector<int> ans = {1};
  for(int i = 2; i <= n; i++) {
    int y;
    cin >> y;
    total += y;
    if(x >= y + y) {
      ans.push_back(i);
      coali += y;
    }
  }
  if(coali + coali <= total) {
    ans.clear();
  }
  cout << ans.size() << '\n';
  for(int k : ans) cout << k << ' ';
  cout << '\n';
}