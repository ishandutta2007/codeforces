// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> ans;
  int cur = 1;
  for (int i = 1; i < n; ++i) {
    if (gcd(n, i) == 1) {
      ans.push_back(i);
      cur = (1LL * cur * i) % n;
    }
  }
  assert(count(ans.begin(), ans.end(), cur));
  if (cur != 1) {
    ans.erase(find(ans.begin(), ans.end(), cur));
  }
  cout << int(ans.size()) << '\n';
  for (auto e : ans) {
    cout << e << ' ';
  } 
}