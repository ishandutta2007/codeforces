// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    if (n % 2 == 1) {
      cout << -1 << '\n';
      continue;
    }
    vector<int> ans;

    for (int bit = 60; bit > 0; --bit) {
      long long take = (2LL << bit) - 2; 
      while (take <= n) {
        n -= take;
        ans.push_back(1);
        ans.insert(ans.end(), bit - 1, 0);    
      }
    }
    assert(n == 0);
    cout << (int) ans.size() << '\n';
    for (auto el : ans) {
      cout << el << ' ';
    }
    cout << '\n';
  }
}